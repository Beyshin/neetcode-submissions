class KthLargest {
private:
    int m_k;
    vector<int> m_data;
public:
    KthLargest(int k, vector<int>& nums) : m_k(k), m_data(nums) {
        
    }
    
    int add(int val) {
        m_data.push_back(val);
        sort(m_data.begin(), m_data.end(), greater());

        return m_data[m_k-1];
    }
};
