class TreeMap {
    class Node{
        public:
            int key;
            int val;
            Node* left;
            Node* right;

            Node(int k, int v) : key(k), val(v), left(nullptr), right(nullptr){};

    };

    Node* root;

public:

    void traverse(Node* node, vector<int>& result){
        if(node == nullptr) return;

        traverse(node->left, result);
        result.push_back(node->key);
        traverse(node->right, result);
    }

    Node* removeTraverse(Node* node, int key){
        if(node == nullptr) return nullptr;

        if(node->key > key){
            node->left = removeTraverse(node->left, key);
        }else if(node->key < key){
            node->right = removeTraverse(node->right, key);
        }else{
            //we found the key
            if(node->left == nullptr){
                Node* temp = node->right;
                delete node;
                return temp;
            }else if(node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return temp;
            }
        
            Node* successor = node->right;
            while(successor->left != nullptr){
                successor = successor->left;
            }

            node->key = successor->key;
            node->val = successor->val;

            node->right = removeTraverse(node->right, successor->key);
        }

        return node;
    }

    TreeMap() : root(nullptr) {
        
    }

    void insert(int key, int val) {
        if(root == nullptr){
            //first insert
            root = new Node(key, val);
            return;
        }

        Node* prev_node = nullptr;
        Node* curr = root;

        while(curr != nullptr){
            prev_node = curr;
            if(curr->key > key){
                curr = curr->left;
            }
            else if(curr->key < key){
                curr = curr->right;
            }else{
                //overwrite
                curr->val = val;
                return;
            }
        }

        if (key < prev_node->key) {
            prev_node->left = new Node(key, val);
        } else {
            prev_node->right = new Node(key, val);
        }


    }

    int get(int key) {
        Node* curr = root;

        while(curr != nullptr){
            if(curr->key == key) return curr->val;

            if(curr->key > key) {
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }

        return -1;
    }

    int getMin() {
        if(root == nullptr) return -1;

        //must go left
        Node* curr= root;
        while(curr->left != nullptr){
            curr = curr->left;
        }

        return curr->val;
    }

    int getMax() {
        if(root == nullptr) return -1;

        Node* curr = root;
        while(curr->right != nullptr){
            curr = curr->right;
        }

        return curr->val;
    }

    void remove(int key) {
      root = removeTraverse(root, key);
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> res;
        traverse(root, res);
        return res;
    }
};
