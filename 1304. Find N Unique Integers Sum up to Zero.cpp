class Solution
{
public:
    vector<int> sumZero(int n)
    {

        vector<int> ANS;

        if (n % 2 == 0)
        {
            for (int i = 1; i <= n / 2; i++)
            {
                ANS.push_back(i);
                ANS.push_back(-1 * i);
            }
        }
        else
        {
            for (int i = 1; i <= n / 2; i++)
            {
                ANS.push_back(i);
                ANS.push_back(-1 * i);
            }

            ANS.push_back(0);
        }

        return ANS;
    }
};