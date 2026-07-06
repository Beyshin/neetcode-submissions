class KthLargest {
private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) : m_k(k) {
        for(const int& num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > m_k){
            pq.pop();
        }

        return pq.top();
    }
};
