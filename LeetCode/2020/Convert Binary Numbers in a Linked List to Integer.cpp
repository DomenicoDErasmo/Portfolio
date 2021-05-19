/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
std::vector<int> GetDigits(ListNode* head)
{
    
    std::vector<int> numbers;
    while (head->next != NULL)
    {
            
        numbers.push_back(head->val);
        head = head->next;
            
    }
    
    numbers.push_back(head->val);
    
    return numbers;
    
}
    
int BinaryToDecimal(std::vector<int> binary_digits)
{
    
    int solution = 0;
    for (int digit_pos = binary_digits.size() - 1; digit_pos > -1; digit_pos--)
    {
        
        solution += binary_digits[binary_digits.size()-1-digit_pos]*pow(2,digit_pos);
        
    }
    
    return solution;
    
}
    
public:
    int getDecimalValue(ListNode* head) 
    {
    
        std::vector<int> binary_digits = GetDigits(head);
        int solution = BinaryToDecimal(binary_digits);
        
        return solution;
        
    }
};