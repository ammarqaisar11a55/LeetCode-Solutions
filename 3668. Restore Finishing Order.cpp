class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> st(friends.begin(), friends.end());

        vector<int> res;

        for (int n : order) {
            if (st.find(n) != st.end()) {
                res.push_back(n);
            }
        }

        return res;
    }
};
