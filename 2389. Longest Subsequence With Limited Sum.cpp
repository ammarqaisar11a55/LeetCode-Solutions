class Solution {
public:
    int binary_search(vector<int> prefix, int target_sum) {
        int maxi = 0;

        int s = 0;
        int e = prefix.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (prefix[mid] <= target_sum) {
                maxi = max(maxi, mid + 1);
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return maxi;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            res[i] = binary_search(prefix, queries[i]);
        }

        return res;
    }
};
