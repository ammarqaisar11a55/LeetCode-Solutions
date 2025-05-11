class Solution {
public:
    int convertTime(string current, string correct) {
        int current_time_in_mins = stoi(current.substr(0, 2));
        int target_time_in_mins = stoi(correct.substr(0, 2));

        current_time_in_mins = current_time_in_mins * 60;
        target_time_in_mins = target_time_in_mins * 60;

        current_time_in_mins += stoi(current.substr(3, 2));
        target_time_in_mins += stoi(correct.substr(3, 2));

        int res = 0;

        while (current_time_in_mins + 60 <= target_time_in_mins) {
            res++;
            current_time_in_mins += 60;
        }

        while (current_time_in_mins + 15 <= target_time_in_mins) {
            res++;
            current_time_in_mins += 15;
        }

        while (current_time_in_mins + 5 <= target_time_in_mins) {
            res++;
            current_time_in_mins += 5;
        }

        while (current_time_in_mins + 1 <= target_time_in_mins) {
            res++;
            current_time_in_mins += 1;
        }

        return res;
    }
};
