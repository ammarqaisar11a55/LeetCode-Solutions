class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string N[10] = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        for (int i = 0; i < 10; i++)
        {
            if (num.find(N[i]) != string::npos)
            {
                return N[i];
            }
        }

        return "";
    }
};
