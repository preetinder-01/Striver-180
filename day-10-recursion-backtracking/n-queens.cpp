class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board, int n)
    {
        // now we need to check for 8 cordinates 4: up,right,bottom,left     4: diagonally
        // firstly check diagonally up
        int duprow=row;
        int dupcol=col;
        // checking upper left diagonla to prevent attack
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
            
        }
        row=duprow;
        col=dupcol;
        //checking whether element present  in same column in any other row 
        while(col>=0)
        {
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=duprow;
        col=dupcol;
        // checking lower left digonal 
        while(row<n and col>=0)
        {
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        
        // didn't checked for right diagnal as we are filling elements recursively and from left to right ( and backtracking _)
        return true ;
        
    }
    
    void solve(int ind,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(ind==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,ind,board,n))
            {
                board[row][ind]='Q';
                solve(ind+1,board,ans,n);
                board[row][ind]='.';    // to remove the queen placed for backtracking 
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>board(n); // vector of strings where each string will act as a row 
        string s(n,'.');    // craeted the string of size n i.e. rows for matrix
        for(int i=0;i<n;i++)
        {
            board[i]=s; // craeted 2d matrix of '.'s
        }
        solve(0,board,ans,n);   // 0 for column index 
        return ans;
    }
};