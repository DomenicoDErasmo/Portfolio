#include <string>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
public:
	// Constructors
	LinkedList();
	LinkedList(std::string in_name, int in_time);

	// Mutators
	void SetName(std::string in_name);
	void SetTime(int in_time);
	void SetLink(LinkedList* in_next);

	// Accessors
	std::string GetName();
	int GetTime();
	LinkedList* GetLink();

	// Functions
	void PrintList();
    std::string ToString();

private:
	std::string name;
	int time;
	LinkedList* link;
};

#endif
