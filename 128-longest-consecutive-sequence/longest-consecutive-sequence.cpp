class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLength = 1, count = 1;

        
        if(nums.size() == 0) return 0;

        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) continue;

            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                maxLength = max(maxLength, count);
                count = 1;
            }
        }

        return max(maxLength, count);
    }
};