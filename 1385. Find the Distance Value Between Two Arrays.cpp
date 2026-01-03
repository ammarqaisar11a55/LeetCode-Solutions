class Solution {
public:
    bool isvalid(vector<int> arr, int target, int d) {
        for (auto i : arr) {
            if (abs(i - target) <= d) {
                return false;
            }
        }

        return true;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        sort(arr2.begin(), arr2.end());

        for (int i = 0; i < arr1.size(); i++) {
            if (isvalid(arr2, arr1[i], d)) {
                res++;
            }
        }

        return res;
    }
};