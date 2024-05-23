class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
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

        int k = 0;
        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {

                nums[i] = evens[k++];
                // k++;
            }
            else
            {

                nums[i] = odds[j++];
                // j++;
            }
        }

        odds.clear();
        evens.clear();

        odds.shrink_to_fit();
        evens.shrink_to_fit();

        return nums;
    }
};