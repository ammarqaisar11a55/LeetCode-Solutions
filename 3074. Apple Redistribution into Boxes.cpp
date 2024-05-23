class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
    int total_apples = 0;
    int total_capacity = 0;
    int n_boxes = 0;

    for (int i = 0; i < apple.size(); i++)
    {
        total_apples = total_apples + apple[i];
    }

    sort(capacity.rbegin(), capacity.rend());

    for (int i = 0; i < capacity.size(); i++)
    {
        total_capacity = total_capacity + capacity[i];
        n_boxes++;
        if(total_capacity>=total_apples){
            return n_boxes;
        }
    }
    
    return 1;
        
    }
};