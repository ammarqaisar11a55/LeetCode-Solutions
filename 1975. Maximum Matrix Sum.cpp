class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;

        priority_queue<int, vector<int>, greater<int>> positivies, negatives;

        for (vector<int> row : matrix) {
            for (int i : row) {
                if (i > 0) {
                    positivies.push(i);
                } else {
                    negatives.push(i);
                }
            }
        }

        while (true) {
            if (negatives.size() >= 2) {
                positivies.push(-1 * negatives.top());
                negatives.pop();
                positivies.push(-1 * negatives.top());
                negatives.pop();
            } else {
                break;
            }
        }

        if (negatives.empty() == false) {
            int top_element = negatives.top() * -1;
            negatives.pop();

            if (positivies.empty() == false && positivies.top() < top_element) {
                // cout << "NEgative top: " << top_element << " -> Positivie
                // TOp: " << positivies.top() << endl;

                negatives.push(-1 * positivies.top());
                positivies.pop();
                positivies.push(top_element);
                // cout << "NEgative top: " << negatives.top() << " -> Positivie
                // TOp: " << top_element << endl;
            } else {
                negatives.push(top_element * -1);
            }
        }

        cout << "Positives: ";

        while (positivies.empty() == false) {
            cout << positivies.top() << " ";

            res += positivies.top();
            positivies.pop();
        }

        cout << endl << "Negatives: ";

        while (negatives.empty() == false) {
            cout << negatives.top() << " ";
            res += negatives.top();
            negatives.pop();
        }

        cout << endl;

        return res;
    }
};