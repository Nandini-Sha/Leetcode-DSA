class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rankMap;
        int rank = 1;
        rankMap[sorted[0]] = rank;

        for (int i = 1; i < sorted.size(); ++i) {
            if (sorted[i] != sorted[i - 1]) {
                ++rank;
            }
            rankMap[sorted[i]] = rank;
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rankMap[arr[i]];
        }

        return arr;
    }
};

