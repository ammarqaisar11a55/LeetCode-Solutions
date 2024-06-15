class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        
         int in = 0;
         int dec = 0;

         for(int i = 1; i < nums.size(); i++){

             if(nums[i-1] <= nums[i]){
                 dec++;
             }

            if(nums[i-1] >= nums[i]){
                 in++;
             }

         }

         return in == nums.size()-1 || dec == nums.size()-1;
        
        return is_sorted(nums.rbegin(), nums.rend()) || is_sorted(nums.begin(), nums.end());
    }
};