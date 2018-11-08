#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseListWithHead(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode * cur = head->next;
        ListNode * next = NULL;
        ListNode *pre = NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = pre;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode * cur = head;
        ListNode * next = NULL;
        ListNode *pre = NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    ListNode * cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    Solution s;
    head = s.reverseList(head);
    cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
