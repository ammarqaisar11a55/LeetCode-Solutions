class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {

        int fivedollar = 0;
        int tendollar = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            // If Customer give us a bill of 5 dollars
            if (bills[i] == 5)
            {
                fivedollar++;
                continue;
            }

            // If Customer give us a bill of 10 dollars
            if (bills[i] == 10)
            {
                if (fivedollar > 0)
                {
                    tendollar++;
                    fivedollar--;
                }
                else
                    return false;

                continue;
            }

            // If Customer give us a bill of 20 dollars
            if (bills[i] == 20)
            {
                if (fivedollar > 0 && tendollar > 0)
                {
                    fivedollar--;
                    tendollar--;
                }
                else if (fivedollar >= 3)
                {
                    fivedollar -= 3;
                }
                else
                    return false;
            }
        }

        return true;
    }
};