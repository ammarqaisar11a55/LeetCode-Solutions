class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {

        bool isHeavy = mass >= 100 ? true : false;
        bool isBulky = (((unsigned long long int)length * (unsigned long long int)width * (unsigned long long int)height)) >= 1e9 || length >= 1e4 || width >= 1e4 || height >= 1e4 || mass >= 1e4 ? true : false;

        if (isHeavy == true && isBulky == true)
        {
            return "Both";
        }

        if (isHeavy == false && isBulky == false)
        {
            return "Neither";
        }

        if (isHeavy == false && isBulky == true)
        {
            return "Bulky";
        }

        return "Heavy";
    }
};