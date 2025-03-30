class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        unordered_set<int> st(target.begin(), target.end());

        for (int i = 1; i <= target.back(); i++) {
            if (st.find(i) == st.end()) {
                res.push_back("Push");
                res.push_back("Pop");
            } else
                res.push_back("Push");
        }

        return res;
    }
};
