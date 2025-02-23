class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int initial = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < initial) initial = prices[i];
            if(prices[i]-initial > maxPro) maxPro = prices[i]-initial;
        }

        return maxPro;
    }
};