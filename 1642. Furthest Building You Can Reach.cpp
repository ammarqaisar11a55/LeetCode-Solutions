class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {

        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < heights.size() - 1; i++)
        {
            int JumDifference = heights[i + 1] - heights[i];

            if (JumDifference > 0)
            {
                pq.push(JumDifference);
            }

            if (pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
            }

            if (bricks < 0)
                return i;
        }

        return heights.size() - 1;
    }
};