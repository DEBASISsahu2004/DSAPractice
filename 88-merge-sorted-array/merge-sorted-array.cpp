class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m-1;
        int b = n-1;
        int right = m+n-1;

        while(b >= 0){
            if(a>=0 && nums1[a] > nums2[b]){
                nums1[right] = nums1[a];
                a--;
            }else{
                nums1[right] = nums2[b];
                b--;
            }
            right--;
        }
    }
};