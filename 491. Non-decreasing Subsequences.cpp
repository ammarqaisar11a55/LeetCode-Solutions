class Solution {
public:
    void Solve(int index, vector<int>& nums, vector<int> Current_SubSeq,
               vector<vector<int>>& Res) {
        if (Current_SubSeq.size() >= 2)
            Res.push_back(Current_SubSeq);

        if (index >= nums.size())
            return;

        unordered_set<int> st;

        for (int i = index; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end())
                continue;
            st.insert(nums[i]);

            if (Current_SubSeq.empty()) {
                Current_SubSeq.push_back(nums[i]);
                Solve(i + 1, nums, Current_SubSeq, Res);
                Current_SubSeq.pop_back();
            } else if (Current_SubSeq.back() <= nums[i]) {
                Current_SubSeq.push_back(nums[i]);
                Solve(i + 1, nums, Current_SubSeq, Res);
                Current_SubSeq.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> Res;
        Solve(0, nums, {}, Res);
        return Res;
    }
};
