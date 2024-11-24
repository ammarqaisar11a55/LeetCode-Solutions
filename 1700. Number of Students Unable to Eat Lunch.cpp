class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {

        queue<int> Students_In_Queue;
        stack<int> Sandwiches_In_Stack;

        for (int i = 0; i < students.size(); i++)
        {
            Students_In_Queue.push(students[i]);
            Sandwiches_In_Stack.push(sandwiches.back());
            sandwiches.pop_back();
        }

        int Last_Served = 0;
        while (!Students_In_Queue.empty() && Last_Served < Students_In_Queue.size())
        {
            if (Students_In_Queue.front() == Sandwiches_In_Stack.top())
            {
                Students_In_Queue.pop();
                Sandwiches_In_Stack.pop();
                Last_Served = 0;
            }
            else
            {
                Students_In_Queue.push(Students_In_Queue.front());
                Students_In_Queue.pop();
                Last_Served++;
            }
        }

        return Students_In_Queue.size();
    }
};