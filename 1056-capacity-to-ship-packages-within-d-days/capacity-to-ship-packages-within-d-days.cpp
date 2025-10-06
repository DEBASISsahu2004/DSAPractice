class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = INT_MIN, high = 0;

        for (int i = 0; i < n; i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }

        while (low <= high) {
            int mid = (low + high) / 2;

            int day = 1, load = 0;
            for (int i = 0; i < n; i++) {
                if (load + weights[i] > mid) {
                    day++;
                    load = weights[i];
                } else {
                    load += weights[i];
                }
            }

            if (day > days) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};