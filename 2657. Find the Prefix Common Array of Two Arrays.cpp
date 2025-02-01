class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> Res;
        unordered_set<int> Elements_with_Twice_Frequency;
        unordered_map<int, int> Freq;

        for (int i = 0; i < A.size(); i++)
        {
            int A_vector_element = A[i];
            int B_vector_element = B[i];

            Freq[A_vector_element]++;
            Freq[B_vector_element]++;

            if (Freq[A_vector_element] == 2)
            {
                Elements_with_Twice_Frequency.insert(A_vector_element);
            }

            if (Freq[B_vector_element] == 2)
            {
                Elements_with_Twice_Frequency.insert(B_vector_element);
            }

            Res.push_back((int)Elements_with_Twice_Frequency.size());
        }

        return Res;
    }
};