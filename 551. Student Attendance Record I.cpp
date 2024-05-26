class Solution
{
public:
    bool checkRecord(string s)
    {

        {
            int absents = 0;
            int lates = 0;

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == 'A')
                {
                    absents++;
                }

                if (s[i] == 'L')
                {
                    lates++;
                    if (lates >= 3)
                    {
                        return false;
                    }
                }
                else
                    lates = 0;
            }

            if (absents < 2 && lates < 3)
            {
                return true;
            }
            else
                return false;
        }
    }
};