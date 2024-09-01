class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {

        int turns = 0;

        for (int i = s.length() - 1; i >= 0; i--)
        {
            turns = (shifts[i] + turns) % 26;
            s[i] = (s[i] - 'a' + turns) % 26 + 'a';
        }

        return s;
    }
};