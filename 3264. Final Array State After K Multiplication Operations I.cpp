class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        while (k--)
        {
            pair<int, int> temp = pq.top();
            pq.pop();

            temp.first = temp.first * multiplier;

            pq.push(temp);
        }

        while (!pq.empty())
        {
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }

        return nums;
    }
};