class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> cur(n,0);
        vector<int> prev(n,1);
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(obstacleGrid[i][j] == 1) cur[j] = 0;
                else if(i==0 && j== 0) cur[j] = 1; 
                else{
                    if(i>0) cur[j] = prev[j];
                    if(j>0) cur[j]+= cur[j-1];
                }
                prev = cur;
            }
        }
        
        return cur[n-1];
    }
};