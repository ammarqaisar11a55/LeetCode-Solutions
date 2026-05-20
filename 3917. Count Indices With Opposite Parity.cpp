class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
    int odd = 0, even = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i == nums.size() - 1)
        {
            res[i] = 0;

            if (nums[i] & 1)
            {
                odd++;
            }
            else
            {
                even++;
            }

            continue;
        }



        if(nums[i]&1)
        {
            res[i] = even;
            odd++;
        }
        else
        {
            res[i] = odd;
            even++;
        }
    }

    return res;
    }
};