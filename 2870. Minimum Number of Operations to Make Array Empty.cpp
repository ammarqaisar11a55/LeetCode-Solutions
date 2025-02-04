class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int c : nums)
            mp[c]++;

        int operations = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto x : mp)
            pq.push(x.second);

        while (!pq.empty())
        {
            int Top = pq.top();
            pq.pop();

            if (Top == 1)
                return -1;

            if (Top % 3 == 0)
            {
                operations += 1;
                Top -= 3;
            }
            else if (Top % 2 == 0)
            {
                operations += 1;
                Top -= 2;
            }
            else
            {
                operations += 1;
                Top -= 3;
            }

            if (Top > 0)
            {
                pq.push(Top);
            }
        }

        return operations;
    }
};