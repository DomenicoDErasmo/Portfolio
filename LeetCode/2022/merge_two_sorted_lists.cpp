#include <iostream>
#include <cstdlib>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x): val(x), next(nullptr) {};
    ListNode(int x, ListNode* next): val(x), next(next) {};
};

struct ListNode* buildSortedRandomList(int nodes)
{
    ListNode* head = new ListNode(), *temp = head;
    int lower_bound = 0;
    for (size_t i = 0; i < nodes - 1; i++)
    {
        temp->val = rand() % 10 + lower_bound;
        lower_bound += temp->val;
        temp->next = new ListNode();
        temp = temp->next;
    }
    temp->val = rand() % 10 + lower_bound;
    return head;
}

void printList(struct ListNode* head)
{
    struct ListNode* temp = head;
    std::cout << "List: ";
    while(temp)
    {
        std::cout << temp -> val << ", ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

class Solution
{
public:
    struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
    {
        if (!(list1 or list2))
        {
            return nullptr;
        }
        struct ListNode* result = new ListNode, *result_temp = result, *list1_temp = list1, *list2_temp = list2;
        while(list1_temp or list2_temp)
        {
            if (list1_temp and list2_temp)
            {
                if (list1_temp->val < list2_temp->val)
                {
                    advanceLists(&result_temp, &list1_temp);
                }
                else
                {
                    advanceLists(&result_temp, &list2_temp);
                }
            }
            else if (list1_temp)
            {
                advanceLists(&result_temp, &list1_temp);
            }
            else
            {
                advanceLists(&result_temp, &list2_temp);
            }
            if (list1_temp or list2_temp)
            {
                result_temp->next = new ListNode;
                result_temp = result_temp->next;
            }
        }
        return result;
    }
private:
    void advanceLists(struct ListNode** result, struct ListNode** temp)
    {
        (*result)->val = (*temp)->val;
        *temp = (*temp)->next;
    }
};

int main()
{
    srand(time(0));
    struct ListNode* list1 = buildSortedRandomList(5);
    struct ListNode* list2 = buildSortedRandomList(7);
    Solution solution;
    struct ListNode* combined_list = solution.mergeTwoLists(list1, list2);
    printList(list1);
    printList(list2);
    printList(combined_list);
    struct ListNode* empty_combined = solution.mergeTwoLists(nullptr, nullptr);
    printList(empty_combined);
    return 0;
}