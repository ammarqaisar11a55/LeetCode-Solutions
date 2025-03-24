class Solution {
public:
    void Solve(string s, int index, int& Res,
               unordered_set<string>& Substrings) {
        if (index >= s.length()) {
            Res = max(Res, (int)Substrings.size());
            return;
        }

        string substring;

        for (int i = index; i < s.length(); i++) {
            substring.push_back(s[i]);

            if (Substrings.find(substring) == Substrings.end()) {
                Substrings.insert(substring);
                Solve(s, i + 1, Res, Substrings);
                Substrings.erase(substring);
            }
        }
    }

    int maxUniqueSplit(string s) {
        int res = 0;
        unordered_set<string> st;
        Solve(s, 0, res, st);
        return res;
    }
};
