class Solution
{
public:
    string binaryConversion(string data)
    {
        string ans = "";
        int N = stoi(data);

        while (N != 0)
        {
            ans += (N % 2) + '0';
            N /= 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    //**********************

    string convertDateToBinary(string date)
    {

        string ans;

        string year = (date.substr(0, 4));
        string month = (date.substr(5, 2));
        string day = (date.substr(8, 2));

        return binaryConversion(year) + "-" + binaryConversion(month) + "-" + binaryConversion(day);
    }
};