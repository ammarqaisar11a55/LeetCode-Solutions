class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {

        char SlowestKey = keysPressed[0];
        int LongestTime = releaseTimes[0];

        for (int i = 1; i < releaseTimes.size(); i++)
        {
            int CurrentKeyTime = releaseTimes[i] - releaseTimes[i - 1];

            if (CurrentKeyTime > LongestTime || CurrentKeyTime == LongestTime && keysPressed[i] > SlowestKey)
            {
                LongestTime = CurrentKeyTime;
                SlowestKey = keysPressed[i];
            }
        }

        return SlowestKey;
    }
};