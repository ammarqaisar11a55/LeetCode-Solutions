class Solution {
public:
    int calculate_fairness(vector<int>& Childs) {
        return *max_element(Childs.begin(), Childs.end());
    }

    void Solve(int current_bag, vector<int>& cookies, vector<int>& Childs,
               int& Res) {
        if (current_bag >= cookies.size()) {
            Res = min(Res, calculate_fairness(Childs));
            return;
        }

        for (int i = 0; i < Childs.size(); i++) {

            Childs[i] += cookies[current_bag];

            // PrintVector(Childs);

            Solve(current_bag + 1, cookies, Childs, Res);

            Childs[i] -= cookies[current_bag];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> Childs(k, 0);
        int Res = INT_MAX;
        Solve(0, cookies, Childs, Res);
        return Res;
    }
};
