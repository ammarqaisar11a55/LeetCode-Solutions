class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {

        long long sum = 0;
        priority_queue<int, vector<int>, less<int>> pq(nums.begin(), nums.end());

        while (k--)
        {
            int t = pq.top();
            sum += t;
            pq.pop();
            t = ceil(double(t / 3.0));
            pq.push(t);
        }

        return sum;
    }
};