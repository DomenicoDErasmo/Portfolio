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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        // We want a-1 from list1 to point to the head of list2
        // Similarly, we want the last node of list2 to point to b+1
        // We can declare ListNode pointers to get these addresses and store them after linked list traversals
        // Similarly, we want to free the memory pointed to on nodes a through b
        ListNode* node1 = list1;
        for (int i = 0; i < a-1; i++)
        {
            node1 = node1->next;
        }
        ListNode* temp = node1->next;
        // deleting a through b
        for (int i = a-1; i < b; i++)
        {
            ListNode* temp2 = temp->next;
            delete temp;
            temp = temp2;
        }
        ListNode* node2 = temp;
        // attaching list 2 to end_a and start_b
        node1->next = list2;
        temp = list2;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node2;
        return list1;
    }
};