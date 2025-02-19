class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int sum1 = (length*(length+1))/2;
        int sum2 = 0;
        for(int i=0; i<length; i++){
            sum2 += nums.at(i);
        }
        return sum1 - sum2;
    }
};