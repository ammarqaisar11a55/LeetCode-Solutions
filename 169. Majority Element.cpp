class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        unordered_map<int, int> Oc;

        for (auto x : nums)
        {
            Oc[x]++;
        }

        int ANS = 0;
        int temp = 0;

        for (auto x : Oc)
        {
            if (x.second > temp)
            {
                ANS = x.first;
                temp = x.second;
            }
        }

        return ANS;
    }
};