class Solution {
public:
    int dp[100];

    int solve(int k, vector<int>& nums) {
        if (k >= nums.size()) {
            return 0;
        }

        if (dp[k] != -1) {
            return dp[k];
        }

        int pick = nums[k] + solve(k + 2, nums);
        int skip = solve(k + 1, nums);

        return dp[k] = max(pick, skip); 
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); 
        return solve(0, nums);
    }
};
