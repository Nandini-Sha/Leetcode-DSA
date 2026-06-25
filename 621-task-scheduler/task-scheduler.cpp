class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> a(26,0);
        for(auto task : tasks){
            a[task-'A']++;
        }
        priority_queue<int> que;
        for(auto f:a){
            if(f>0){
                que.push(f);
            }
        }
        int t = 0;
        queue<pair<int,int>> q;
        while(!que.empty() || !q.empty()){
            if(!q.empty() && q.front().second == t){
                que.push(q.front().first);
                q.pop();
            }
            if(!que.empty()){
                int p = que.top();
                que.pop();
                if(p-1>0) q.push({p-1,t+n+1});
            }
            t++;
        }

        return t;
        
    }
};