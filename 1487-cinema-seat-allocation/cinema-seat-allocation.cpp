class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = 0;

        // Rows with no reservations can accommodate 2 families.
        ans = (n - mp.size()) * 2;

        for (auto &[row, seats] : mp) {
            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int seat : seats) {
                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right) {
                // Both outer groups are available.
                ans += 2;
            }
            else if (left || middle || right) {
                // At least one group is available.
                ans += 1;
            }
        }

        return ans;
    }
};