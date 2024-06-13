class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {

        int answer = 0;
        int negations = 0;

        for (int i = 0; i < batteryPercentages.size(); i++)
        {
            if (batteryPercentages[i] - negations > 0)
            {
                answer++;
                negations++;
            }
        }

        return answer;
    }
};