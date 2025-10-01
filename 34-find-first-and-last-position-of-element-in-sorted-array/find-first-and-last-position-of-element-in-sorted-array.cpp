class Solution {
public:
    int bs(vector<int>& nums, int target, bool leftSearch) {
        int left = 0, right = nums.size() - 1, ind = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                ind = mid;
                if (leftSearch) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return ind;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = bs(nums, target, true);
        int right = bs(nums, target, false);
        result[0] = left;
        result[1] = right;
        return result;
    }
};