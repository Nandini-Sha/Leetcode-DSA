class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> results;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            indegree[prerequisites[i][1]]++;
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int i = q.front();
            results.push_back(i);
            q.pop();
            for(auto n:adj[i]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
        }
        reverse(results.begin(),results.end());

        return (results.size()==numCourses)?results:vector<int>{};
    }
};