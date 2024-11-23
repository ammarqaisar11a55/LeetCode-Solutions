class Solution
{
public:
    bool IsAnyCharacterCommon(string a, string b, unordered_map<string, unordered_set<char>> &mp)
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (mp[b].find(a[i]) != mp[b].end())
                return true;
        }

        return false;
    }

    int maxProduct(vector<string> &words)
    {

        unordered_map<string, unordered_set<char>> mp;

        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]].insert(words[i].begin(), words[i].end());
        }

        sort(words.begin(), words.end(), [](string a, string b)
             { return a.length() < b.length(); });

        int MaxProduct = INT_MIN;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = words.size() - 1; j > i; j--)
            {
                if (IsAnyCharacterCommon(words[i], words[j], mp) == false)
                {
                    MaxProduct = max(MaxProduct, int(words[i].length() * words[j].length()));
                    break;
                }
            }
        }

        return MaxProduct == INT_MIN ? 0 : MaxProduct;
    }
};