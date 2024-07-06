class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> Evens;

        for (auto x : nums)
        {
            if (x % 2 == 0)
                Evens[x]++;
        }

        if (Evens.size() == 0)
            return -1;

        int max = 0;
        int min = INT_MAX;

        for (auto x : Evens)
            if (x.second > max)
                max = x.second;

        for (auto x : Evens)
            if (x.second == max && x.first < min)
                min = x.first;

        return min;
    }
};