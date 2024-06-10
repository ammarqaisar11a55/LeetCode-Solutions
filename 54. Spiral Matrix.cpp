class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        vector<int> answer;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int count = 0;
        int total_elements = rows * cols;

        int firstrow = 0;
        int firstcol = 0;
        int lastrow = rows - 1;
        int lastcol = cols - 1;

        while (count < total_elements)
        {
            // First Row
            for (int i = firstcol; count < total_elements && i <= lastcol; i++)
            {
                answer.push_back(matrix[firstrow][i]);
                count++;
            }
            firstrow++;

            // Last Col
            for (int i = firstrow; count < total_elements && i <= lastrow; i++)
            {
                answer.push_back(matrix[i][lastcol]);
                count++;
            }
            lastcol--;

            // Last Row
            for (int i = lastcol; count < total_elements && i >= firstcol; i--)
            {
                answer.push_back(matrix[lastrow][i]);
                count++;
            }
            lastrow--;

            // First Col
            for (int i = lastrow; count < total_elements && i >= firstrow; i--)
            {
                answer.push_back(matrix[i][firstcol]);
                count++;
            }
            firstcol++;
        }

        return answer;
    }
};