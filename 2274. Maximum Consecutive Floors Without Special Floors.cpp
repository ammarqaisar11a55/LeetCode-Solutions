/*
    Approach 1: Brute Force (Time Limit Exceed)
*/

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {

        unordered_set<int> Special_Floors(special.begin(), special.end());
        int Ans = 0;
        int count = 0;

        for (int i = bottom; i <= top; i++)
        {
            if (Special_Floors.find(i) != Special_Floors.end())
            {
                Ans = max(Ans, count);
                count = 0;
            }
            else
            {
                count++;
            }
        }

        Ans = max(Ans, count);

        return Ans;
    }
};

/*
    Approach 2:
*/

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {

        sort(special.begin(), special.end());

        int Ans = 0;

        for (int i = 1; i < special.size(); i++)
        {
            Ans = max(Ans, special[i] - special[i - 1] - 1);
        }

        Ans = max(Ans, special[0] - bottom);
        Ans = max(Ans, top - special.back());

        return Ans;
    }
};