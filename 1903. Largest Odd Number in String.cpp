class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;

        string res;

        for (int i = num.length() - 1; i >= 0; i--) {
            int digit = num[i] - '0';

            if (digit & 1) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return "";
        }

        for (int i = index; i >= 0; i--) {
            res = num[i] + res;
        }

        return res;
    }
};