class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string temp;

            for (int i = 0; i < s.length() - 1; i++) {
                temp.push_back((s[i] + s[i + 1]) % 10);
            }

            s = temp;
        }

        return s[0] == s[1] ? true : false;
    }
};
