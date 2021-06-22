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
    void printQueue(std::queue<ListNode*>& queue)
    {
        while (!queue.empty())
        {
            std::cout << queue.front()->val << ", ";
            queue.pop();
        }
        std::cout << std::endl;
    }
    
    void initQueueWithLinkedList(std::queue<ListNode*>& nodes, ListNode* head)
    {
        ListNode* temp = head;
        while(temp)
        {
            nodes.push(temp);
            temp = temp->next;
        }
    }
    
    void fillQueue(std::queue<ListNode*>& nodes, int size)
    {
        while (nodes.size() < size)
        {
            nodes.push(new ListNode(0));
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        std::queue<ListNode*> l1_nodes, l2_nodes;
        initQueueWithLinkedList(l1_nodes, l1);
        initQueueWithLinkedList(l2_nodes, l2);
        
        if(l1_nodes.size() < l2_nodes.size())
        {
            fillQueue(l1_nodes, l2_nodes.size());
        }
        else
        {
            fillQueue(l2_nodes, l1_nodes.size());
        }
        
        ListNode* result = new ListNode();
        ListNode* temp = result;
        int carryVal = 0;
        
        while(!l1_nodes.empty())
        {
            int digitSum = l1_nodes.front()->val + l2_nodes.front()->val + carryVal;
            carryVal = 0;
            if (digitSum >= 10)
            {
                carryVal = digitSum / 10;
                digitSum -= 10 * carryVal;
            }
            temp->val = digitSum;
            
            l1_nodes.pop();
            l2_nodes.pop();
            
            if (!l1_nodes.empty())
            {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        
        if(carryVal > 0)
        {
            temp->next = new ListNode(carryVal);
        }
        
        // plan: make these queues equal size (add 0s to smaller queue)
        // include carry condition: if l1.front + l2.front > 10, make carry bit true, sum of the current digits -= 10
        
        return result;
    }
};