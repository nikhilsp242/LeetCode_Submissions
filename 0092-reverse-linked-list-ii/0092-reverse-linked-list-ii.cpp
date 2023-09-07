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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==nullptr || left==right) return head;
        
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* preLeft = temp;

        for(int i=1;i<left;i++){
            preLeft = preLeft->next;
        }

        ListNode* leftNode = preLeft->next;
        ListNode* rightNode = leftNode;
        ListNode* prev = nullptr;

        for(int i=left;i<=right;i++){
            ListNode* next = rightNode->next;
            rightNode->next = prev;
            prev = rightNode;
            rightNode = next;
        }

        preLeft->next = prev;
        leftNode->next = rightNode;

        return temp->next;
    }
};