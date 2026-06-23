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
        int cnt = 0;
        Node* node = m_head;
        while(node != nullptr){
            if(cnt == index) return node->val;
            node = node->next;
            cnt++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* new_head;
        if(m_head != nullptr){
            Node* old_head = m_head;
            new_head = new Node{val, old_head};
        }else{
           new_head = new Node{val, nullptr};
           m_tail = new_head;
        }
        m_head = new_head;
    }
    
    void insertTail(int val) {
       Node* new_tail = new Node{val, nullptr};
       if(m_tail != nullptr) m_tail->next = new_tail;
       else m_head = new_tail;
       m_tail = new_tail;
    }

    bool remove(int index) {
    if (m_head == nullptr) return false;

        int cnt = 0;
        Node* node_to_remove = nullptr;

        if(index == 0){
            node_to_remove = m_head;
            m_head = m_head->next;
            delete node_to_remove;
            if (m_head == nullptr) m_tail = nullptr; 
            return true;
        }

        Node* node = m_head;
        Node* node_before = nullptr;

       while (node != nullptr && cnt < index) {
            node_before = node;
            node = node->next;
            cnt++;
        }

        if (node == nullptr) return false; 

        node_before->next = node->next;

        if (node->next == nullptr) {
            m_tail = node_before;
        }

        delete node;
        return true;
    }

    vector<int> getValues() {
        Node* node = m_head;
        vector<int> ans;
        while(node != nullptr){
            ans.push_back(node->val);
            cout << node->val << endl;
            node = node->next;
        }
        return ans;
    }
};
