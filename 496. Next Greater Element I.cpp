class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        vector<int> ANS;

        for (int i = 0; i < nums1.size(); i++)
        {
            bool found = false;
            int index = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    index = j;
                    found = true;
                    break;
                }
            }

            if (found)
            {
                bool greater = false;
                int greator_index = -1;

                for (int k = index + 1; k < nums2.size(); k++)
                {
                    if (nums2[k] > nums1[i])
                    {
                        greater = true;
                        greator_index = k;
                        break;
                    }
                }

                if (greater)
                {
                    ANS.push_back(nums2[greator_index]);
                }
                else
                    ANS.push_back(-1);
            }
        }

        return ANS;
    }
};