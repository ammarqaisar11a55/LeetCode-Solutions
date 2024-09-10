class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {

        map<int, int> Accumulation;

        for (int i = 0; i < nums1.size(); i++)
        {
            Accumulation[nums1[i][0]] = nums1[i][1];
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            if (Accumulation.find(nums2[i][0]) != Accumulation.end())
            {
                Accumulation[nums2[i][0]] += nums2[i][1];
            }
            else
            {
                Accumulation[nums2[i][0]] = nums2[i][1];
            }
        }

        vector<vector<int>> Ans;

        for (auto x : Accumulation)
        {
            Ans.push_back({x.first, x.second});
        }

        return Ans;
    }
};