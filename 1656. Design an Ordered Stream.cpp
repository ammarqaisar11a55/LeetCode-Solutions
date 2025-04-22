class OrderedStream {
public:
    vector<string> Stream;
    int current_pointer;

    OrderedStream(int n) {
        Stream.resize(n + 1);
        current_pointer = 1;
    }

    vector<string> insert(int idKey, string value) {
        Stream[idKey] = value;
        vector<string> Current_res;

        while (current_pointer < Stream.size() &&
               Stream[current_pointer].empty() == false) {
            Current_res.push_back(Stream[current_pointer]);
            current_pointer++;
        }

        return Current_res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
