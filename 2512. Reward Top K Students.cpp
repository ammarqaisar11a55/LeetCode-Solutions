class Solution
{
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {

        unordered_set<string> Negative_Feedbacks(negative_feedback.begin(), negative_feedback.end());
        unordered_set<string> Positive_Feedbacks(positive_feedback.begin(), positive_feedback.end());

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        priority_queue<int, vector<int>, less<int>> Highest_Points;

        for (int i = 0; i < report.size(); i++)
        {
            int points = 0;
            string single;

            for (int j = 0; j < report[i].length(); j++)
            {
                if (report[i][j] != ' ')
                {
                    single.push_back(report[i][j]);
                }
                else if (single.empty() == false)
                {
                    points += Positive_Feedbacks.find(single) != Positive_Feedbacks.end() ? 3 : 0;
                    points -= Negative_Feedbacks.find(single) != Negative_Feedbacks.end() ? 1 : 0;
                    single.clear();
                }
            }

            if (single.empty() == false)
            {
                points += Positive_Feedbacks.find(single) != Positive_Feedbacks.end() ? 3 : 0;
                points -= Negative_Feedbacks.find(single) != Negative_Feedbacks.end() ? 1 : 0;
                single.clear();
            }

            mp[points].push(student_id[i]);
            Highest_Points.push(points);
        }

        vector<int> Ans;
        int TopK = k;

        while (k--)
        {
            int TopPoints = Highest_Points.top();
            Highest_Points.pop();

            while (!mp[TopPoints].empty())
            {
                if (Ans.size() != TopK)
                    Ans.push_back(mp[TopPoints].top());
                else
                    break;
                mp[TopPoints].pop();
            }

            if (Ans.size() >= TopK)
                break;
        }

        return Ans;
    }
};