class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i = 0;
        int j = 0;

        while (i < nums1.size() && j < nums2.size())
        {

            if (nums1[i] == 0)
            {

                nums1[i] = nums2[j];
                i++;
                j++;
            }
            else
            {

                i++;
            }
        }

        sort(nums1.begin(), nums1.end());
    }
};