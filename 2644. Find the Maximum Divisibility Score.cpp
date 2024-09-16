class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {

        int MaxScore = INT_MIN;
        int Ans = INT_MAX;
        unordered_map<int, int> Mp;

        for (int i = 0; i < divisors.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if ((nums[j] % divisors[i]) == 0)
                    count++;
            }

            Mp[divisors[i]] = count;

            MaxScore = max(MaxScore, count);
        }

        for (auto x : Mp)
        {
            if (x.second == MaxScore)
            {
                Ans = min(Ans, x.first);
            }
        }

        return Ans;
    }
};