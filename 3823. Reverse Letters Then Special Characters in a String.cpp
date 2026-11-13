class Solution {
public:
    string reverseByType(string s) {

        string specials = "!@#$%^&*()";

        unordered_set<char> fast_specials;

        for (int i = 0; i < specials.size(); i++) {
            fast_specials.insert(specials[i]);
        }

        vector<char> alphas, sp_char;

        for (int i = 0; i < s.length(); i++) {
            if (fast_specials.find(s[i]) == fast_specials.end()) {
                alphas.push_back(s[i]);
            } else {
                sp_char.push_back(s[i]);
            }
        }

        for (int i = 0; i < s.length(); i++) {
            if (fast_specials.find(s[i]) == fast_specials.end()) {
                s[i] = alphas.back();
                alphas.pop_back();
            } else {
                s[i] = sp_char.back();
                sp_char.pop_back();
            }
        }

        return s;
    }
};
