class Solution {
public:
    bool isvowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? true
                                                                        : false;
    }

    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for (char s : s) {

            if (s >= '0' && s <= '9') {
                continue;
            }

            if (s == ' ') {
                continue;
            }

            if (isvowel(s)) {
                v++;
            } else {
                c++;
            }
        }

        cout << "v: " << v << " , c:" << c << endl;

        return c > 0 ? floor(v / c) : 0;
    }
};