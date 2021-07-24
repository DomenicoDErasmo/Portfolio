#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList<std::string>* head = new LinkedList<std::string>("Hello");
    head->SetNext(new LinkedList<std::string>("world!"));
    LinkedList<std::string>* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->GetData() << " ";
        temp = temp->GetNext();
    }
    std::cout << std::endl;
    return 0;
}