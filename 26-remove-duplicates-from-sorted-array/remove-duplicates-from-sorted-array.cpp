class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), count = 0;

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            nums[count] = nums[i];
            count++;
        }

        return count;
    }
};