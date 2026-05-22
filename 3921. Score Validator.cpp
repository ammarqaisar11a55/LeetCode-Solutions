class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;

        for (int i = 0; i < events.size(); i++) {
            if (events[i] == "1" || events[i] == "WD" || events[i] == "NB") {
                score += 1;
            } else if (events[i] == "2") {
                score += 2;
            } else if (events[i] == "3") {
                score += 3;
            } else if (events[i] == "4") {
                score += 4;
            } else if (events[i] == "6") {
                score += 6;
            } else if (events[i] == "W") {
                counter++;
            }

            if (counter == 10) {
                break;
            }
        }

        return {score, counter};
    }
};