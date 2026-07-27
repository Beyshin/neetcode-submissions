class LinkedList {
    struct Node{
        int val;
        Node* next;
    };

    Node* m_head;
    Node* m_tail;
public:
    LinkedList() : m_head(nullptr), m_tail(nullptr) {

    }

    int get(int index) {
        int curr = 0;
        Node* curr_node = m_head;
        while(curr_node){
            if(curr == index) return curr_node->val;
            curr++;
            curr_node = curr_node->next;
        }

        return -1;
    }

    void insertHead(int val) {
        if(m_head == nullptr){
            m_head = new Node(val, nullptr);
            m_tail = m_head;
        }else{
            Node* temp = new Node(val, m_head);
            m_head = temp;
        }
    }
    
    void insertTail(int val) {
        Node* new_tail = new Node(val, nullptr);
        if(m_tail != nullptr){
            m_tail->next = new_tail; 
        }else{
            m_head = new_tail;
        }
        m_tail = new_tail;
    }

    bool remove(int index) {
        if(m_head == nullptr) return false;

        int cnt = 1;
        if(index == 0 && m_head != nullptr){
            Node* delete_node = m_head;
            m_head = m_head->next;
            
            if (m_head == nullptr) {
                m_tail = nullptr; 
            }

            delete delete_node;
            return true;
        }
        
        Node* node_before = m_head;
        Node* curr_node = m_head->next;
        while(curr_node != nullptr){
            if(cnt == index){
                if (curr_node == m_tail) {
                    m_tail = node_before;
                }
                node_before->next = curr_node->next;
                delete curr_node;
                return true;
            }
            node_before = node_before->next;
            curr_node = curr_node->next;
            cnt++;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> ans;
        Node* curr_node = m_head;
        while(curr_node){
            ans.push_back(curr_node->val);
            curr_node = curr_node->next;
        }
        return ans;
    }
};
