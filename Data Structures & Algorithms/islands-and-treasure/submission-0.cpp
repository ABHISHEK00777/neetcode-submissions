class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        // Step 1: Push all treasure cells
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        // Step 2: Multi-source BFS
        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();

            for(auto [dr,dc] : dir){

                int nr = r + dr;
                int nc = c + dc;

                if(nr<0 || nr>=rows ||
                   nc<0 || nc>=cols)
                    continue;

                if(grid[nr][nc] != INT_MAX)
                    continue;

                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr,nc});
            }
        }
    }
};