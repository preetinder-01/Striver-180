class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
     
        solve(board);
    }
    
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1'; c<='9'; c++)
                    {
                        if(isValid(board,i,j,c))
                        {
                            board[i][j]=c;
                        
                        
                        if(solve(board))
                            return true;    // if we get the solution will return from here only 
                        else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }   // if now able to find the correct elem for that position return false 
                // return false;
            }
        }
        return true;
    }
    
    
    
    
    
    bool isValid(vector<vector<char>>& board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)return false;
            if(board[row][i]==c)return false;
            // to get box we use formula (row/3)*3 +(col/3)
            // so for row we used  i/3 and for col we used i%3 as addition to iterate in row at same time 
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
            
        }
        return true;
    }
    
    
    
    
};