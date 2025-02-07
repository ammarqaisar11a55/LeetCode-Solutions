/*Brute Force:*/


class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        vector<vector<char>> Res(box[0].size(), vector<char>(box.size()));

        while (true)
        {
            int Changes = 0;

            for (int i = box.size() - 1; i >= 0; i--)
            {
                for (int j = box[i].size() - 1; j >= 1; j--)
                {
                    if (box[i][j] == '.')
                    {
                        if (box[i][j - 1] == '#')
                        {
                            Changes++;
                            swap(box[i][j], box[i][j - 1]);
                        }
                    }
                }
            }

            if (Changes == 0)
                break;
        }

        for (int i = 0; i < Res.size(); i++)
        {
            for (int j = 0; j < Res[i].size(); j++)
            {
                Res[i][j] = box[box.size() - j - 1][i];
            }
        }

        return Res;
    }
};