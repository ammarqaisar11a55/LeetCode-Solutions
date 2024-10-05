class Solution
{
public:
    int Mod = 1e9 + 7;

    int maximumProduct(vector<int> &nums, int k)
    {

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while (k--)
        {
            int top = pq.top();
            pq.pop();
            top++;
            pq.push(top);
        }

        long long Product = 1;

        while (!pq.empty())
        {
            Product = (Product * pq.top()) % Mod;
            pq.pop();
        }

        return Product;
    }
};