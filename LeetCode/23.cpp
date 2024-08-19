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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return 0;

        vector<int> ansv;
        for (int i=0; i<k; ++i) {
            ListNode* node = lists[i];
            while (node != nullptr) {
                ansv.push_back(node->val);
                node = node->next;
            }
        }

        if (ansv.size() == 0) return 0;
        sort(ansv.begin(), ansv.end());
        
        ListNode* head = new ListNode();
        head->val = ansv[0];
        ListNode* parent = head;
        for (int i=1; i<ansv.size(); ++i) {
            int v = ansv[i];
            ListNode* newnode = new ListNode(v);
            parent->next = newnode;
            parent = newnode;
        }

        return head;
    }
};