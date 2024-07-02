class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {

        // Seperating distinct intergers of each vector:

        unordered_set<int> N1Unique;

        for (auto x : nums1)
        {
            N1Unique.insert(x);
        }

        unordered_set<int> N2Unique;

        for (auto x : nums2)
        {
            N2Unique.insert(x);
        }

        // Counting occruances:

        unordered_map<int, int> count;

        for (auto x = N1Unique.begin(); x != N1Unique.end(); x++)
        {
            count[*x]++;
        }

        for (auto x = N2Unique.begin(); x != N2Unique.end(); x++)
        {
            count[*x]++;
        }

        int ANS = INT_MAX;

        for (auto x : count)
        {
            if (x.second == 2 && x.first < ANS)
            {
                ANS = x.first;
            }
        }

        if (ANS == INT_MAX)
            return -1;

        return ANS;
    }
};