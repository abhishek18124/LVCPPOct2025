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

class ListNodeComp {
public:

    // return false if you want a to be given more priority than b otherwise return true

    bool operator()(ListNode* a, ListNode* b) {
        if (a->val < b->val) {
            // since we are building a minHeap based on node values so when
            // a->val is less than b->val we want to give node a more priority
            // then node b hence we are return false
            return false;
        } else {
            return true;
        }
    }
};

// time : O(nklogk)
// space: O(k) due to minHeap

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComp> minHeap;
        for (ListNode* head : lists) {
            if (head != NULL) {
                minHeap.push(head);
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        while (!minHeap.empty()) {
            ListNode* minNodePtr = minHeap.top();
            minHeap.pop();
            temp->next = minNodePtr;
            temp = temp->next;
            if (minNodePtr->next != NULL) {
                minHeap.push(minNodePtr->next);
            }

        }

        return dummy->next;

    }
};