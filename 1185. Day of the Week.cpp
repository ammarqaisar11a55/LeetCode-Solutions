class Solution
{
public:
    string dayOfTheWeek(int day, int month, int year)
    {

        if (month == 1 || month == 2)
        {
            month += 12;
            year--;
        }

        int q = day;
        int m = month;
        int k = year % 100;
        int j = year / 100;

        string days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

        int h = (q + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

        return days[h];
    }
};