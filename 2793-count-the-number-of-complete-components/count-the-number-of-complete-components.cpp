class Solution {
public:
    unordered_map <int,unordered_set<int>> mp;
    unordered_map<int,bool> visited;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for(int i = 0;i<n;i++){
            mp[i].insert(i);
            visited[i] = false;
        }
        for(int i = 0;i<m;i++){
            mp[edges[i][0]].insert(edges[i][1]);
            mp[edges[i][1]].insert(edges[i][0]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(visited[i]==false){
                ans+=dfs(i,mp[i]);
            }
        }

        return ans;
    }

    int dfs(int i, unordered_set<int>& s){
        if(visited[i]) return 1;

        visited[i] = true;

        int ok = (s == mp[i]);   // current node valid?

        for(auto j : mp[i]){
            if(!visited[j]){
                if(dfs(j, s) == 0)
                    ok = 0;
            }
        }

        return ok;
    }
};