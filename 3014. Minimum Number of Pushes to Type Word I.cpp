class Solution
{
public:
    int minimumPushes(string word)
    {
        int res = 0;
        unordered_map<char, int> mp;
        unordered_map<int, vector<char>> Buttons_with_Mapped_Keys;
        int Current_button = 2;

        int i = 0;
        while (i < word.size())
        {
            int Character = word[i];

            Buttons_with_Mapped_Keys[Current_button].push_back(Character);
            mp[Character] = Buttons_with_Mapped_Keys[Current_button].size();

            Current_button++;

            if (Current_button > 9)
            {
                Current_button = 2;
            }

            i++;
        }

        for (char c : word)
        {
            res += mp[c];
        }

        return res;
    }
};