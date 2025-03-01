class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int maxSum = nums[0] + nums[1] + nums[2], n=nums.size();

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l=i+1, r=n-1;

            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];

                if(abs(sum-target) < abs(maxSum-target)){
                    maxSum = sum;
                }

                if(sum > target){
                    r--;
                }else if(sum < target){
                    l++;
                }else{
                    return sum;
                }
            }
        }

        return maxSum;
    }
};