class Solution {
public:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? true : false;
    }

    string reverseWords(string s) {
        vector<string> words;

        s.push_back(' ');

        string word;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word.push_back(s[i]);
            } else {
                words.push_back(word);
                word.clear();
            }
        }

        string res;

        int first_word_vowel_count = 0;

        for (int i = 0; i < words[0].length(); i++) {
            if (isVowel(words[0][i])) {
                first_word_vowel_count++;
            }
        }

        res = words[0] + ' ';

        for (int i = 1; i < words.size(); i++) {
            string word_from_collection = words[i];
            int current_word_vowel_count = 0;

            for (int j = 0; j < word_from_collection.length(); j++) {
                if (isVowel(word_from_collection[j])) {
                    current_word_vowel_count++;
                }
            }

            if (current_word_vowel_count == first_word_vowel_count) {
                reverse(words[i].begin(), words[i].end());
            }

            res += words[i];

            if (i != words.size() - 1) {
                res += ' ';
            }
        }

        if (res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};