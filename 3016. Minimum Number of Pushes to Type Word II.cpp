class Solution
{
public:
    int minimumPushes(string word)
    {
        unordered_map<char, int> mp;
        unordered_set<char> st(word.begin(), word.end());

        for (char c : word)
            mp[c]++;

        vector<char> Letters(vector<char>(st.begin(), st.end()));

        sort(Letters.begin(), Letters.end(), [&](char c, char d)
             { return mp[c] > mp[d]; });

        int res = 0;
        unordered_map<int, vector<char>> Mapping;
        int current_button = 2;
        unordered_map<char, pair<int, int>> Current_Alphabet_Button_with_Position;

        for (int i = 0; i < Letters.size(); i++)
        {

            while (true)
            {
                if (current_button == 7 || current_button == 9)
                {
                    if (Mapping[current_button].size() < 4)
                    {
                        break;
                    }
                }
                else if (Mapping[current_button].size() < 3)
                {
                    break;
                }

                current_button++;
            }

            Current_Alphabet_Button_with_Position[Letters[i]] = {current_button, Mapping[current_button].size()};
            Mapping[current_button].push_back(Letters[i]);

            current_button++;

            if (current_button > 9)
            {
                current_button = 2;
            }
        }

        for (int i = 0; i < word.length(); i++)
        {
            char Current_Character = word[i];

            res += Current_Alphabet_Button_with_Position[Current_Character].second + 1;
        }

        return res;
    }
};