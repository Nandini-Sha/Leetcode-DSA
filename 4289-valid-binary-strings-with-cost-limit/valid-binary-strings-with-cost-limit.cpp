class Solution {
public:
    vector<string> ans;
    vector<string> generateValidStrings(int n, int k) {
        dfs("0", n, k, 0, 1);
        dfs("1", n, k, 0, 1);

        return ans;
    }

    void dfs(string s, int n, int k, int cost, int i){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        if(s.back()=='1'){
            s+='0';
            dfs(s,n,k,cost,i+1);
        }
        else{
            s+='0';
            dfs(s,n,k,cost,i+1);
            s.pop_back();
            s+='1';
            if(cost+i<=k) 
                dfs(s,n,k,cost+i,i+1);
        }
    }
};