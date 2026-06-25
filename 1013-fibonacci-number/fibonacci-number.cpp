class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int first = 0;
        int second = 1;
        int temp;

        for (int i = 2; i <= n; i++) {
            temp = first + second;
            first = second;
            second = temp;
        }

        return second;
    }
};