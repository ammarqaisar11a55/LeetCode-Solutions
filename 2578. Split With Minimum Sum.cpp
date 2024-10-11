class Solution
{
public:
    int splitNum(int num)
    {

        int x = 0;
        int y = 0;

        priority_queue<int, vector<int>, greater<int>> pq;

        while (num != 0)
        {
            pq.push(num % 10);
            num /= 10;
        }

        while (!pq.empty())
        {

            if (pq.empty() == false)
                x = x * 10 + pq.top();

            pq.pop();

            if (pq.empty())
                break;

            y = y * 10 + pq.top();

            pq.pop();
        }

        return x + y;
    }
};