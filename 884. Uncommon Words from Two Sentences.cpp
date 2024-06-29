class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {

        vector<string> words;
        string single;

        // Sperating Words from S1 string:

        s1.push_back(' ');

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == ' ')
            {
                words.push_back(single);
                single.clear();
            }
            else
            {
                single.push_back(s1[i]);
            }
        }

        // Sperating Words from S2 string:

        s2.push_back(' ');

        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] == ' ')
            {
                words.push_back(single);
                single.clear();
            }
            else
            {
                single.push_back(s2[i]);
            }
        }

        // Counting Occurances:

        unordered_map<string, int> Oc;

        for (int i = 0; i < words.size(); i++)
        {
            Oc[words[i]]++;
        }

        // Inserting Words with 1 occurance only in ANS:

        vector<string> ANS;

        for (auto x : Oc)
        {
            if (x.second == 1)
                ANS.push_back(x.first);
        }

        return ANS;
    }
};