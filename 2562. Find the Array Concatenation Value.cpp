class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {

        long long ans = 0;

        long long s = 0;
        long long e = nums.size() - 1;

        while (s < e)
        {
            string concate = to_string(nums[s++]) + to_string(nums[e--]);
            ans += stoll(concate);
        }

        if (nums.size() % 2 != 0)
            ans += nums[s];

        return ans;
    }
};