class Solution
{
public:
    bool isBalanced(string num)
    {

        int oddindices = 0;
        int evenindices = 0;

        for (int i = 0; i < num.length(); i++)
        {
            if (i & 1)
            {
                oddindices += num[i] - '0';
            }
            else
            {
                evenindices += num[i] - '0';
            }
        }

        return oddindices == evenindices ? true : false;
    }
};