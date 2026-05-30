class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> seen;

        int res = 0;

        for (int i = 0; i < password.length(); i++) {
            if (seen.find(password[i]) != seen.end()) {
                continue;
            }

            if (isalnum(password[i])) {
                if (isalpha(password[i])) {
                    if (isupper(password[i])) {
                        res += 2;
                    } else {
                        res++;
                    }
                } else {
                    res += 3;
                }
            } else {
                res += 5;
            }

            seen.insert(password[i]);
        }

        return res;
    }
};