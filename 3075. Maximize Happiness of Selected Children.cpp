class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {

        long long ans = 0;

        sort(happiness.rbegin(), happiness.rend());

        int dec = 0;

        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - dec > 0)
                ans += happiness[i] - dec;
            dec++;
        }

        return ans;
    }
};