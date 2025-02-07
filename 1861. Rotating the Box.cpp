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

/*Optimized Solution*/

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {

        vector<vector<char>> Res(box[0].size(), vector<char>(box.size()));

        for (int i = 0; i < Res.size(); i++)
        {
            for (int j = 0; j < Res[i].size(); j++)
            {
                Res[i][j] = box[box.size() - j - 1][i];
            }
        }

        int total_rows = Res.size();
        int total_cols = Res[0].size();

        for (int i = 0; i < total_cols; i++)
        {
            int Current_Col_Empty_Cell = total_rows - 1;

            for (int j = total_rows - 1; j >= 0; j--)
            {
                if (Res[j][i] == '#')
                {
                    swap(Res[j][i], Res[Current_Col_Empty_Cell--][i]);
                }
                else if (Res[j][i] == '*')
                {
                    Current_Col_Empty_Cell = j - 1;
                }
            }
        }

        return Res;
    }
};