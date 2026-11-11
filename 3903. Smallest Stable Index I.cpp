class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>suffixMin(nums.size());
        
        suffixMin[nums.size() - 1] = nums[nums.size() - 1];
        
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }
        
        int prefixMax = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++)
        {
            prefixMax = max(prefixMax, nums[i]);
            
            
            if(prefixMax - suffixMin[i] <=k)
            {
                return i;
            }
            
        }
        
        return -1;
    }
};
