class Solution
{
public:
    vector<string> stringSequence(string target)
    {
        vector<string> Ans;
        string temp = "";
        string Alphabets = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < target.length(); i++)
        {
            char Required_Character = target[i];

            for (int j = 0; j < Alphabets.length(); j++)
            {
                if (Required_Character != Alphabets[j])
                {
                    Ans.push_back(temp + Alphabets[j]);
                }
                else
                {
                    temp.push_back(Alphabets[j]);
                    Ans.push_back(temp);
                    break;
                }
            }
        }

        return Ans;
    }
};