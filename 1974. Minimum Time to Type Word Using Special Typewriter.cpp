class Solution
{
public:
    int minTimeToType(string word)
    {
        int Time = 0;
        int Current_Pointer = 0;

        for (int i = 0; i < word.length(); i++)
        {
            int target_character = word[i] - 'a';

            int ClockWise_Seconds = abs(Current_Pointer - target_character);
            int Anti_ClockWise_Seconds = 26 - ClockWise_Seconds;

            Time += min(Anti_ClockWise_Seconds, ClockWise_Seconds);
            Time++;

            Current_Pointer = target_character;
        }

        return Time;
    }
};