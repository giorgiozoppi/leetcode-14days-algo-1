
struct ListNode {
    int val;
    struct ListNode *next;
};
/**
 * Problem:
 * Given the head of a singly linked list, return the middle node of the linked list. 
 * If there are two middle nodes, return the second middle node.
 * Please don't use as LinkedList.
 */
ListNode* middleNode(ListNode* head) {
        auto tmp{head};
        auto idx{1};
        for(auto tmp = head; tmp!=nullptr; tmp=tmp->next) {
            idx++;
        }
        auto pos = idx / 2;
        auto mod = idx % 2;
        if (mod == 1) {
            pos++;
        }
        ListNode* newhead{nullptr};
        int index{1};
        for (auto item = head; item!=nullptr; item = item->next) {
            if (index == pos) {
                newhead = new ListNode;
                newhead->val = item->val;
                newhead->next = item->next;
                return newhead;
            }
            index++;
        }
        return newhead;
}