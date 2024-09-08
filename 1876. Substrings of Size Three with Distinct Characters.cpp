class Solution
{
public:
    int countGoodSubstrings(string s)
    {

        if (s.length() < 3)
            return 0;

        int CountGood = 0;

        for (int i = 0; i < s.length() - 2; i++)
        {
            string substring = s.substr(i, 3);

            unordered_set<char> Unique;

            for (char x : substring)
            {
                Unique.insert(x);
            }

            if (substring.length() == Unique.size())
                CountGood++;
        }

        return CountGood;
    }
};