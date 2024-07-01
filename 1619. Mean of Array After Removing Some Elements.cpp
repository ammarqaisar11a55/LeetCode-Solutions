class Solution
{
public:
    double trimMean(vector<int> &arr)
    {

        double from_to = 5.00 * arr.size() / 100.0;
        sort(arr.begin(), arr.end());
        int sum = 0;
        int count = 0;

        for (int i = from_to; i < arr.size() - from_to; i++)
        {
            sum += arr[i];
        }

        return (double)sum / (arr.size() - (2 * from_to));
    }
};