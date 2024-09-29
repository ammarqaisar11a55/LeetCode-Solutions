class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {

        priority_queue<unsigned long long int, vector<unsigned long long int>, greater<unsigned long long int>> pq(nums.begin(), nums.end());

        int CountOperations = 0;

        while (!pq.empty() && pq.size() > 1 && pq.top() < k)
        {
            unsigned long long int x = pq.top();
            pq.pop();
            unsigned long long int y = pq.top();
            pq.pop();

            
            pq.push(min(x, y) * 2 + max(x, y));
            CountOperations++;
        }

        return CountOperations;
    }
};