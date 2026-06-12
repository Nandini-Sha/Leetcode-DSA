class Solution {
public:
    double med(vector<int>& A, int a, vector<int>& B, int b, int total){
        int leftSize = (total + 1) / 2;
        int l1 = min(a, leftSize) - 1;
        int l2 = leftSize - l1 - 2;

       while (
    (l1 >= 0 && l2 + 1 < b && A[l1] > B[l2 + 1]) ||
    (l2 >= 0 && l1 + 1 < a && B[l2] > A[l1 + 1])
)
{
            if (A[l1] > B[l2 + 1]) {
                l1--;
                l2++;
            } else {
                l2--;
                l1++;
            }
        }

        int leftMax = max(
            (l1 >= 0 ? A[l1] : INT_MIN),
            (l2 >= 0 ? B[l2] : INT_MIN)
        );

        int rightMin = min(
            (l1 + 1 < a ? A[l1 + 1] : INT_MAX),
            (l2 + 1 < b ? B[l2 + 1] : INT_MAX)
        );

        if (total % 2 == 0) {
            return (leftMax + rightMin) / 2.0;
        } else {
            return (double) leftMax;
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;

        if (m < n)
            return med(nums1, m, nums2, n, total);
        else
            return med(nums2, n, nums1, m, total);
    }
};
