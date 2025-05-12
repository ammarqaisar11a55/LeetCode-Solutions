class Solution {
public:
    int minChanges(int n, int k) {
        vector<int> nb, kb;

        while (n > 0) {
            nb.push_back(n % 2);
            n /= 2;
        }

        while (k > 0) {
            kb.push_back(k % 2);
            k /= 2;
        }

        while (nb.size() < kb.size()) {
            nb.push_back(0);
        }

        while (kb.size() < nb.size()) {
            kb.push_back(0);
        }

        reverse(kb.begin(), kb.end());
        reverse(nb.begin(), nb.end());

        int res = 0;

        for (int i = 0; i < nb.size(); i++) {
            if (nb[i] != kb[i]) {
                if (nb[i] == 1) {
                    res++;
                } else
                    return -1;
            }
        }

        return res;
    }
};
