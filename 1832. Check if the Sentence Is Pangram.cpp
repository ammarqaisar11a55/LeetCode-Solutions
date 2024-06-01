class Solution
{
public:
    bool checkIfPangram(string sentence)
    {

        if (sentence.length() < 26)
        {
            return false;
        }

        string atz = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < sentence.length(); i++)
        {
            for (int j = 0; j < atz.length(); j++)
            {
                if (atz[j] == sentence[i])
                {
                    atz.erase(atz.begin() + j);
                }
            }
        }

        if (atz.length() == 0)
        {
            return true;
        }
        else
            return false;
    }
};