class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        int Smallest_String_Length = INT_MAX;

        for_each(strs.begin(), strs.end(), [&](string s)
                 { Smallest_String_Length = min(Smallest_String_Length, int(s.length())); });

        string ans;

        for (int i = 0; i < Smallest_String_Length; i++)
        {
            unordered_set<char> Temp;

            for (int j = 0; j < strs.size(); j++)
            {
                Temp.insert(strs[j][i]);
            }

            if (Temp.size() == 1)
            {
                ans.push_back(*(Temp.begin()));
                Temp.clear();
            }
            else
                break;
        }

        return ans;
    }
};