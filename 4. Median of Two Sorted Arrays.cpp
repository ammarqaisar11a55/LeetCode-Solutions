class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int i = 0;
        int j = 0;
        int k = 0;

        vector<int> Merged(nums1.size() + nums2.size(), 0);

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                Merged[k++] = nums1[i++];
            }
            else
                Merged[k++] = nums2[j++];
        }

        while (i < nums1.size())
        {
            Merged[k++] = nums1[i++];
        }

        while (j < nums2.size())
        {
            Merged[k++] = nums2[j++];
        }

        return Merged.size() % 2 == 0 ? ((Merged[Merged.size() / 2] + Merged[Merged.size() / 2 - 1]) / 2.0) : Merged[Merged.size() / 2.0];
    }
};