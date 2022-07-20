class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        bool present=false;
        while(i<m)
        {
            if(target<matrix[i][n-1])
                break;
            i++;
        }
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==target)
                present=true;
        }
        return present;
    }
};