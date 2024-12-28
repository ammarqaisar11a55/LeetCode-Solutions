class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {

        unordered_set<int> st(nums.begin(), nums.end());

        if (nums.size() == st.size())
            return 0;

        int Count_Operation = 0;

        reverse(nums.begin(), nums.end());

        st.clear();

        while (!nums.empty())
        {
            if (nums.size() >= 3)
            {
                nums.pop_back();
                nums.pop_back();
                nums.pop_back();
            }
            else if (nums.size() == 2)
            {
                nums.pop_back();
                nums.pop_back();
            }
            else if (nums.size() == 1)
            {
                nums.pop_back();
            }

            Count_Operation++;

            unordered_set<int> Current_elements(nums.begin(), nums.end());

            if (nums.size() == Current_elements.size())
                break;
        }

        return Count_Operation;
    }
};