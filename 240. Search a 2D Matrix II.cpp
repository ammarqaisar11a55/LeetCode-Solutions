class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int TotalRows = matrix.size();
        int TotalCols = matrix[0].size();

        int RowIndex = 0;
        int ColIndex = TotalCols - 1;

        while (RowIndex < TotalRows && ColIndex >= 0)
        {
            if (matrix[RowIndex][ColIndex] == target)
                return true;

            if (target > matrix[RowIndex][ColIndex])
            {
                RowIndex++;
            }
            else if (target < matrix[RowIndex][ColIndex])
            {
                ColIndex--;
            }
        }

        return false;
    }
};