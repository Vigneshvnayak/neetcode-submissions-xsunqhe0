class Solution {
public:
    int get_kth_value(int index1, int index2, int k, vector<int>& nums1,
        int len1, vector<int>& nums2, int len2) {
            if (len1 > len2) {
                return get_kth_value(index2, index1, k, nums2, len2, nums1, len1);
            }
            if (len1 == 0) {
                return nums2[index2 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            int i = min(len1, k / 2);
            int j = min(len2, k / 2);
            int res = 0;
            if (nums1[index1 + i - 1] > nums2[index2 + j - 1]) {
                res = get_kth_value(index1, index2 + j, k - j, nums1, len1, nums2, len2 - j);
            } else {
                res = get_kth_value(index1 + i, index2, k - i, nums1, len1 - i, nums2, len2);
            }
            return res;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int m1 = (len1 + len2 + 1) / 2;
        int m2 = (len1 + len2 + 2) / 2;
        double res = (get_kth_value(0, 0, m1, nums1, len1, nums2, len2) +
                        get_kth_value(0, 0, m2, nums1, len1, nums2, len2)) / 2.0;
        return res;
    }
};
