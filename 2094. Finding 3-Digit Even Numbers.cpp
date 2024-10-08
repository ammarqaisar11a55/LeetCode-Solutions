class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {

        vector<int> Ans;

        unordered_map<int, int> Mp;

        for_each(digits.begin(), digits.end(), [&](int v)
                 { Mp[v]++; });

        for (int i = 100; i < 999; i += 2)
        {
            int Temp = i;

            int LastDigit = Temp % 10;
            Temp /= 10;

            int MiddleDigit = Temp % 10;
            Temp /= 10;

            int FirstDigit = Temp;

            bool VALID = true;

            unordered_map<int, int> TempMp;

            TempMp[FirstDigit]++;
            TempMp[MiddleDigit]++;
            TempMp[LastDigit]++;

            for (auto [Digit, Count] : TempMp)
            {
                if (Mp[Digit] < Count)
                {
                    VALID = false;
                    break;
                }
            }

            if (VALID)
                Ans.push_back(i);

            // unordered_set<int> TempSET;

            // TempSET.insert(FirstDigit);
            // TempSET.insert(MiddleDigit);
            // TempSET.insert(LastDigit);

            // if (TempSET.size() == 1)
            // {
            //     int digit = *TempSET.begin();

            //     if (Mp.find(digit) != Mp.end() && Mp[digit] > 2)
            //     {
            //         Ans.push_back(i);
            //     }
            // }
            // else if (TempSET.size() == 2)
            // {
            //     unordered_set<int>::iterator it = TempSET.begin();

            //     int first = *it;
            //     it++;
            //     int second = *it;

            //     if ((Mp[first] >= 1 && Mp[second] >= 2) || (Mp[first] >= 2 && Mp[second] >= 1))
            //     {
            //         Ans.push_back(i);
            //     }
            // }
            // else if (TempSET.size() == 3)
            // {
            //     unordered_set<int>::iterator Beginner = TempSET.begin();

            //     int first = *Beginner;
            //     Beginner++;
            //     int second = *(Beginner);
            //     Beginner++;
            //     int third = *(Beginner);

            //     if (Mp.find(first) != Mp.end() && Mp.find(second) != Mp.end() && Mp.find(third) != Mp.end())
            //     {
            //         if (Mp[first] > 0 && Mp[second] > 0 && Mp[third] > 0)
            //         {
            //             Ans.push_back(i);
            //         }
            //     }
            // }
        }

        return Ans;
    }
};