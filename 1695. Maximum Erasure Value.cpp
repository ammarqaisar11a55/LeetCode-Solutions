class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, sum = 0, res = 0;
        unordered_set<int> unique_window_elements;

        while (r < nums.size()) {
            if (unique_window_elements.find(nums[r]) ==
                unique_window_elements.end()) {
                sum += nums[r];
                res = max(res, sum);
                unique_window_elements.insert(nums[r]);
                r++;

                // cout<<"Left: "<<l<<" Right: "<<r<<endl;
            } else {
                // res = max(res, sum);

                while (unique_window_elements.find(nums[r]) !=
                       unique_window_elements.end()) {
                    unique_window_elements.erase(nums[l]);
                    sum -= nums[l];
                    l++;
                    // cout<<"Left: "<<l<<" Right: "<<r<<endl;
                }
            }
        }

        return res;
    }
};
