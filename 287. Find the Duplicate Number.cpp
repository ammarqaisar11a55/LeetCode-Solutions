class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return -1;
    }
};

//************************************************************** */


class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int>N;

        for (int i = 0; i < nums.size(); i++)
        {
            if(N.find(nums[i])!=N.end()){
                return nums[i];
            }else N.insert(nums[i]);
        }

        return 1;
        
    }
};
