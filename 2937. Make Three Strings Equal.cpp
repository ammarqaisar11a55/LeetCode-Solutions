class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {

        int minlength = min(s1.length(), min(s2.length(), s3.length()));

        int common = 0;

        for (int i = 0; i < minlength; i++)
        {
            if (s1[i] == s2[i] && s2[i] == s3[i])
            {
                common++;
            }
            else
            {
                break;
            }
        }

        return common == 0 ? -1 : s1.length() - common + s2.length() - common + s3.length() - common;
    }
};