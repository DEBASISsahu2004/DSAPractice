class Solution {
public:
    unordered_map<int, int> m;
    int dp[2000][2000];

    bool solve(int i, int k, vector<int>& stones){
        if(i == stones.size()-1){
            return true;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        bool s1 = false, s2 = false, s3 = false;

        if(m.find(stones[i] + k) != m.end()){
            s1 = solve(m[stones[i] + k], k, stones);
        }

        
        if(k>1 && m.find(stones[i] + k - 1) != m.end()){
            s2 = solve(m[stones[i] + k - 1], k-1, stones);
        }

        
        if(m.find(stones[i] + k + 1) != m.end()){
            s3 = solve(m[stones[i] + k + 1], k + 1, stones);
        }

        dp[i][k] = s1 || s2 || s3;
        return dp[i][k];
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] != 1){
            return false;
        }
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<stones.size(); i++){
            m[stones[i]] = i;
        }

        return solve(1, 1, stones);
    }
};