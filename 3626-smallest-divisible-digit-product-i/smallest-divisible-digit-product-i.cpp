class Solution {
public:
    int smallestNumber(int n, int t) {
        int a;
        for(int i = n;i<=100;i++){
            a = 1;
            n = i;
            while(n){
                a*=n%10;
                n=n/10;
            }
            if(a%t == 0) return i;
        }

        return -1;
    }
};