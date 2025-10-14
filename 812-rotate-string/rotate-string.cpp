class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();

        if (n != goal.size()) {
            return false;
        }

        if (s == goal)
            return true;

        for (int i = 1; i < n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            string rotated = right + left;

            if (rotated == goal)
                return true;
        }

        return false;
    }
};