class Solution
{
public:
    int SumOfDigits(int x)
    {
        int Sum = 0;
        while (x != 0)
        {
            Sum += x % 10;
            x /= 10;
        }

        return Sum;
    }

    int maximumSum(vector<int> &nums)
    {

        unordered_map<int, priority_queue<int, vector<int>, less<int>>> mp;
        int Maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[SumOfDigits(nums[i])].push(nums[i]);
        }

        for (auto x : mp)
        {
            if (x.second.size() >= 2)
            {
                int TempSum = x.second.top();
                x.second.pop();
                TempSum += x.second.top();

                Maxi = max(Maxi, TempSum);
            }
        }

        return Maxi == INT_MIN ? -1 : Maxi;
    }
};