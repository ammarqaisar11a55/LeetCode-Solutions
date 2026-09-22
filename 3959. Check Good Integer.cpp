class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0, square_sum = 0;


        while(n>0)
        {
            int digit = n%10;
            digitSum += digit;
            square_sum += (digit*digit);
            n/=10;
        }
        return square_sum - digitSum >= 50 ? true : false;
    }

};
