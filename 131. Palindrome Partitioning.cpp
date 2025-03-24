class Solution {
public:
    bool check(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }

        return true;
    }

    void Solve(string s, int index, vector<string> current_res,
               vector<vector<string>>& Res) {
        if (index >= s.length()) {
            if (current_res.empty() == false)
                Res.push_back(current_res);

            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (check(s.substr(index, i - index + 1))) {
                current_res.push_back(s.substr(index, i - index + 1));
                Solve(s, i + 1, current_res, Res);
                current_res.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> Res;
        Solve(s, 0, {}, Res);
        return Res;
    }
};
