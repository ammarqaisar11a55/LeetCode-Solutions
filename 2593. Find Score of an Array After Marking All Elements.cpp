class Solution
{
public:
    long long findScore(vector<int> &nums)
    {

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> Elements_Indices;
        unordered_map<int, bool> Visited_Indices;
        long long score = 0;

        vector<int> Temp = nums;

        for (int i = 0; i < nums.size(); i++)
        {
            Elements_Indices[nums[i]].push(i);
        }

        sort(Temp.begin(), Temp.end());

        for (int i = 0; i < Temp.size(); i++)
        {
            int smallest_element = Temp[i];
            int smallest_index = Elements_Indices[Temp[i]].top();
            Elements_Indices[smallest_element].pop();

            if (Visited_Indices[smallest_index])
                continue;

            score += smallest_element;
            Visited_Indices[smallest_index] = true;

            // Left of Index

            if (smallest_index - 1 >= 0)
            {
                Visited_Indices[smallest_index - 1] = true;
            }

            // Right of Index

            if (smallest_index + 1 < Temp.size())
            {
                Visited_Indices[smallest_index + 1] = true;
            }
        }

        return score;
    }
};