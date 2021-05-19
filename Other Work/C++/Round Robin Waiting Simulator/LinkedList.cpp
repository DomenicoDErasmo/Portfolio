#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList()
{
	name = "";
	time = 0;
	link = nullptr;
}

/* Constructor
 * @param in_name: A string for the desired name of the node
 * @param in_time: An int for the initial time cost for the process
 */
LinkedList::LinkedList(std::string in_name, int in_time)
{
	name = in_name;
	time = in_time;
	link = nullptr;
}

/* Mutator for the node name
 * @param in_name: A string for the desired name of the node
 */
void LinkedList::SetName(std::string in_name)
{
	name = in_name;
}

/* Mutator for the process cost
 * @param in_time: An int for the time cost for the process
 */
void LinkedList::SetTime(int in_time)
{
	time = in_time;
}

/* Mutator for the next element in the linked list
 * @param in_next: A pointer to the next node
 */
void LinkedList::SetLink(LinkedList* in_next)
{
	link = in_next;
}

/* Accessor for the node name
 * @return name: A string denoting the name of the node
 */
std::string LinkedList::GetName()
{
	return name;
}

/* Accessor for the time cost of the process
 * @return time: An int denoting the time cost of the process
 */
int LinkedList::GetTime()
{
	return time;
}

/* Accessor for the link to the next node in the list
 * @return link: A pointer to the next node
 */
LinkedList* LinkedList::GetLink()
{
	return link;
}

/* Helper function to print every node after this one.
 */
void LinkedList::PrintList()
{
	LinkedList* temp = this;
	std::cout << "-------------------------" << std::endl;
	while (temp != NULL)
	{
		std::cout << temp->GetName() << " - " << temp->GetTime() << std::endl;
		temp = temp->GetLink();
	}
	std::cout << "-------------------------" << std::endl;
}

/* Helper function to conver the current node into a string
 * @return output: The string representation of the node
 */
std::string LinkedList::ToString()
{
	std::string output = name;
	output.append(1, ' ');
	output.append(std::to_string(time));
	return output;
}
