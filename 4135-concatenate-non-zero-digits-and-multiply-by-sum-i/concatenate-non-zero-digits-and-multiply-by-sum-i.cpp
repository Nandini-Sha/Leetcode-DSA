class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> a;
        int x;
        while(n>0){
            x = n%10;
            if(x!=0){
                a.push_back(x);
            }
            n=n/10;
        }
        if(a.empty()) return 0;
        long long sum = accumulate(a.begin(),a.end(),0LL);
        x = 0;
        int m = a.size();
        for(int i = a.size()-1;i>=0;i--){
            x = x*10 + a[i];
            m--;
        }
        long long result = x*sum;
        return result;
    }
};