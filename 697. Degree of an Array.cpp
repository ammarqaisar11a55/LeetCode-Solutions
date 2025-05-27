class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = INT_MAX;

        unordered_map<int, int> mp;
        int max_freq = INT_MIN;

        for (int i : nums) {
            mp[i]++;
            max_freq = max(max_freq, mp[i]);
        }

        if (max_freq == 1)
            return 1;
        unordered_set<int> max_freq_elements;

        for (auto x : mp) {
            if (x.second == max_freq) {
                max_freq_elements.insert(x.first);
            }
        }

        unordered_map<int, stack<int>> max_freq_elements_first_and_last_pos;

        for (int i = 0; i < nums.size(); i++) {
            if (max_freq_elements.find(nums[i]) != max_freq_elements.end()) {
                if (max_freq_elements_first_and_last_pos.find(nums[i]) ==
                    max_freq_elements_first_and_last_pos.end()) {
                    max_freq_elements_first_and_last_pos[nums[i]].push(i);
                } else {
                    if (max_freq_elements_first_and_last_pos[nums[i]].size() ==
                        1) {
                        max_freq_elements_first_and_last_pos[nums[i]].push(i);
                    } else if (max_freq_elements_first_and_last_pos[nums[i]]
                                   .size() == 2) {
                        max_freq_elements_first_and_last_pos[nums[i]].pop();
                        max_freq_elements_first_and_last_pos[nums[i]].push(i);
                    }
                }
            }
        }

        for (auto x : max_freq_elements_first_and_last_pos) {

            int last_pos = x.second.top();
            x.second.pop();
            int first_pos = x.second.top();

            res = min(res, last_pos - first_pos + 1);
        }

        return res;
    }
};
