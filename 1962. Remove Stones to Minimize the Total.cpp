class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {

        priority_queue<int, vector<int>, less<int>> pq(piles.begin(), piles.end());

        while (k--)
        {
            int temp = pq.top();
            pq.pop();
            temp -= floor(temp / 2);
            pq.push(temp);
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