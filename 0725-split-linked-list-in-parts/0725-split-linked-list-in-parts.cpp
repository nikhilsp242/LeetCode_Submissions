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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int count=0;

        while(curr){
            count++;
            curr = curr->next;
        }

        curr = head;
        vector<ListNode*> lst;

        int rem = count%k;
        int split = count/k;

        for(int i=0;i<k;i++){
            lst.push_back(curr);
            int splitSize = split+(i<rem ? 1 : 0);
            for(int j=0;j<splitSize-1;j++){
                curr = curr->next;
            }
            if(curr){
                ListNode* newHead = curr->next;
                curr->next = nullptr;
                curr = newHead;
            }
        }
         
        return lst;
    }
};