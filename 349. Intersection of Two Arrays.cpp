class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> intersection;

        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                // int nums1copy = nums1[i];
                if ((nums1[i] == nums2[j]) && notduplicate(intersection, nums1[i]))
                {
                    intersection.push_back(nums1[i]);
                }
            }
        }

        return intersection;
    }

    bool notduplicate(vector<int> output, int a)
    {

        for (int i = 0; i < output.size(); i++)
        {
            if (output.at(i) == a)
            {
                return false;
            }
        }

        return true;
    }
};