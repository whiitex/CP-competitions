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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = head;
        while (first != 0) {
            stack<int> st;
            ListNode* last = first;
            int count = 0;
            while (last != 0 and count < k) {
                st.push(last->val);
                last = last->next;
                ++count;
            }
            
            if (count < k) break;

            while (st.size()) {
                first->val = st.top();
                first = first->next;
                st.pop();
            }
        }
        return head;
    }
};