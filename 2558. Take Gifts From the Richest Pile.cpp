class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {

        priority_queue<int, vector<int>, less<int>> q(gifts.begin(), gifts.end());

        while (k--)
        {
            int t = q.top();
            q.pop();
            q.push(sqrt(t));
        }

        long long sum = 0;

        while (!q.empty())
        {
            sum += q.top();
            q.pop();
        }

        return sum;
    }
};