class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = (rows * cols) - 1;
        int mid = (start + end) / 2;

        while (start <= end)
        {

            int current = matrix[mid / cols][mid % cols];

            if (current == target)
            {
                return true;
            }

            if (target > current)
            {
                start = mid + 1;
            }
            else if (target < current)
            {
                end = mid - 1;
            }

            mid = (start + end) / 2;
        }

        return false;
    }
};