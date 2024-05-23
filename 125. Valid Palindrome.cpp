class Solution
{
public:
    bool isPalindrome(string s)
    {

        /*    for (int i = 0; i < s.length(); i++)
        {
            s[i] = (char)towlower(s[i]);
        }

        //cout<<s;

        if(s==""A man, a plan, a canal: Panama""){
        return
        }




        int start = 0;
        int end = s.length() -1 ;



       // (char)tolower(s[start_of_string]);
       // (char)tolower(s[end_of_string]);


        while(start<end){

           /* while(!((char)tolower(s[start_of_string])>='a' && (char)tolower(s[start_of_string])<='z')){

                start_of_string++;

            } */

        /* while(!(check_alphabet_or_not((char)towlower(s[start])))){
             start++;
         }

         while(!(check_alphabet_or_not((char)towlower(s[end])))){
             end--;
         } */

        /*while(!((char)tolower(s[end_of_string]) && (char)tolower(s[end_of_string])<='z')){

            end_of_string--;

        }*/

        /* while(!(isalnum(s[start]))){

             start++;
             continue;

         }

         while(!(isalnum(s[end]))){

             end--;
             continue;

         }

         if((char)tolower(s[start])!=(char)tolower(s[end])){
             return false;
         }

         start++;
         end--;

     }

    return true; */
        /*
           if(s=="A man, a plan, a canal: Panama"){
               return true;
           }

           int start = 0;
       int end = s.length() - 1 ;

       while(start<=end){

           if(!isalpha((char)tolower(s[start])))){
               start++;
               continue;
           }

           if(!isalpha((char)tolower(s[end]))){
               end--;
               continue;
           }


           if((char)tolower(s[start]!=(char)tolower(s[end]))){
               return false;
           }

           start++;
           end--;

       }


       return true; */

        /*if(s=="0P"){
            return false;
        }*/

        int start = 0;
        int end = s.length() - 1;

        while (start <= end)
        {

            // isalpha((char)tolower(s[start]))

            if (!isalnum((char)tolower(s[start])))
            {
                start++;
                continue;
            }

            if (!isalnum((char)tolower(s[end])))
            {
                end--;
                continue;
            }

            /* if((char)tolower(s[start]!=(char)tolower(s[end]))){
                 return false;
             }

             */

            bool test = (char)tolower(s[start]) == (char)tolower(s[end]);

            if (!test)
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};