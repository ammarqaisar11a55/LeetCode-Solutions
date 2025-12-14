class Solution {
public:
    inline bool compare_strings(string s, string e) {
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        return s == e ? true : false;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        bool array_has_anagrams = true;

        while (array_has_anagrams) {
            bool this_iteration_has_anagrams = false;

            for (int i = 1; i < words.size(); i++) {
                if (compare_strings(words[i], words[i - 1])) {
                    this_iteration_has_anagrams = true;

                    words.erase(words.begin() + i);

                    break;
                }
            }

            if (this_iteration_has_anagrams) {
                array_has_anagrams = true;
            } else {
                array_has_anagrams = false;
            }
        }

        return words;
    }
};
