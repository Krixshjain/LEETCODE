// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head->next==nullptr) return nullptr;
//         ListNode* fast = head;
//         ListNode* slow = head;
//         while(fast != nullptr && n != 0){
//             fast= fast->next;
//             n--;
//         }
//         if(!fast) return head->next;
//         while(fast && fast->next != nullptr){
//             slow= slow->next;
//             fast = fast->next;
//         }

//         ListNode* dummy = NULL;
//         if(slow->next->next == NULL){
//             slow->next=nullptr;
//             // delete slow->next;//
//         }
//         else if(slow == head){
//             head = head->next;
//             delete slow;
//         } else{
//             dummy = slow->next;
//             slow->next = slow->next->next;
//             delete dummy;
//         }

//         return head;
//     }
// };


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        while(n>0){
            fast = fast->next;
            n--;
        }

        while(fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* nodedel = slow->next;
        slow->next = slow->next->next;

        delete nodedel;

        return dummy->next;   


    }
};