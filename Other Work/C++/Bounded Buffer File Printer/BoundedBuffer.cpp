#include "BoundedBuffer.h"
#include <iostream>
#include <semaphore.h>

BoundedBuffer::~BoundedBuffer()
{
  delete[] buffer;
}

void BoundedBuffer::run_producer()
{
  std::string line;
  while (std::getline(*reader, line))
  {
    sem_wait(&empty);
    sem_wait(&mutex);

    // critical section
    *(buffer + in) = line;

    // 
    in = (in + 1) % capacity; // determine where to next read to in the circular array
    size++;
       
    // end critical section
 
    sem_post(&mutex);
    sem_post(&full);
  }
  end_of_file = true;
}

void BoundedBuffer::run_consumer()
{
  while (!end_of_file or size > 0)
  {
    sem_wait(&full);
    sem_wait(&mutex);

    // critical section
    std::cout << *(buffer + out) << "\n"; // both '\n' and std::endl seem to work
    
    out = (out + 1) % capacity; // determine where to next output from
    size--;

    // end critical section

    sem_post(&mutex);
    sem_post(&empty);
  }
}
