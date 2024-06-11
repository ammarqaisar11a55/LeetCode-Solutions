class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {

        vector<string> modifiy;
        string word;

        for (int i = 0; i < strs[0].length(); i++)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                word.push_back(strs[j][i]);
            }
            modifiy.push_back(word);
            word.clear();
        }

        int unsorted = 0;

        for (int i = 0; i < modifiy.size(); i++)
        {
            if (!is_sorted(modifiy[i].begin(), modifiy[i].end()))
            {
                unsorted++;
            }
        }

        return unsorted;
    }
};