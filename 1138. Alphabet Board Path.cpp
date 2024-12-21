class Solution
{
public:
    string alphabetBoardPath(string target)
    {
        unordered_map<char, pair<int, int>> Positions;

        for (int i = 0; i < 26; i++)
        {
            Positions['a' + i] = {i / 5, i % 5};
        }

        int Current_Row = 0;
        int CurrentCol = 0;
        string res;

        for (int i = 0; i < target.length(); i++)
        {

            int TargetRow = Positions[target[i]].first;
            int TargetCol = Positions[target[i]].second;

            if (target[i] == 'z')
            {
                while (CurrentCol > TargetCol)
                {

                    res += "L";
                    CurrentCol--;
                }

                while (Current_Row < TargetRow)
                {

                    res += "D";
                    Current_Row++;
                }
            }
            else
            {
                while (Current_Row > TargetRow)
                {
                    res += "U";
                    Current_Row--;
                }

                while (Current_Row < TargetRow)
                {
                    res += "D";
                    Current_Row++;
                }

                while (CurrentCol > TargetCol)
                {
                    res += "L";
                    CurrentCol--;
                }

                while (CurrentCol < TargetCol)
                {
                    res += "R";
                    CurrentCol++;
                }
            }

            res += "!";
        }

        return res;
    }
};