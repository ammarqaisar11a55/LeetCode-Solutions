class Solution
{
public:
    int fillCups(vector<int> &amount)
    {

        int ans = 0;

        priority_queue<int, vector<int>, less<int>> pq(amount.begin(), amount.end());

        while (pq.top() != 0)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            a--;
            b--;

            pq.push(a);
            pq.push(b);

            ans++;
        }

        return ans;
    }
};