class Solution {
public:
    bool play(int& x, int& y) {
        int total = 115;

        while (total - 75 >= 0 && x > 0) {
            total -= 75;
            x--;
        }

        while (total - 10 >= 0 && y > 0) {
            total -= 10;
            y--;
        }

        return total == 0 ? true : false;
    }

    string winningPlayer(int x, int y) {
        while (true) {
            if (play(x, y) == false) {
                return "Bob";
            }

            if (play(x, y) == false) {
                return "Alice";
            }
        }
        return "";
    }
};
