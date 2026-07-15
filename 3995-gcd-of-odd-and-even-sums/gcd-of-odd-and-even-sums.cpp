class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0,sumeven=0;
        for(int i = 1;i<2*n;i+=2){
            sumodd += i;
            sumeven += i+1;
        }

        return gcd(sumodd,sumeven);
    }
};