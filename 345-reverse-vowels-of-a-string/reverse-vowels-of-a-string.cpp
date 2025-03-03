class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        unordered_set<char> arr = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (l < r) {
            while( l<r && arr.find(s[l]) == arr.end()) l++;
            while( l<r && arr.find(s[r]) == arr.end()) r--;

            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            
            l++;
            r--;
        }

        return s;
    }
};