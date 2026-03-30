class Solution {
public:
    double get_kth_value(vector<int>& nums1, int m, vector<int>& nums2, int n,
                         int k, int index1, int index2) {
        if (m > n) {
            return get_kth_value(nums2, n, nums1, m, k, 0, 0);
        }
        if (m == 0) {
            return nums2[index2 + k - 1];
        }
        if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }
        int i = min(m, k / 2);
        int j = min(n, k / 2);
        if (nums1[index1 + i - 1] > nums2[index2 + j - 1]) {
            return get_kth_value(nums1, m, nums2, n - j, k - j, index1, index2 + j);
        } else {
            return get_kth_value(nums1, m - i, nums2, n, k - i, index2 + i, index2);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left = (nums1.size() + nums2.size() + 1) / 2;
        int right = (nums1.size() + nums2.size() + 2) / 2;
        return (get_kth_value(nums1, nums1.size(), nums2, nums2.size(), left,
                0, 0) + 
                get_kth_value(nums1, nums1.size(), nums2, nums2.size(), right,
                0, 0)) / 2.0;
    }
};
