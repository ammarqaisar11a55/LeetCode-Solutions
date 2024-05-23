class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {

        /*vector<int>odd;
        vector<int>even;

        for (int i = 0; i < nums.size() ; i++)
        {
            if(i%2==0){
                even.push_back(nums[i]);
            }else {
                odd.push_back(nums[i]);
            }
        }

        //Arranging Evens and Odds according to given conditions:

        sort(even.begin(),even.end());

        for (int i = 1 ; i < odd.size() ; i++)
        {
            bool swap_flag = false ;

            for (int j = 0; j < odd.size()-i ; j++)
            {
                if(odd[j]<odd[j+1]){
                    swap_flag = true;
                    swap(odd[j],odd[j+1]);
                }
            }

            if(swap_flag==false){

                break;
            }

        }





        //nums.clear();

        int e = 0;
        int o = 0;

        for (int i = 0; i < nums.size() ; i++)
        {
            if(i%2==0){
                nums[i] = even[e];
                e++;
            }else {
                nums[i] = odd[o];
                o++;
            }
        }



        return nums;*/

        vector<int> odd;
        vector<int> even;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                even.push_back(nums[i]);
            }
            else
            {
                odd.push_back(nums[i]);
            }
        }

        // Arranging Evens and Odds according to given conditions:

        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());

        // nums.clear();

        int e = 0;
        int o = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                nums[i] = even[e];
                e++;
            }
            else
            {
                nums[i] = odd[o];
                o++;
            }
        }

        return nums;
    }
};