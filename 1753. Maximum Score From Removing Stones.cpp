class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {

        priority_queue<int, vector<int>, less<int>> pq;

        pq.push(a);
        pq.push(b);
        pq.push(c);

        int score = 0;

        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();

            int y = -1;

            if (pq.top() > 0)
            {
                y = pq.top();
                pq.pop();
            }
            else
            {
                break;
            }

            score++;

            x--;
            y--;

            if (x > 0)
                pq.push(x);

            if (y > 0)
                pq.push(y);
        }

        return score;
    }
};