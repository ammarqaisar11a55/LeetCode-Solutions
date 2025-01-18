class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        if (find(words.begin(), words.end(), target) == words.end())
            return -1;

        if (words[startIndex] == target)
            return 0;

        int dis_left_to_right = 0;
        int dis_right_to_left = 0;

        int i = (startIndex + 1 + words.size()) % words.size();
        dis_left_to_right++;

        while (true)
        {
            if (words[i] == target)
            {
                break;
            }
            else
            {
                dis_left_to_right++;
            }

            i = (i + 1) % words.size();
        }

        i = (startIndex - 1 + words.size()) % words.size();
        dis_right_to_left++;

        while (true)
        {
            if (words[i] == target)
            {
                break;
            }
            else
            {
                dis_right_to_left++;
            }

            i = (i - 1 + words.size()) % words.size();
        }

        return min(dis_left_to_right, dis_right_to_left);
    }
};