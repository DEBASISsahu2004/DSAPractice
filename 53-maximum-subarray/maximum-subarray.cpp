class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxi = 0;

        for(int i=0; i<nums.size(); i++){
            if(maxi < 0){
                maxi = 0;
            }

            maxi += nums[i];
            sum = max(maxi, sum);
        }

        return sum;
    }
};