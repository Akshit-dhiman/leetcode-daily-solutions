class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> &board){
    
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }
        int dupcol = col;
        int duprow = row;
        while(duprow>=0 && dupcol>=0){
            if(board[duprow][dupcol] == 'Q')return false;
            duprow--;
            dupcol--;
        }
        dupcol = col;
        duprow = row;

        while(duprow>=0 && dupcol<n){
            if(board[duprow][dupcol] == 'Q')return false;
            duprow--;
            dupcol++;
        }
        return true;

    }
    void solver(int row, int n, vector<string>&board, vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(isSafe(row, col, n, board)){
                board[row][col] = 'Q';
                solver(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> board(n, s);

        solver(0, n, board, ans);
        return ans;

    }
};