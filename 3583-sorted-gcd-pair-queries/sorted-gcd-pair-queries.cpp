class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        const int MAX = *max_element(nums.begin(), nums.end());

        // freq[x] = occurrences of x
        vector<long long> freq(MAX + 1, 0);
        for (int x : nums)
            freq[x]++;

        // divCnt[d] = numbers divisible by d
        vector<long long> divCnt(MAX + 1, 0);
        for (int d = 1; d <= MAX; d++) {
            for (int m = d; m <= MAX; m += d)
                divCnt[d] += freq[m];
        }

        // exact[d] = number of pairs with gcd exactly d
        vector<long long> exact(MAX + 1, 0);
        for (int d = MAX; d >= 1; d--) {
            long long k = divCnt[d];
            exact[d] = k * (k - 1) / 2;

            for (int m = d + d; m <= MAX; m += d)
                exact[d] -= exact[m];
        }

        // prefix counts
        vector<long long> pref(MAX + 1, 0);
        for (int d = 1; d <= MAX; d++)
            pref[d] = pref[d - 1] + exact[d];

        vector<int> ans;
        for (long long q : queries) {
            // first gcd value whose prefix count > q
            int g = upper_bound(pref.begin(), pref.end(), q) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};