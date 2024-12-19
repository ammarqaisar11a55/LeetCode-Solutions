class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool Found_zero_in_First_Row = false;
        bool Found_zero_in_First_Col = false;

        // Fist Row Check
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] == 0)
            {
                Found_zero_in_First_Row = true;
                break;
            }
        }

        // First Col
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                Found_zero_in_First_Col = true;
                break;
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[i].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (Found_zero_in_First_Row)
        {
            for (int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (Found_zero_in_First_Col)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};