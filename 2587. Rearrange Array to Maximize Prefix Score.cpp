class Solution {
public:
    int maxScore(vector<int>& nums) {

        vector<long long int> p(nums.begin(), nums.end());
        sort(p.rbegin(), p.rend());

        for (int i = 1; i < p.size(); i++) {
            p[i] = p[i] + p[i - 1];
        }

        int res = 0;

        for (long long int i : p)
            if (i > 0)
                res++;

        return res;
    }
};
