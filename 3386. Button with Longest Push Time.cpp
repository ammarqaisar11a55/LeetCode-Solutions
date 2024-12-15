class Solution
{
public:
    int buttonWithLongestTime(vector<vector<int>> &events)
    {

        int Longest_time = events[0][1];
        int ButtonIndex = events[0][0];

        for (int i = 1; i < events.size(); i++)
        {
            int Current_Button_Time = events[i][1] - events[i - 1][1];
            int Current_Index = events[i][0];

            if (Current_Button_Time > Longest_time)
            {
                Longest_time = Current_Button_Time;
                ButtonIndex = Current_Index;
            }
            else if (Current_Button_Time == Longest_time && Current_Index < ButtonIndex)
            {
                Longest_time = Current_Button_Time;
                ButtonIndex = Current_Index;
            }
        }

        return ButtonIndex;
    }
};