class Solution
{
public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {

        vector<string> words_with_occ_one_in_words1;

        for (int i = 0; i < words1.size(); i++)
        {
            int count = 1;
            for (int j = 0; j < words1.size(); j++)
            {
                if (words1[i] == words1[j] && i != j)
                {
                    count++;
                }
            }
            if (count == 1)
            {
                words_with_occ_one_in_words1.push_back(words1[i]);
            }
        }

        vector<string> words_with_occ_one_in_words2;

        for (int i = 0; i < words2.size(); i++)
        {
            int count = 1;
            for (int j = 0; j < words2.size(); j++)
            {
                if (words2[i] == words2[j] && i != j)
                {
                    count++;
                }
            }
            if (count == 1)
            {
                words_with_occ_one_in_words2.push_back(words2[i]);
            }
        }

        int ans = 0;

        for (int i = 0; i < words_with_occ_one_in_words1.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < words_with_occ_one_in_words2.size(); j++)
            {
                if (words_with_occ_one_in_words1[i] == words_with_occ_one_in_words2[j])
                {
                    count++;
                }
            }
            if (count == 1)
            {
                ans++;
            }
        }

        return ans;
    }
};