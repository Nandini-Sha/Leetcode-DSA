class Solution {
private:
    vector<vector<string>> ans;
public:
    bool ispalin(string s){
        string p = s;
        reverse(p.begin(),p.end());
        return p==s;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        back(s,0,temp);

        return ans;
    }
    void back(string s, int start, vector<string> temp){
        if(start == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int end = start;end<s.size();end++){
            string a = s.substr(start,end-start+1);
            if(ispalin(a)){
                temp.push_back(a);
                back(s,end+1,temp);
                temp.pop_back();
            }
        }
    }
};