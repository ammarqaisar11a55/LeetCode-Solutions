class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {

        vector<int> answer;

        for (int i = 0; i < arr2.size(); i++)
        {

            for (int j = 0; j < arr1.size(); j++)
            {
                if (arr2[i] == arr1[j])
                {
                    answer.push_back(arr1[j]);
                }
            }
        }

        vector<int> not_found_elements;

        for (int i = 0; i < arr1.size(); i++)
        {

            bool not_found = true;
            for (int j = 0; j < arr2.size(); j++)
            {
                if (arr1[i] == arr2[j])
                {
                    not_found = false;
                }
            }

            if (not_found)
            {
                not_found_elements.push_back(arr1[i]);
            }
        }

        sort(not_found_elements.begin(), not_found_elements.end());

        for (int i = 0; i < not_found_elements.size(); i++)
        {
            answer.push_back(not_found_elements[i]);
        }

        return answer;
    }
};