class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;

        if (k == 0)
            return int(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            auto upper_bound_index =
                upper_bound(nums.begin(), nums.end(), nums[i]);

            int in = upper_bound_index - nums.begin();

            if ((int)nums.size() - in >= k)
                res++;
        }

        return res;
    }
};
