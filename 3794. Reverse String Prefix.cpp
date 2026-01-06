class Solution {
public:
    string reversePrefix(string s, int k) {

        string pre;
        k--;

        for (int i = 0; i <= k; i++) {
            pre.push_back(s[i]);
        }

        for (int i = 0; i <= k; i++) {
            s[i] = pre.back();
            pre.pop_back();
        }

        return s;
    }
};