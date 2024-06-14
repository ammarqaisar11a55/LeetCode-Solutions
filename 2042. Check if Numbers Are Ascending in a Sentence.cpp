class Solution
{
public:
    bool areNumbersAscending(string s)
    {

        vector<int> nums;

        for (int i = 0; i < s.length(); i++)
        {
            string temp;
            if (isdigit(s[i]))
            {
                while (i < s.length() && isdigit(s[i]))
                {
                    temp += s[i++];
                }
                nums.push_back(stoi(temp));
            }
            temp.clear();
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
                return false;
        }

        return true;
    }
};