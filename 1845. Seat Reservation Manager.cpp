class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> reserved_seats;

    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            pq.push(i);
    }

    int reserve() {
        int current = pq.top();
        pq.pop();

        return current;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
        reserved_seats.erase(seatNumber);
    }
};
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
