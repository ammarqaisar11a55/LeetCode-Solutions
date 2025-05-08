class Solution {
public:
    bool check_vowel(const char& a) {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ? true
                                                                        : false;
    }

    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> Prefix((int)words.size());

        Prefix[0] =
            check_vowel(words[0].front()) && check_vowel(words[0].back()) ? 1
                                                                          : 0;

        for (int i = 1; i < words.size(); i++) {
            if (check_vowel(words[i].front()) && check_vowel(words[i].back())) {
                Prefix[i] = Prefix[i - 1] + 1;
            } else {
                Prefix[i] = Prefix[i - 1] + 0;
            }
        }

        vector<int> Res((int)queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int current_ans = Prefix[queries[i][1]];

            if (queries[i][0] - 1 >= 0) {
                current_ans -= Prefix[queries[i][0] - 1];
            }

            Res[i] = current_ans;
        }

        return Res;
    }
};
