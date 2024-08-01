class Solution
{
public:
    int countSeniors(vector<string> &details)
    {

        int count = 0;

        for (int i = 0; i < details.size(); i++)
        {

            string digits;
            digits.push_back(details[i][11]);
            digits.push_back(details[i][12]);
            int age = stoi(digits);
            if (age > 60)
            {
                count++;
            }
        }

        return count;
    }
};