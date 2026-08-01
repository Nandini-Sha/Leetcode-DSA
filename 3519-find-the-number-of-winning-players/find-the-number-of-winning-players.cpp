class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> mp(n,vector<int>(11,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<pick.size();j++){
                if(pick[j][0] == i){
                    mp[i][pick[j][1]]++;
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<11;j++){
                if(mp[i][j]>i){
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};