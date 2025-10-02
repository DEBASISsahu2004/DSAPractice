class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        int minNum = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] < minNum)
                minNum = min(minNum, nums[mid]);
            
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return minNum;
    }
};