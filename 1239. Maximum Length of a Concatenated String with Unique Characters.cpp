class Solution {
public:
    bool check(string s, unordered_set<char>& st) {
        for (char c : s) {
            if (st.find(c) != st.end()) {
                return false;
            }
        }

        return true;
    }

    void Solve(string current, int index, vector<string>& arr, int& res) {
        unordered_set<char> current_st(current.begin(), current.end());

        if (current.length() != current_st.size())
            return;

        res = max(res, (int)current.length());

        if (index >= arr.size()) {
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (check(arr[i], current_st)) {
                Solve(current + arr[i], i + 1, arr, res);
            }
        }
    }

    int maxLength(vector<string>& arr) {
        int res = 0;
        Solve("", 0, arr, res);
        return res;
    }
};
