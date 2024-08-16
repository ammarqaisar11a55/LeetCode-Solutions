class Solution
{
public:
    string reformatDate(string date)
    {

        string day, month, year;
        date.push_back(' ');
        int word = 0;

        for (int i = 0; i < date.length(); i++)
        {
            if (date[i] != ' ')
            {
                if (word == 0)
                {
                    day += date[i];
                }

                if (word == 1)
                {
                    month += date[i];
                }

                if (word == 2)
                {
                    year += date[i];
                }
            }
            else
            {
                word++;
            }
        }

        day.pop_back();
        day.pop_back();

        unordered_map<string, string> Months;

        Months["Jan"] = "01";
        Months["Feb"] = "02";
        Months["Mar"] = "03";
        Months["Apr"] = "04";
        Months["May"] = "05";
        Months["Jun"] = "06";
        Months["Jul"] = "07";
        Months["Aug"] = "08";
        Months["Sep"] = "09";
        Months["Oct"] = "10";
        Months["Nov"] = "11";
        Months["Dec"] = "12";

        return day.length() == 2 ? year + "-" + Months[month] + "-" + day : year + "-" + Months[month] + "-0" + day;
    }
};