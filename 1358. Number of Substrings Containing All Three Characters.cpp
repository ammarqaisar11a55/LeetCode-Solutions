class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;

        int a = 0, b = 0, c = 0, left_pointer = 0;

        for (int right_pointer = 0; right_pointer < s.length();
             right_pointer++) {
            a += s[right_pointer] == 'a' ? 1 : 0;
            b += s[right_pointer] == 'b' ? 1 : 0;
            c += s[right_pointer] == 'c' ? 1 : 0;

            while (a > 0 && b > 0 && c > 0) {

                res += s.length() - right_pointer;

                a -= s[left_pointer] == 'a' ? 1 : 0;
                b -= s[left_pointer] == 'b' ? 1 : 0;
                c -= s[left_pointer] == 'c' ? 1 : 0;
                left_pointer++;
            }
        }

        return res;
    }
};
