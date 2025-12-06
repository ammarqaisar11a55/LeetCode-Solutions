class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> avail(arr.begin(), arr.end());
        int res = 0;

        for (int i = 1;; i++) {
            if (avail.find(i) == avail.end()) {
                k--;
                if (k == 0) {
                    res = i;
                    break;
                }
            }
        }

        return res;
    }
};
