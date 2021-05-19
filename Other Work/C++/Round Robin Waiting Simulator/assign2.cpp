// Domenico D'Erasmo
// 21 March 2021
// CISC 3595 RR Scheduler
// Driver code to simulate a round robin CPU scheduler

#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <signal.h>
#include "LinkedList.h"

/* Converts the given string into an integer
 * @param str: The string to convert. Should consist only of numbers.
 * @return result: The integer representation of the string.
 */
int ToInt(std::string str)
{
	int result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		result = result * 10 + int(str[i]) - 48;
	}
	return result;
}

/* Reads the line and converts it into fields name and time, regardless of the number of spaces in between
 * @param line: The string to convert. Should be in the format: [name] [time]
 * return fields: A string array consisting of 2 elements. fields[0] is the name, while fields[1] is the time
 */
std::string* ParseLine(std::string line)
{
	std::istringstream ss(line);	// handles any amount of whitespace between the name and time on the line
	std::string* fields = new std::string[2];
	std::string field;
	int i = 0;
	while (ss >> field)
	{
		fields[i] = field;
		i++;
	}
	return fields;
}

/* Builds a linked list node from the provided line
 * @param line: The formatted line. It should be in the format: [name] [time]
 * @return: Returns a new linked list node, allocated on the heap
 */
LinkedList* BuildFromLine(std::string line)
{
	std::string* fields = ParseLine(line);
	return new LinkedList(fields[0], ToInt(fields[1]));
	delete[] fields;    // frees the memory allocated in ParseLine to fields
}

/* Creates the list of processes
 * @param all_text: A string consisting of text pulled from user input in main
 * @param head: The address of a pointer to the head of a linked list
 */
void CreateProcessList(std::string all_text, LinkedList** head)
{
    // init
	std::stringstream parser(all_text);
	std::string line;

	// initialize head
	std::getline(parser, line, '.');
	*head = BuildFromLine(line);
	LinkedList* temp = *head;

    // initialize the rest of the nodes
	while (std::getline(parser, line, '.'))
	{
		temp->SetLink(BuildFromLine(line));
		temp = temp->GetLink();
	}
}

/* Deletes the node with the specified name
 * @param head: The address of a pointer to the head of a linked list
 * @param del_name: The name of the node to delete
 */
void DeleteByName(LinkedList** head, std::string del_name)
{
	LinkedList* temp = *head;

    // if we want to delete the head, must set head to the next position
	if ((*head)->GetName() == del_name)
	{
		*head = (*head)->GetLink();
		delete temp;
		return;
	}
    // otherwise, we search using temp
	else
	{
		LinkedList* prev = *head;
		temp = temp->GetLink();
		while (temp->GetLink() != NULL)
		{
			std::cout << temp->GetName() << std::endl;
			if (temp->GetName() == del_name)
			{
				prev->SetLink(temp->GetLink());
				delete temp;
				return;
			}
			else
			{
				prev = temp;
				temp = temp->GetLink();
			}
		}
	}	
}

/* Deletes the whole linked list to prevent memory leak, although the list should delete itself either way
 * @param head: The address of a pointer to the head of a linked list
 */
void DeleteList(LinkedList** head)
{
	LinkedList* temp = *head;
	while (temp != NULL)
	{
		(*head) = (*head)->GetLink();
		delete temp;
	    temp = *head;
    }
}

/* Moves the head of the linked list to the end of the linked list
 * @param head: The address of a pointer to the head of a linked list. 
 *  Also lets us access the node we wish to move.
 */
void MoveToEnd(LinkedList** head)
{
	if ((*head)->GetLink() == nullptr)
	{
		return;
	}
	LinkedList* old_head = *head;
	*head = (*head)->GetLink();
	LinkedList* temp = *head;
	while (temp->GetLink() != nullptr)
	{
		temp = temp->GetLink();
	}
	temp->SetLink(old_head);
	old_head->SetLink(nullptr);
}

const int TIMESLICE = 3;
bool alarm_fired = false;

/* Our alarm handler. This activates the alarm to signify an interrupt
 */
void alarm_handler(int sig_num)
{   
    alarm_fired = true;
} 

int main()
{
    std::string input, all_text;

	std::cout << "Enter processes and time left in this format:" << std::endl;
    std::cout << "ProcessName TimeRemaining" << std::endl;
    std::cout << "Then enter the EOF character (Ctrl D on Linux) when you are done\n";

    // Prompt the user for input
	while (std::getline(std::cin, input))
	{
		all_text.append(input);
		all_text.append(1, '.');
	}
    std::cout << "\n";	

    LinkedList* head = NULL; 
	CreateProcessList(all_text, &head);
    
    signal(SIGALRM, alarm_handler);

    // Round robin scheduler
    while(head)
    {
        int time_remaining = head->GetTime();
        alarm(TIMESLICE); 
        sleep(time_remaining);
        
        // Process interrupted and timed out
        if (alarm_fired == true)
        {
            time_remaining -= TIMESLICE;
        }
        // Process completed
        else
        {
            time_remaining = 0;
        }
        // Signify process completion and remove from queue
        if (time_remaining == 0)
        {
            std::cout << head->GetName() << " Finished\n";
            DeleteByName(&head, head->GetName());
        }
        // Decrement time by TIMESLICE and move to end of queue
        else
        {
            head->SetTime(time_remaining);
            std::cout << head->ToString() << "\n";
            MoveToEnd(&head);
        }
        alarm_fired = false;
    }
    std::cout << "No process left\n";

    // while the code should delete the whole list already, we want this here just in case 
	DeleteList(&head);
	return 0;
}
