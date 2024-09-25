class Solution
{
public:
    int similarPairs(vector<string> &words)
    {

        int count = 0;

        for (int i = 0; i < words.size(); i++)
        {
            set<char> Temp1(words[i].begin(), words[i].end());

            for (int k = i + 1; k < words.size(); k++)
            {
                set<char> Temp2(words[k].begin(), words[k].end());
                if (Temp1 == Temp2)
                    count++;
            }
        }

        return count;
    }
};