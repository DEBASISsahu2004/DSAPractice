class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> re(nums.size());

        int pos = 0, neg = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                re[pos] = nums[i];
                pos += 2;
            } else {
                re[neg] = nums[i];
                neg += 2;
            }
        }

        return re;
    }
};