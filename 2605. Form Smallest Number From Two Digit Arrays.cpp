class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_set<int> S;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < nums1.size(); i++)
        {
            S.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (S.find(nums2[i]) != S.end())
                return nums2[i];
        }

        return min(*min_element(nums1.begin(), nums1.end()) * 10 + *min_element(nums2.begin(), nums2.end()), *min_element(nums2.begin(), nums2.end()) * 10 + *min_element(nums1.begin(), nums1.end()));
    }
};