class Solution
{
public:
    int largestdigit(int a)
    {
        int Maxi = INT_MIN;

        while (a != 0)
        {
            Maxi = max(Maxi, a % 10);
            a /= 10;
        }

        return Maxi == INT_MIN ? -1 : Maxi;
    }

    int maxSum(vector<int> &nums)
    {

        unordered_map<int, priority_queue<int, vector<int>, less<int>>> mp;

        for (int x : nums)
        {
            int largest = largestdigit(x);

            if (largest != -1)
            {
                mp[largest].push(x);
            }
        }
        int ANS = INT_MIN;

        for (auto x : mp)
        {
            if (x.second.size() > 1)
            {
                int f = x.second.top();
                x.second.pop();
                int s = x.second.top();

                ANS = max(ANS, f + s);
            }
        }

        return ANS == INT_MIN ? -1 : ANS;
    }
};