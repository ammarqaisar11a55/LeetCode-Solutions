class Solution
{
public:
    int halveArray(vector<int> &nums)
    {

        int Counts = 0;
        priority_queue<double, vector<double>, less<double>> pq(nums.begin(), nums.end());
        double NormalSum = accumulate(nums.begin(), nums.end(), 0.0);
        double NEWSUM = NormalSum;

        while (NEWSUM > NormalSum / 2.0)
        {
            double Top = pq.top() / 2.0;
            pq.pop();

            NEWSUM -= Top;
            pq.push(Top);

            Counts++;
        }

        return Counts;
    }
};