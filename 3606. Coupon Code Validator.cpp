class Solution {
public:
    bool code_checker(string s) {

        for (char c : s) {
            if (isalnum(c) == false && c != '_') {
                return false;
            }
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        unordered_set<int> ignored_indicies;
        vector<string> res;
        unordered_map<string, vector<string>> mapping;

        for (int i = 0; i < code.size(); i++) {
            if (isActive[i]) {
                if (businessLine[i] == "electronics" ||
                    businessLine[i] == "grocery" ||
                    businessLine[i] == "pharmacy" ||
                    businessLine[i] == "restaurant") {
                    if (code_checker(code[i])) {
                        mapping[businessLine[i]].push_back(code[i]);
                    }
                }
            }
        }

        sort(mapping["electronics"].begin(), mapping["electronics"].end());
        sort(mapping["grocery"].begin(), mapping["grocery"].end());
        sort(mapping["pharmacy"].begin(), mapping["pharmacy"].end());
        sort(mapping["restaurant"].begin(), mapping["restaurant"].end());

        for (string s : mapping["electronics"]) {
            if (s.empty() == false)
                res.push_back(s);
        }

        for (string s : mapping["grocery"]) {
            if (s.empty() == false)
                res.push_back(s);
        }

        for (string s : mapping["pharmacy"]) {
            if (s.empty() == false)
                res.push_back(s);
        }

        for (string s : mapping["restaurant"]) {
            if (s.empty() == false)
                res.push_back(s);
        }

        return res;
    }
};
