class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long int res = 0;
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>,
                       less<pair<vector<int>, int>>>
            pq;

        for (int i = 0; i < grid.size(); i++) {
            int l = limits[i];

            if (l == 0)
                continue;

            sort(grid[i].rbegin(), grid[i].rend());

            pq.push({grid[i], l});
        }

        while (k-- && pq.empty() == false) {
            pair<vector<int>, int> top_pair = pq.top();
            pq.pop();

            int front_element = top_pair.first[0];
            top_pair.first.erase(top_pair.first.begin());

            top_pair.second--;

            res += front_element;

            if (top_pair.second > 0) {
                pq.push(top_pair);
            }
        }

        return res;
    }
};

//Failed on last test case :( 

//2nd Approach:


class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long int res = 0;

        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>,
                       less<tuple<int, int, int, int>>>
            pq;

        for (int i = 0; i < grid.size(); i++) {
            int l = limits[i];

            if (l == 0)
                continue;

            sort(grid[i].rbegin(), grid[i].rend());

            // Val Row COl Limi;
            pq.push({grid[i][0], i, 0, l});
        }

        while (k-- && pq.empty() == false) {
            auto [val, row, col, l] = pq.top();
            pq.pop();

            res += val;
            l--;

            if (l > 0 && col + 1 < grid[row].size()) {
                pq.push({grid[row][col + 1], row, col + 1, l});
            }
        }

        return res;
    }
};
