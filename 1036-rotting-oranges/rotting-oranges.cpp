class Solution {
public:
       
    queue<pair<int,int>> rottens;
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2) rottens.push({i,j});
            }
        }
        while(!rottens.empty()){
            int size = rottens.size();
            while(size>0){
                pair<int,int> p = rottens.front();
                rottens.pop();
                rotting(grid,p.first,p.second);                
                size--;
            } 
            time++;
        }
         for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return (time>0)?time-1:0;
    }
    void rotting(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i+1<m && grid[i+1][j] == 1){
            grid[i+1][j] = 2;
            rottens.push({i+1,j});
        }
        if(j+1<n && grid[i][j+1] == 1){
            grid[i][j+1] = 2;
            rottens.push({i,j+1});
        }
        if(i-1>=0 && grid[i-1][j] == 1){
            grid[i-1][j] = 2;
            rottens.push({i-1,j});
        }
        if(j-1>=0 && grid[i][j-1] == 1){
            grid[i][j-1] = 2;
            rottens.push({i,j-1});
        }
    }
};