class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {

        int lessthanten = 0, greatorthanten = 0;

        for (auto x : nums)
        {
            if (x > 9)
                greatorthanten += x;

            if (x < 10)
                lessthanten += x;
        }

        return lessthanten == greatorthanten ? false : true;
    }
};