class Deque {
    class Node{
        public:
            Node() : m_val(0), m_prev(nullptr), m_next(nullptr){};
            Node(int v) : m_val(v), m_prev(nullptr), m_next(nullptr){};
            int m_val;
            Node* m_prev;
            Node* m_next;
    };

    Node* head;
    Node* tail;

public:
    Deque() {
        head = new Node(0);
        tail = new Node(0);
        head->m_next = tail;
        tail->m_prev = head;

    }

    bool isEmpty() {
        return head->m_next == tail;
    }

    void append(int value) {
        Node* new_node = new Node(value);
        Node* prev_node = tail->m_prev;
        
        new_node->m_next = tail;
        new_node->m_prev = prev_node;

        prev_node->m_next = new_node;
        tail->m_prev = new_node;
    }

    void appendleft(int value) {
        Node* new_node = new Node(value);
        Node* next_node = head->m_next;

        new_node->m_prev = head;
        new_node->m_next = next_node;

        head->m_next = new_node;
        next_node->m_prev = new_node;
    }

    int pop() {
        if(this->isEmpty()){
            return -1;
        }

        Node* node_to_pop = tail->m_prev;
        Node* prev_node = node_to_pop->m_prev;
        int val = node_to_pop->m_val;

        prev_node->m_next = tail;
        tail->m_prev = prev_node;

        return val;
    }

    int popleft() {
        if(this->isEmpty()){
            return -1;
        }

        Node* node_to_pop = head->m_next;
        Node* next_node = node_to_pop->m_next;
        int val = node_to_pop->m_val;

        head->m_next = next_node;
        next_node->m_prev = head;

        return val;
    }
};
