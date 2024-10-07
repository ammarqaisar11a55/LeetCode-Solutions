class Solution
{
public:
    bool digitCount(string num)
    {

        unordered_map<int, int> Mp;

        for (char a : num)
            Mp[a - '0']++;

        for (int i = 0; i < num.length(); i++)
        {
            if (Mp[i] != num[i] - '0')
                return false;
        }

        return true;
    }
};