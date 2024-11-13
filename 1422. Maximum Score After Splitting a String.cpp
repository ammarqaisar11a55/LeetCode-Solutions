class Solution
{
public:
    int maxScore(string s)
    {

        int MaxScore = INT_MIN;
        int left = 0;
        int right = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                right++;
        }

        for (int i = 0; i < s.length() - 1; i++)
        {

            if (s[i] == '1')
            {
                right--;
            }
            else
                left++;

            MaxScore = max(MaxScore, left + right);
        }

        return MaxScore;
    }
};