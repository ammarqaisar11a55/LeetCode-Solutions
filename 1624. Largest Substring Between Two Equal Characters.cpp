class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {

        unordered_map<char, int> FirstIndices;
        int Ans = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (FirstIndices.find(s[i]) != FirstIndices.end())
            {
                Ans = max(Ans, i - FirstIndices[s[i]] - 1);
            }
            else
                FirstIndices[s[i]] = i;
        }

        return Ans;
    }
};