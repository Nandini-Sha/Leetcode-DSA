class Solution {
public:
    string winningPlayer(int x, int y) {
        int a = y/4;
        if(x<a) a = x;
        if(a%2 != 0) return "Alice";
        return "Bob";
    }
};