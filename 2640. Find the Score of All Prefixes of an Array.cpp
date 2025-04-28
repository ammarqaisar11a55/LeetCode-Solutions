class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res(nums.size());
        int Maxi_Value = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            Maxi_Value = max(nums[i], Maxi_Value);

            if (i == 0) {
                res[i] = Maxi_Value + nums[i];
            } else {
                res[i] = Maxi_Value + nums[i] + res[i - 1];
            }
        }

        return res;
    }
};
