/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        vector<ListNode*> visited;

        ListNode* node = head;
        while(node){
            if(find(visited.begin(), visited.end(), node) == visited.end()){
                visited.push_back(node);
            }else{
                return true;
            }
            node = node->next;
        }

        return false;
    }
};
