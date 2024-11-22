class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {

        int LaserBeams = 0;
        int Previous_Row = 0;

        for (int i = 0; i < bank.size(); i++)
        {
            int Current_Row_Devices = count(bank[i].begin(), bank[i].end(), '1');

            if (Current_Row_Devices != 0)
            {
                LaserBeams += Previous_Row * Current_Row_Devices;
                Previous_Row = Current_Row_Devices;
            }
        }

        return LaserBeams;
    }
};