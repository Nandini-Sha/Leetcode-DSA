class Solution {
public:
    long long checkb(vector<int>& piles, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += ( (long long)pile + k - 1 ) / k;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int u = *max_element(piles.begin(), piles.end());
        int ans = u;

        while (l <= u) {
            int mid = l + (u - l) / 2;
            long long hours = checkb(piles, mid);

            if (hours <= h) {
                ans = mid;
                u = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
