class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {

        int ans = 0;

        for (int i = 0; i < strs.size(); i++)
        {
            int count = 0;
            int temp = 0;
            for (int j = 0; j < strs[i].length(); j++)
            {
                if (isdigit(strs[i][j]))
                {
                    count++;
                }
                else
                    break;
            }
            if (count == strs[i].length())
            {
                temp = stoi(strs[i]);
            }
            else
                temp = strs[i].length();

            if (temp > ans)
            {
                ans = temp;
            }
        }

        return ans;
    }
};