class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;
        int res = 0;

        for (vector<int> pair : dominoes) {
            sort(pair.begin(), pair.end());
            res += mp[{pair[0], pair[1]}];
            mp[{pair[0], pair[1]}]++;
        }

        return res;
    }
};