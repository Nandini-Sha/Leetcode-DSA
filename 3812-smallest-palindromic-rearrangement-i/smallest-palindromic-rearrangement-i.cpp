class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> a(26,0);
        for(int i = 0;i<s.size();i++){
            a[s[i]-'a'] ++;
        }
        int j = 0;
        int n = s.size();
        s = "";
        for(int i = 0;i<26;i++){
            while(a[i]>=2){
                char c = i+'a';
                s.insert(j,2,c);
                j++;
                a[i]-=2;
            }
        }
        for(int i = 0;i<26;i++){
            if(a[i]==1){
                char c = i+'a';
                s.insert(j,1,c);
                j++;
                a[i]-=1;
            }
        }
        return s;
    }
};