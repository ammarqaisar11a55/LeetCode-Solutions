class Solution
{
public:
    int minimizedStringLength(string s)
    {

        unordered_set<char> ANS;

        for (int i = 0; i < s.length(); i++)
        {
            ANS.insert(s[i]);
        }

        return ANS.size();
    }
};