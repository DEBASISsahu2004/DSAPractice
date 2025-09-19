class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> re;
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == (n / 3 + 1) ) {
                re.push_back(nums[i]);
            }
        }
        return re;
    }
};