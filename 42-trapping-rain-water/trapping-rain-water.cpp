class Solution {
public:
    int trap(vector<int>& height) {
        long long V = 0;
        int n = height.size();
        int maxleft = height[0];
        int maxright = height[n-1];
        vector<vector<int>> walls(n, vector<int>(2));

        for(int i = 0;i<height.size();i++){
            walls[i][0] = maxleft;
            maxleft = max(maxleft,height[i]);
        }

        for(int j = n-1;j>=0;j--){
            walls[j][1] = maxright;
            maxright = max(maxright,height[j]);
        }

        for(int i = 0;i<n;i++){
            if(height[i]<walls[i][0] && height[i]<walls[i][1]){
                V+=(min(walls[i][0],walls[i][1])-height[i]);
            }
        }

        
        return V;
    }
};
