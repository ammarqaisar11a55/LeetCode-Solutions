class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_set<int> st;

        for (int i = 0; i < bulbs.size(); i++) {
            if (st.find(bulbs[i]) == st.end()) {
                st.insert(bulbs[i]);
            } else {
                st.erase(bulbs[i]);
            }
        }

        vector<int> res;

        for (auto x : st) {
            res.push_back(x);
        }

        sort(res.begin(), res.end());

        return res;
    }
};