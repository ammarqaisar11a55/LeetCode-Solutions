class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? true
                                                                        : false;
    }

    string trimTrailingVowels(string s) {
        while (s.empty() == false && is_vowel(s.back()) == true) {
            s.pop_back();
        }

        return s;
    }
};