class Solution {
public:
    int m,n;
    int emptycells = 0;
    int result = 0;

    void dfs(int x, int y, int remaining, vector<vector<int>>& grid){
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y] == -1) return;

        if(grid[x][y] == 2){
            if(remaining == 0){
                result++;
            }return;
        }
        int temp = grid[x][y];
        grid[x][y] = -1;

        dfs(x+1, y, remaining-1, grid);
        dfs(x-1, y, remaining-1, grid);
        dfs(x, y+1, remaining-1, grid);
        dfs(x, y-1, remaining-1, grid);

        grid[x][y] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int startx = 0, starty=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    emptycells++;
                }else if(grid[i][j] == 1){
                    startx = i;
                    starty = j;
                }
            }
        }
        dfs(startx, starty, emptycells+1, grid);
        return result;
    }
};