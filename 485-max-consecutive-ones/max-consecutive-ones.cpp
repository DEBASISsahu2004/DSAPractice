class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums.at(i) == 1){
                count++;
            }else{
                count = 0;
            }

            if(max < count){
                max = count;
            }
        }
        return max;
    }
};