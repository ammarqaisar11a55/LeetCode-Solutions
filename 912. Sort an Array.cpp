class Solution
{
public:
    void Merge(vector<int> &nums, int s, int e)
    {
        int mid = s + (e - s) / 2;

        int length1 = mid - s + 1;
        int length2 = e - mid;

        int *first = new int[length1];
        int *second = new int[length2];

        // Copying First Half:
        int MainArray = s;

        for (int i = 0; i < length1; i++)
            first[i] = nums[MainArray++];

        // Copying Second Half:
        MainArray = mid + 1;

        for (int i = 0; i < length2; i++)
            second[i] = nums[MainArray++];

        // Merge 2 Sorted Half Arrays:
        int index1 = 0;
        int index2 = 0;
        MainArray = s;

        while (index1 < length1 && index2 < length2)
        {
            if (first[index1] < second[index2])
            {
                nums[MainArray++] = first[index1++];
            }
            else
            {
                nums[MainArray++] = second[index2++];
            }
        }

        while (index1 < length1)
        {
            nums[MainArray++] = first[index1++];
        }

        while (index2 < length2)
        {
            nums[MainArray++] = second[index2++];
        }

        delete[] first;
        delete[] second;
    }

    void MergeSort(vector<int> &nums, int s, int e)
    {
        if (s >= e)
            return;

        // Mid of the array:
        int mid = s + (e - s) / 2;

        // Left Part:
        MergeSort(nums, s, mid);

        // Right Part:
        MergeSort(nums, mid + 1, e);

        // Merge Left & Right:
        Merge(nums, s, e);
    }

    //*******************************************
    vector<int> sortArray(vector<int> &nums)
    {

        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};