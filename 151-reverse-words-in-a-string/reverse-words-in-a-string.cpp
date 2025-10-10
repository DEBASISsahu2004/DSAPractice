class Solution {
public:
    string reverseWords(string s) {
        string str = "", temp = "";

        for (char c : s) {
            if (c != ' ') {
                temp += c;
            } else {
                if (!temp.empty()) {
                    if (str.empty()) {
                        str = temp;
                    } else {
                        str = temp + " " + str;
                    }
                    temp = "";
                }
            }
        }

        if (!temp.empty()) {
            if (str.empty()) {
                str = temp;
            } else {
                str = temp + " " + str;
            }
            temp = "";
        }

        return str;
    }
};