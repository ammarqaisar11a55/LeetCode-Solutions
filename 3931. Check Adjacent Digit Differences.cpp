class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i < s.length() - 1; i++) {
            int left = s[i] - '0';
            int right = s[i + 1] - '0';

            if (abs(left - right) > 2) {
                return false;
            }
        }

        return true;
    }
};