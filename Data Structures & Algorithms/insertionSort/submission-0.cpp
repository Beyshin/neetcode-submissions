// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        int n = pairs.size();
        vector<vector<Pair>> ans;
        vector<Pair> current_iteration = pairs;
        for(size_t i = 0; i<n; i++){
            int j = i;
    
            while(j > 0 && current_iteration[j].key < current_iteration[j-1].key){
                Pair tmp = current_iteration[j];
                current_iteration[j] = current_iteration[j-1];
                current_iteration[j-1] = tmp;
                j--;
                cout << current_iteration[j].value << " moves." << endl;
            };
            ans.push_back(current_iteration);
        }

        return ans;
    }
};
