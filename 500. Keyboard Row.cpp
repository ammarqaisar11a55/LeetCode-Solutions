class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {

        string first = "qwertyuiop";
        string second = "asdfghjkl";
        string third = "zxcvbnm";

        unordered_set<char> FirstRow;
        unordered_set<char> SecondRow;
        unordered_set<char> ThirdRow;

        for (char x : first)
        {
            FirstRow.insert(x);
        }

        for (char x : second)
        {
            SecondRow.insert(x);
        }

        for (char x : third)
        {
            ThirdRow.insert(x);
        }

        vector<string> Ans;

        for (int i = 0; i < words.size(); i++)
        {
            int count = 0;

            // First Row:
            for (int j = 0; j < words[i].length(); j++)
            {
                if (FirstRow.find(tolower(words[i][j])) != FirstRow.end())
                    count++;
            }

            if (count == words[i].length())
            {
                Ans.push_back(words[i]);
                continue;
            }
            else if (count > 0)
            {
                count = 0;
                continue;
            }

            // Second Row:
            for (int j = 0; j < words[i].length(); j++)
            {
                if (SecondRow.find(tolower(words[i][j])) != SecondRow.end())
                    count++;
            }

            if (count == words[i].length())
            {
                Ans.push_back(words[i]);
                continue;
            }
            else if (count > 0)
            {
                continue;
                count = 0;
            }

            // Third Row:
            for (int j = 0; j < words[i].length(); j++)
            {
                if (ThirdRow.find(tolower(words[i][j])) != ThirdRow.end())
                    count++;
            }

            if (count == words[i].length())
            {
                Ans.push_back(words[i]);
                continue;
            }
        }

        return Ans;
    }
};