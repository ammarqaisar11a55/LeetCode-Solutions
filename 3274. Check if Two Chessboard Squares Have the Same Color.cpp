class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {

        bool C1 = (coordinate1[0] + coordinate1[1]) % 2;
        bool C2 = (coordinate2[0] + coordinate2[1]) % 2;

        return C1 == C2 ? true : false;
    }
};