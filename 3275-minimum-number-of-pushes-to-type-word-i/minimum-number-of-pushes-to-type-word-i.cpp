class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        if(n>0 && n<9) return n;
        if(n>8 && n<17) return 8+(2*(n-8));
        if(n>16 && n<25) return 24+(3*(n-16));
        if(n>24) return 48+(4*(n-24));
        return -1;
    }
};