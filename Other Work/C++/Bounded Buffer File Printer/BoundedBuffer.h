#ifndef BOUNDEDBUFFER_H
#define BOUNDEDBUFFER_H

#include <iostream>
#include <fstream>
#include <semaphore.h>

class BoundedBuffer
{
public:
  // I used a pointer to istream, as I couldn't get the reference to work for some reason
  // That being said, to allocate a reference in the constructor, we replace the first line with:
  // BoundedBuffer(std::istream& in, int& n) : reader(in)
  BoundedBuffer(std::istream* in, int& n)
  {
    // initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, n);

    // initialize buffer
    capacity = n;
    buffer = new std::string[capacity];  
  
    reader = in;
  }

  // for freeing dynamically allocated memory
  ~BoundedBuffer();
  void run_producer();
  void run_consumer();

private:
  sem_t mutex;
  sem_t full;  
  sem_t empty;
  int capacity, size = 0, in = 0, out = 0;
  bool end_of_file = false;
  std::istream* reader;
  std::string* buffer;
};

#endif
