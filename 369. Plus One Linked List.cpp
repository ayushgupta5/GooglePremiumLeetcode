/*369. Plus One Linked List
Input: head = [1,2,3]
Output: [1,2,4]
Input: head = [0]
Output: [1]
*/
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
      // sentinel head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* notNine = dummy;

        // find the rightmost not-nine digit
        while (head != nullptr) {
            if (head->val != 9)
                notNine = head;
            head = head->next;
        }
        // increase this rightmost not-nine digit by 1
        notNine->val++;
        notNine = notNine->next;
        // set all the following nines to zeros
        while (notNine != nullptr) {
            notNine->val = 0;
            notNine = notNine->next;
        }
        if(dummy->val==1)
             return dummy;
        return dummy->next;
    }
};