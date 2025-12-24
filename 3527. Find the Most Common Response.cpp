class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        string res;
        int max_freq = INT_MIN;

        unordered_map<string, int> responeses_freq;

        for (vector<string> person : responses) {
            unordered_set<string> st;

            for (string resp : person) {
                if (st.find(resp) == st.end()) {
                    st.insert(resp);
                    responeses_freq[resp]++;
                    max_freq = max(max_freq, responeses_freq[resp]);
                }
            }
        }

        for (auto [response, freq] : responeses_freq) {
            if (freq == max_freq) {
                if (res.empty()) {
                    res = response;
                    continue;
                }
                res = min(res, response);
            }
        }

        return res;
    }
};
