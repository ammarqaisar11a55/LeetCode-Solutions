class Solution
{
public:
    int distinctAverages(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        unordered_set<float> Ans;

        int s = 0;
        int e = nums.size() - 1;

        while (s < e)
        {
            Ans.insert((nums[s++] + nums[e--]) / 2.0);
        }

        return Ans.size();
    }
};