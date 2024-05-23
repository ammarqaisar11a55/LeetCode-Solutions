class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        vector<int> odds;
        vector<int> evens;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) % 2 == 0)
            {
                evens.push_back(nums.at(i));
            }
            else
            {

                odds.push_back(nums.at(i));
            }
        }

        nums.clear();

        for (int i = 0; i < evens.size(); i++)
        {
            nums.push_back(evens.at(i));
        }

        for (int i = 0; i < odds.size(); i++)
        {
            nums.push_back(odds.at(i));
        }

        odds.clear();
        evens.clear();

        odds.shrink_to_fit();
        evens.shrink_to_fit();

        return nums;
    }
};