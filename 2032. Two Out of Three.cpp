class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {

        // Adding each element of each vector in set for unique values:

        unordered_set<int> A;

        for (auto x : nums1)
        {
            A.insert(x);
        }

        unordered_set<int> B;

        for (auto x : nums2)
        {
            B.insert(x);
        }

        unordered_set<int> C;

        for (auto x : nums3)
        {
            C.insert(x);
        }

        // Counting:

        unordered_map<int, int> Oc;

        for (auto x = A.begin(); x != A.end(); x++)
        {
            Oc[*x]++;
        }

        for (auto x = B.begin(); x != B.end(); x++)
        {
            Oc[*x]++;
        }

        for (auto x = C.begin(); x != C.end(); x++)
        {
            Oc[*x]++;
        }

        // Answer:

        vector<int> ANS;

        for (auto x : Oc)
        {
            if (x.second > 1)
            {
                ANS.push_back(x.first);
            }
        }

        return ANS;
    }
};