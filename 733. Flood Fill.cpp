class Solution
{
public:
    void DFS(vector<vector<int>> &image, int i, int j, int NewColor, int Previous_Original_Color)
    {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != Previous_Original_Color)
            return;

        int Current_Original_Color = image[i][j];

        image[i][j] = NewColor;

        DFS(image, i, j + 1, NewColor, Current_Original_Color);
        DFS(image, i, j - 1, NewColor, Current_Original_Color);
        DFS(image, i - 1, j, NewColor, Current_Original_Color);
        DFS(image, i + 1, j, NewColor, Current_Original_Color);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        if (image[sr][sc] == color)
            return image;

        DFS(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};