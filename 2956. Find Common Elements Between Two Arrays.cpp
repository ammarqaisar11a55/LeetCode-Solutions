class Solution
{
public:
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ANS1;
        vector<int> ANS2;

        // Answer 1:

        int count1 = 0;

        unordered_set<int> N2;

        for (auto x : nums2)
        {
            N2.insert(x);
        }

        for (auto x : nums1)
        {
            if (N2.find(x) != N2.end())
            {
                count1++;
            }
        }

        // Answer 2:

        int count2 = 0;

        unordered_set<int> N1;

        for (auto x : nums1)
        {
            N1.insert(x);
        }

        for (auto x : nums2)
        {
            if (N1.find(x) != N1.end())
            {
                count2++;
            }
        }

        return {count1, count2};
    }
};