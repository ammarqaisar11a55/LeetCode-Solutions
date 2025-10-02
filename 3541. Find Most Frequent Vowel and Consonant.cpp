class Solution {
public:
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? true
                                                                        : false;
    }

    int maxFreqSum(string s) {

        unordered_map<char, int> freq;

        int vowels = 0, consonents = 0;

        for (char c : s) {
            freq[c]++;

            if (is_vowel(c)) {
                vowels = max(vowels, freq[c]);
            } else {
                consonents = max(consonents, freq[c]);
            }
        }

        return vowels + consonents;
    }
};
