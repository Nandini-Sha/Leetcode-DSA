class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        if(n<9){
            ans += n;
            return ans;
        }
        else{
            ans+=8;
            n-=8;
        }
        if(n<9){
            ans+=(2*n);
            return ans;
        }
        else{
            ans+=16;
            n-=8;
        }
        if(n<9){
            ans = ans + (3*n);
            return ans;
        }
        else{
            
            ans+=24;
            n-=8;
        }
        if(n<9){
            ans+=(4*n);
            return ans;
        }
        else{
            ans+=32;
            n-=8;
        }

        return ans;
    }
};