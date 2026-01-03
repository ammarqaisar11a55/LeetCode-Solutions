class Solution
{
public:
    string generateTag(string caption)
    {
        string result;

        result.push_back('#');

        if (caption.back() != ' ')
        {
            caption.push_back(' ');
        }

        int current_word_number = 1;

        for (int i = 0; i < caption.size(); i++)
        {
            if (caption[i] != ' ')
            {
                if (current_word_number == 1)
                {
                    result.push_back(tolower(caption[i++]));

                    while (i < caption.size() && caption[i] != ' ')
                    {
                        result.push_back(tolower(caption[i++]));
                        if (result.size() == 100)
                            return result;
                    }
                }
                else
                {
                    result.push_back(toupper(caption[i++]));

                    while (i < caption.size() && caption[i] != ' ')
                    {
                        result.push_back(tolower(caption[i++]));
                        if (result.size() == 100)
                            return result;
                    }
                }

                current_word_number++;
            }
        }

        return result;
    }
};