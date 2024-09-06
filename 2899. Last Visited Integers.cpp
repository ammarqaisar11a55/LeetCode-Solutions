class Solution
{
public:
    vector<int> lastVisitedIntegers(vector<int> &nums)
    {

        vector<int> Seen, Ans;
        int k = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
            {

                if (k <= Seen.size())
                {
                    Ans.push_back(Seen[k - 1]);
                    k++;
                }
                else
                {
                    Ans.push_back(-1);
                }
            }
            else
            {
                Seen.insert(Seen.begin() + 0, nums[i]);
                k = 1;
            }
        }

        return Ans;
    }
};