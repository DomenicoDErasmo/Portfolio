#include <iostream>
#include <fstream>
#include <thread>
#include "BoundedBuffer.h"

int main(int argc, char* argv[])
{
  int size = 10;
  std::ifstream reader(argv[1]);
  BoundedBuffer buffer(&reader, size);
 
  // Currently, we have the threads running
  // Get a segmentation fault at the moment when trying to dereference istream
  std::thread producer(&BoundedBuffer::run_producer, &buffer);
  std::thread consumer(&BoundedBuffer::run_consumer, &buffer);

  producer.join();
  consumer.join();  

  return 0;
}
