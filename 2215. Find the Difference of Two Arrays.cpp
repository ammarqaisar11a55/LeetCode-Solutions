class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> answer1;
        vector<int> answer2;

        for (int i = 0; i < nums1.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    found = true;
                    break;
                }
            }
            if (found == false && !IsThere(answer1, nums1[i]))
            {
                answer1.push_back(nums1[i]);
            }
        }

        for (int i = 0; i < nums2.size(); i++)
        {
            bool found = false;
            for (int j = 0; j < nums1.size(); j++)
            {
                if (nums2[i] == nums1[j])
                {
                    found = true;
                    break;
                }
            }
            if (found == false && !IsThere(answer2, nums2[i]))
            {
                answer2.push_back(nums2[i]);
            }
        }

        return {{answer1}, {answer2}};
    }

    bool IsThere(vector<int> ans, int tobesearched)
    {

        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == tobesearched)
            {
                return true;
            }
        }

        return false;
    }
};