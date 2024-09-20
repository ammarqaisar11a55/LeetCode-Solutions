class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> Temp;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    Temp.push_back(nums[j]);
                }
            }

            // bool check = is_sorted(Temp.begin(), Temp.end(), [](int a, int b) {

            //     return a < b;

            // });

            int check = true;

            for (int k = 1; k < Temp.size(); k++)
            {
                if (Temp[k - 1] >= Temp[k])
                    check = false;
            }

            if (check)
                return true;
        }

        return false;
    }
};