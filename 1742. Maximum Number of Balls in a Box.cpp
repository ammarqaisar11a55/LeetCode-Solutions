class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {

        unordered_map<int, int> BoxesAndBalls;

        int MaxBalls = INT_MIN;

        for (int i = lowLimit; i <= highLimit; i++)
        {
            string boxno = to_string(i);
            int sum = 0;

            for (char c : boxno)
                sum += c - '0';

            BoxesAndBalls[sum]++;

            MaxBalls = max(MaxBalls, BoxesAndBalls[sum]);
        }

        return MaxBalls;
    }
};