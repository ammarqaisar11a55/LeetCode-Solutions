class Solution
{
public:
    int countDistinctIntegers(vector<int> &nums)
    {

        vector<int> Rev;
        for (int i = 0; i < nums.size(); i++)
        {
            Rev.push_back(rev(nums[i]));
        }

        unordered_set<int> ANS;

        for (int i = 0; i < nums.size(); i++)
        {
            ANS.insert(nums[i]);
            ANS.insert(Rev[i]);
        }

        return ANS.size();
    }

    int rev(int x)
    {
        string R = to_string(x);

        if (R.length() > 1)
            reverse(R.begin(), R.end());

        return stoi(R);
    }
};