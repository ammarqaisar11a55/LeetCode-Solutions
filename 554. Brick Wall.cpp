class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long int, int> mp;
        int maxi = INT_MIN;

        for (int i = 0; i < wall.size(); i++) {
            long long int current_sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                current_sum += wall[i][j];

                mp[current_sum]++;
                maxi = max(maxi, mp[current_sum]);
            }
        }

        if (maxi == INT_MIN)
            return wall.size();

        return wall.size() - maxi;
    }
};
