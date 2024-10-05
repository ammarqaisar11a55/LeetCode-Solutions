class Solution
{
public:
    int largestInteger(int num)
    {

        priority_queue<int, vector<int>, less<int>> Even, Odd;
        string NUM = to_string(num);

        while (num != 0)
        {
            if ((num % 10) % 2 == 0)
            {
                Even.push(num % 10);
            }
            else
                Odd.push(num % 10);

            num /= 10;
        }

        string ans;

        for (int i = 0; i < NUM.length(); i++)
        {
            int digit = NUM[i] - '0';

            if (digit % 2 == 0)
            {
                ans += to_string(Even.top());
                Even.pop();
            }
            else
            {
                ans += to_string(Odd.top());
                Odd.pop();
            }
        }

        return stoi(ans);
    }
};