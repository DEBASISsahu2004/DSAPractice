class Solution {
public:
    int v[46];
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }

        if(v[n] != 0) return v[n];
        v[n] = climbStairs(n-1) + climbStairs(n-2);

        return v[n];
    }
};