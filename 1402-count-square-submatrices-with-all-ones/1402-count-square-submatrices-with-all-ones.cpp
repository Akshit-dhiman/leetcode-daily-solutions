class Solution {
public:
    int m, n, total;
    vector<vector<int>> memo;
    vector<vector<int>> *mat;

    int dp(int i, int j){
        if(i>=m || j>=n ) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        int right = dp(i,j+1);
        int diagonal = dp(i+1, j+1);
        int down = dp(i+1,j);

        if((*mat)[i][j] == 1){
            memo[i][j] = 1+min({right, diagonal, down});
            total += memo[i][j];
            return memo[i][j];
        }
        return memo[i][j] = 0;
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        total = 0;
        memo.assign(m,vector<int>(n,-1));
        mat = &matrix;

        dp(0,0);

        return total;
    }
};