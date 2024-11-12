class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {

        vector<vector<int>> Ans;

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        for (vector<int> Point : points)
        {
            double distance = sqrt(Point[0] * Point[0] + Point[1] * Point[1]);

            pq.push({distance, {Point[0], Point[1]}});
        }

        while (k--)
        {
            Ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return Ans;
    }
};