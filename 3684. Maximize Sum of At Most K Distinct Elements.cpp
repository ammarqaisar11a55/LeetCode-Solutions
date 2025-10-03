class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        nums = vector<int>(st.begin(), st.end());

        priority_queue<int, vector<int>, less<int>> pq(nums.begin(),
                                                       nums.end());

        vector<int> res;

        while (k-- && pq.empty() == false) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
