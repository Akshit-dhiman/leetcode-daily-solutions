class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board){
        int r = row, c=col;

        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }
        while(r>=0 && c>=0){
            if(board[r--][c--] == 'Q') return false;
        }
        r=row, c=col;

        while(r>=0 && c<n){
            if(board[r--][c++] == 'Q') return false;
        }
        return true;
    }
    void solver(int row, int n, vector<string>& board, int &ans){
        if(row == n){
            ans++;
        }
        for(int col = 0; col<n; col++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solver(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;

        string s(n,'.');
        vector<string> board(n, s);

        solver(0, n, board, ans);
        return ans;
    }
};