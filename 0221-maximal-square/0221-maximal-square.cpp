class Solution {
public:
    int m, n;
    int dp(int i, int j, int &maxi, vector<vector<char>>& matrix, vector<vector<int>>&memo ){
        if(i>=m || j>=n) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        int right = dp(i, j+1, maxi, matrix, memo);
        int diagonal = dp(i+1, j+1, maxi, matrix, memo);
        int down = dp(i+1, j, maxi, matrix, memo);

        if(matrix[i][j] == '1'){
            memo[i][j] = 1+min({right, diagonal, down});
            maxi = max(maxi, memo[i][j]);
            return memo[i][j];
        }
        return memo[i][j] = 0;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        m=matrix.size();
        n = matrix[0].size();
        int maxi = 0;
        vector<vector<int>> memo(m,vector<int>(n,-1));

        dp(0,0,maxi, matrix, memo);
        return maxi*maxi;
    }
};