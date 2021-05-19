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
class Solution 
{
public:
    
    int GetLength(ListNode** head)
    {
        ListNode* crawler = *head;
        int length = 0;
        while (crawler->next != NULL)
        {
            length++;
            crawler = crawler->next;
        }
        return length;
    }
    
    ListNode* GetMidOfEvenList(ListNode** head, int mid)
    {
        ListNode* crawler = *head;
        for (int i = 1; i < mid; i++)
        {
            crawler = crawler->next;
        }
        return crawler;
    }
    
    ListNode* GetMidOfOddList(ListNode** head, int mid)
    {
        ListNode* crawler = *head;
        for (int i = 0; i < mid; i++)
        {
            crawler = crawler->next;
        }
        return crawler;
    }
    
    ListNode* middleNode(ListNode* head) 
    {
        int length = GetLength(&head);    
        int mid = (length + 2)/2;
        ListNode* middle = (length % 2 == 0) ? GetMidOfEvenList(&head, mid) : GetMidOfOddList(&head, mid);
        return middle;
    }
};