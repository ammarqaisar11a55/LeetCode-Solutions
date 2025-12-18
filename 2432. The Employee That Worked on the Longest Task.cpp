class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>>
            time_users;

        int max_time = 0;

        for (int i = 0; i < logs.size(); i++) {
            int user = logs[i][0], time = logs[i][1];

            if (i == 0) {
                max_time = max(max_time, time);
                time_users[time].push(user);
                continue;
            }

            time = logs[i][1] - logs[i - 1][1];
            time_users[time].push(user);

            max_time = max(max_time, time);
        }

        return time_users[max_time].top();
    }
};
