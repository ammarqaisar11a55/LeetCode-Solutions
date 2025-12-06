class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int left = *min_element(nums.begin(),nums.end());
    int right = *max_element(nums.begin(),nums.end());

    unordered_set<int>avail(nums.begin(),nums.end());

    vector<int>res;

    for(int i = left + 1; i < right; i++)
    {
        if(avail.find(i)==avail.end())
        {
            res.push_back(i);
        }
    }

    return res;
    }
};
