/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* getMid(ListNode *head)
        {
            ListNode* slow = head, *fast = head->next;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    ListNode* mergeList(ListNode *list1, ListNode *list2)
    {
        ListNode *tail = new ListNode();
        ListNode *dummy = tail;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
            
        }
        if (list1)
            {
                tail->next = list1;
            }
        if (list2)
            {
                tail->next = list2;
            }
            return dummy->next;
    }
    ListNode* sortList(ListNode *head)
    {

        if (!head || !head->next)
        {
            return head;
        }
        ListNode *mnode = getMid(head);
        ListNode *temp = mnode->next;
        mnode->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(temp);
        return mergeList(left,right);
    }
};
