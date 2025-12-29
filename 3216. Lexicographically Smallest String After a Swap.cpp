class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.length() - 1; i++) {
            int left = s[i] - '0';
            int right = s[i + 1] - '0';

            int left_parity = left % 2 == 0 ? 0 : 1;
            int right_parity = right % 2 == 0 ? 0 : 1;

            if (left_parity == right_parity) {
                if (left > right) {
                    swap(s[i], s[i + 1]);
                    break;
                }
            }
        }

        return s;
    }
};