class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> que;

        for(int i = 0; i < k; i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            que.push({dis, {points[i][0], points[i][1]}});
        }

        for(int i = k; i < points.size(); i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];

            if(dis < que.top().first){
                que.pop();
                que.push({dis, {points[i][0], points[i][1]}});
            }
        }

        vector<vector<int>> ans;
        while(!que.empty()){
            auto top = que.top();
            que.pop();
            ans.push_back({top.second.first, top.second.second});
        }

        return ans;
    }
};