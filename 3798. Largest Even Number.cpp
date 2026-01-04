class Solution {
public:
    string largestEven(string s) {
        for (int i = s.length() - 1; i >= 0; i--) {
            int digit = s[i] - '0';

            if (digit & 1) {
                s.pop_back();
            } else {
                break;
            }
        }

        return s;
    }
};