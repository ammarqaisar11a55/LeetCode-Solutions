class Solution {
public:
    bool compare_words(string fix, string dic_word) {
        int d = 0;

        for (int i = 0; i < fix.length(); i++) {
            if (d < dic_word.length() && fix[i] == dic_word[d]) {
                d++;
            }
        }

        return d >= dic_word.length() ? true : false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string res;

        for (string word : dictionary) {
            if (compare_words(s, word)) {
                if (res.empty()) {
                    res = word;
                } else {
                    if (res.length() < word.length()) {
                        res = word;
                        continue;
                    }

                    else if (res.length() == word.length()) {
                        res = min(res, word);
                    }
                }
            }
        }

        return res;
    }
};
