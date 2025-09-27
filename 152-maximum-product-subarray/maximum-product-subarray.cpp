class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = INT_MIN, pre = 1, suf = 1, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (!pre)
                pre = 1;
            if (!suf)
                suf = 1;
            pre *= nums[i];
            suf *= nums[n - i - 1];
            maxPro = max(maxPro, max(pre, suf));
        }

        return maxPro;
    }
};