class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {

        // Convserion of Paragraph into Lowercase:

        for (int i = 0; i < paragraph.length(); i++)
        {
            if (isalpha(paragraph[i]))
                paragraph[i] = tolower(paragraph[i]);
        }

        // Inserting Banned Words into hash set in order to reduce time complexity :

        unordered_set<string> Ban_words;

        for (auto x : banned)
        {
            Ban_words.insert(x);
        }

        // Converting Paragraphs into Words & Storing them in Vector:

        string single;
        vector<string> words;
        string special = "'";

        paragraph.push_back(' ');

        for (int i = 0; i < paragraph.length(); i++)
        {
            if (paragraph[i] == ' ' || paragraph[i] == '!' || paragraph[i] == '?' || paragraph[i] == ',' || paragraph[i] == ';' || paragraph[i] == '.' || paragraph[i] == special[0])
            {
                if (!single.empty() && Ban_words.find(single) == Ban_words.end())
                    words.push_back(single);
                single.clear();
            }
            else
                single.push_back(paragraph[i]);
        }

        if (words.size() == 1)
            return words[0];

        // Occurances of each

        unordered_map<string, int> oc;

        for (auto x : words)
        {
            oc[x]++;
        }

        // Searching for ans with most occurances:

        string ans;
        int temp = INT_MIN;

        for (auto x : oc)
        {
            if (x.second > temp)
            {
                temp = x.second;
                ans = x.first;
            }
        }

        return ans;
    }
};