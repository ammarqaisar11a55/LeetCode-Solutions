class NumArray
{
public:
    vector<int> N;

    NumArray(vector<int> &nums)
    {
        N = nums;
    }

    int sumRange(int left, int right)
    {

        int sum = 0;

        for (int i = left; i <= right; i++)
        {
            sum += N[i];
        }

        return sum;
    }
};

/*Optimized Approach:*/

class NumArray {
public:
    vector<int> Tree;
    int Original_size;

    NumArray(vector<int>& nums) {
        Original_size = nums.size();
        Tree.resize(4 * Original_size);
        Build_Tree(nums, 0, 0, Original_size - 1);
    }

    int sumRange(int left, int right) {
        return Answer_to_Query(0, 0, Original_size - 1, left, right);
    }

    /*Segment Tree*/

    void Build_Tree(vector<int>& Nums, int Current_Index, int left, int right) {
        if (left == right) {
            Tree[Current_Index] = Nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        Build_Tree(Nums, 2 * Current_Index + 1, left, mid);
        Build_Tree(Nums, 2 * Current_Index + 2, mid + 1, right);

        /*This is just example of range sum relation, it can be changed such
        according to the question asked.*/

        Tree[Current_Index] =
            Tree[2 * Current_Index + 1] + Tree[2 * Current_Index + 2];
    }

    int Answer_to_Query(int current_index, int left, int right,
                        int target_start, int target_end) {

        if (right < target_start || left > target_end)
            return 0;

        if (left >= target_start && right <= target_end) {
            return Tree[current_index];
        }

        int mid = left + (right - left) / 2;

        /*This is just example of range sum relation, it can be changed such
        according to the question asked.*/
        return Answer_to_Query(2 * current_index + 1, left, mid, target_start,
                               target_end) +
               Answer_to_Query(2 * current_index + 2, mid + 1, right,
                               target_start, target_end);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
