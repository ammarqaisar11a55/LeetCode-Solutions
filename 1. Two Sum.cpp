class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }

        return {};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>Mp;
        
        
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            
            if(Mp.find(diff)!=Mp.end())
            {
                return {i,Mp[diff]};
            }
            
            Mp[nums[i]] = i;
        }
        
        return {};
        
    }
};