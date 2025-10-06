class Solution {
public:
    bool possible(vector<int>& bloomDay, int mid, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int nb = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid)
                cnt++;
            else{
                nb += cnt / k;
                cnt=0;
            }
        }
        nb += cnt / k;
        return nb >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        if (val > n)
            return -1;

        int low = INT_MAX, high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};