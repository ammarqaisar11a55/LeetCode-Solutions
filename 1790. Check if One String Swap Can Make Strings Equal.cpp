class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {

        if (s1 == s2)
            return true;

        unordered_map<char, int> W1, W2;
        unordered_set<char> Characters;
        int difference = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            W1[s1[i]]++;
            W2[s2[i]]++;
            Characters.insert(s1[i]);
            Characters.insert(s2[i]);

            if (s1[i] != s2[i])
                difference++;
        }

        for (auto it = Characters.begin(); it != Characters.end(); it++)
        {
            if (W1[*it] != W2[*it])
                return false;
        }

        return difference == 0 || difference == 2 ? true : false;
    }
};