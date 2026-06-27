class MinStack {
public:
    vector<pair<int, int>> m_values; // [value, min_to_date]
    int m_count = 0;

    MinStack() {
        
    }
    
    void push(int val) {
        if(m_values.empty()) m_values.push_back(make_pair(val, val));
        else{
            m_values.push_back(make_pair(val, min(val, m_values.back().second)));
        }
        m_count++;
    }
    
    void pop() {
        m_values.pop_back();
    }
    
    int top() {
        return m_values.back().first;
    }
    
    int getMin() {
        return m_values.back().second;
    }
};
