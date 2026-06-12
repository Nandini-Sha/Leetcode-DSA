class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return 1;
        unordered_map<char,int> c;
        int i = 0, j = 1;
        int ans = 0;
        c.insert({s[i],i});
        while(j<s.size()){
            if(c.find(s[j]) == c.end()){
                c.insert({s[j],j});
            }
            else{
                auto it = c.find(s[j]);
                i = max(i,it->second + 1);
                c[s[j]] = j;
            }
            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};