class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while (k--)
        {
            int top = pq.top();
            top *= -1;
            pq.pop();
            pq.push(top);
        }

        int sum = 0;

        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};