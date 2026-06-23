class DynamicArray {
private:
    int m_capacity;
    int* m_items;
    int m_cnt = 0;
public:

    DynamicArray(int capacity){
        try{
            if(capacity <= 0) throw runtime_error("Capacity must be over 0.");

            m_capacity = capacity;
            m_items = new int [capacity];

        }catch(const exception& e){
            cout << e.what() << endl;
        }
    }

    int get(int i) {
        return m_items[i];
    }

    void set(int i, int n) {
        m_items[i] = n;
    }

    void pushback(int n) {
        if(m_cnt >= m_capacity){
            resize();
        }
        if (m_cnt > 0) {
            cout << "Value of last item before: " << m_items[m_cnt - 1] << "\n";
        }    

        cout << "Address where I will place " << n << ": " << &m_items[m_cnt] << "\n";
        m_items[m_cnt] = n; 
        m_cnt++;
    }

    int popback() {
        int last = m_items[m_cnt-1];
        m_items[m_cnt-1] = 1337;
        m_cnt--;
        return last;
    }

    void resize() {
        m_capacity *= 2;
        int* new_items = new int [m_capacity];
        
        for(size_t i = 0; i< m_cnt; i++){
            new_items[i] = m_items[i];
        }

        delete[] m_items;
        m_items = new_items;
    }

    int getSize() {
        return m_cnt;
    }

    int getCapacity() {
        return m_capacity;
    }
};
