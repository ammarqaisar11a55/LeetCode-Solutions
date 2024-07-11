class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {

        int size = nums.size();
        vector<int> Left(size);
        vector<int> Right(size);

        Left[0] = 1;

        for (int i = 1; i < size; i++)
        {
            Left[i] = Left[i - 1] * nums[i - 1];
        }

        Right[size - 1] = 1;

        for (int i = size - 2; i >= 0; i--)
        {
            Right[i] = Right[i + 1] * nums[i + 1];
        }

        vector<int> ANS;

        for (int i = 0; i < size; i++)
        {
            ANS.push_back(Right[i] * Left[i]);
        }

        return ANS;
    }
};