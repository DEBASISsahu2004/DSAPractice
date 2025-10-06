class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = INT_MIN;

        for (int i = 0; i < n; i++) {
            high = max(nums[i], high);
        }

        while (low <= high) {
            int mid = (low + high) / 2, sum = 0;

            for (int i = 0; i < n; i++) {
                sum += ceil((double)nums[i] / (double)mid);
            }

            if (sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};