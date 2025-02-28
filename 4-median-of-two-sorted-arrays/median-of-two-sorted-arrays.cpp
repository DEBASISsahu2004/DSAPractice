class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;
        vector<int> sorted;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                sorted.push_back(nums1[i]);
                i++;
            } else {
                sorted.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            sorted.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            sorted.push_back(nums2[j]);
            j++;
        }

        int size = sorted.size();
        if (size % 2 == 0) {
            int in = size / 2;
            return (sorted[in] + sorted[in - 1]) / 2.0;
        } else {
            return sorted[size / 2];
        }
    }
};