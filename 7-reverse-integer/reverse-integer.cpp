class Solution {
public:
    int reverse(int x) {
        int sum = 0; // Initialize a variable to store the reversed number

        while (x != 0) { // Continue the loop until x becomes 0

            if (sum > INT_MAX/10 || sum < INT_MIN/10) { // Check if adding the next digit will cause overflow
                return 0; // If overflow occurs, return 0
            }

            int rem = x % 10; // Get the last digit of x
            sum = sum * 10 + rem; // Multiply the current sum by 10 and add the last digit
            x = x / 10; // Remove the last digit from x
        }

        return sum; // Return the reversed number
    }
};
