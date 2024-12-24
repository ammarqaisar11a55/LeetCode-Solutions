class Solution
{
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {

        vector<int> res((int)s.length());

        for (int i = 0; i < s.length(); i++)
        {
            int Count = 0;
            int x = startPos[0];
            int y = startPos[1];

            for (int j = i; j < s.length(); j++)
            {
                if (s[j] == 'U')
                {
                    x--;
                }
                else if (s[j] == 'D')
                {
                    x++;
                }
                else if (s[j] == 'L')
                {
                    y--;
                }
                else
                {
                    y++;
                }

                if (x < 0 || y < 0 || x >= n || y >= n)
                    break;

                Count++;
            }

            res[i] = Count;
        }

        return res;
    }
};