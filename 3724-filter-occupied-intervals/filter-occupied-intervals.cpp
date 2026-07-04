class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> result;

        int a = occupiedIntervals[0][0];
        int b = occupiedIntervals[0][1];

        // Merge overlapping and adjacent intervals
        for (int i = 1; i < occupiedIntervals.size(); i++) {
            if (occupiedIntervals[i][0] <= b + 1) {
                b = max(b, occupiedIntervals[i][1]);
            } else {
                result.push_back({a, b});
                a = occupiedIntervals[i][0];
                b = occupiedIntervals[i][1];
            }
        }
        result.push_back({a, b});

        vector<vector<int>> merged;

        // Remove the free interval
        for (auto &interval : result) {
            a = interval[0];
            b = interval[1];

            // No overlap
            if (b < freeStart || a > freeEnd) {
                merged.push_back({a, b});
            }
            // Completely inside free interval
            else if (a >= freeStart && b <= freeEnd) {
                continue;
            }
            // Left overlap
            else if (a < freeStart && b <= freeEnd) {
                if (a <= freeStart - 1)
                    merged.push_back({a, freeStart - 1});
            }
            // Right overlap
            else if (a >= freeStart && b > freeEnd) {
                if (freeEnd + 1 <= b)
                    merged.push_back({freeEnd + 1, b});
            }
            // Free interval lies inside occupied interval
            else {
                if (a <= freeStart - 1)
                    merged.push_back({a, freeStart - 1});
                if (freeEnd + 1 <= b)
                    merged.push_back({freeEnd + 1, b});
            }
        }

        return merged;
    }
};