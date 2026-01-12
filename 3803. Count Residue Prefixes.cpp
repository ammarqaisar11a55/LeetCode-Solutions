class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> st;
        string prefix;

        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            prefix.push_back(s[i]);
            st.insert(s[i]);

            if (st.size() == (int)prefix.length() % 3) {
                res++;
            }
        }

        return res;
    }
};