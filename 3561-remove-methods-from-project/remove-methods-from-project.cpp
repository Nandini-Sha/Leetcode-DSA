class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& sus) {
        sus[node] = true;

        for (int nxt : adj[node]) {
            if (!sus[nxt]) {
                dfs(nxt, adj, sus);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Find suspicious methods
        vector<bool> sus(n, false);
        dfs(k, adj, sus);

        // Check if removal possible
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!sus[u] && sus[v]) {
                vector<int> all;
                for (int i = 0; i < n; i++)
                    all.push_back(i);
                return all;
            }
        }

        // Return remaining methods
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};