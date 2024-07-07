class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        vector<int> ANS(nums.size(), 0);
        int positive = 0;
        int negative = 1;

        for (auto x : nums)
        {
            if (x > 0)
            {
                ANS[positive] = x;
                positive += 2;
            }
            else
            {
                ANS[negative] = x;
                negative += 2;
            }
        }
        return ANS;
    }
};