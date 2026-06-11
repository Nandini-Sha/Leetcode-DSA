class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0;i< s.size();i++){
            if(isalnum(s[i])) continue;
            else{
                s.erase(i,1);
                i--;
            }
        }
        cout<<s;
        int i = 0,j=s.size()-1;
        while(i<j){
            if(tolower(s[i]) != tolower(s[j])) return false;
            else{
                i++;
                j--;
            }
        }

        return true;
    }
};