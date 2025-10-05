class Solution {
public:
    int MaxVal(vector<int>& piles){
        int maxVal = INT_MIN;

        for(int i=0; i<piles.size(); i++){
            maxVal = max(piles[i], maxVal);
        }

        return maxVal;
    }

    long long totalHour(vector<int>& piles, int k){
        long long totalH = 0;

        for(int i=0; i<piles.size(); i++){
            totalH += ceil((double)(piles[i]) / (double)(k));
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = MaxVal(piles);

        while(low <= high){
            int mid = low+(high-low)/2;

            long long totalH = totalHour(piles, mid);

            if(totalH <= h) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};