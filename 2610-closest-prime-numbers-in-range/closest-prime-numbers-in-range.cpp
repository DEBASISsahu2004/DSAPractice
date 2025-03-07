class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int N = right + 1; 
        vector<bool> isPrime(N, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) primes.push_back(i);
        }

        int n = primes.size();
        vector<int> result = {-1, -1};

        if (n <= 1) return result; 

        int minDiff = INT_MAX;
        for (int i = 1; i < n; i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};
