// Domenico D'Erasmo
// 19 January 2020
// CISC 4080 - Lab 1
// Driver file to test sorting algorithms

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "Sorter.h"

/* Helper Function
 *
 * Checks if the vector is sorted.
 *    @param int_list: The list of integers that the function checls
 *    returns true if int_list's elements are arranged in ascending order
 *    returns false otherwise */

bool IsSorted (std::vector<int> list)
{
   // declared outside loop to prevent repeated checking of size
   int size = list.size();

   for (int list_pos = 1; list_pos < size; list_pos++)
   {
      if (list[list_pos] < list[list_pos - 1])
      {
         return false;
      }
   }

   return true;
}

/* Driver Function
 *
 * Checks if the vector was sorted
 *    @param sorted_vector: the vector to check  */ 

void PrintResults(std::vector<int> vector_to_check)
{
   if (IsSorted (vector_to_check))
   {
      std::cout <<"The sort passed testing!\n";
   }
   else
   {
      std::cout <<"The sort does not work!\n";
   }
}

/* Driver Function
 *
 * Initializes input_size, which is used for the first part of the lab 
 *    @return input_size: an integer prompted by the user */

int PromptForSize()
{
   int input_size;
   std::cout << "Enter the vector size: ";
   std::cin >> input_size;
   return input_size;
}

/* Driver Function
 *
 * Tests the three sorting algorithms to see if they work
 *    @param test_sorter: a sorting instance that lets us work on a vector */

void TestSortFunctionality(Sorter test_sorter)
{   
   typedef std::vector<int> (Sorter::*BasicSortCall)();
   typedef std::vector<int> (Sorter::*AdvancedSortCall)(int, int);

   // Defined pointers to member functions so that I could pass the function as an argument to another function
   //    The benefit is that I avoid reusing code 
   //    The downside is that this is somewhat tricky to work with. While std::function would make this easier,
   //       std::function does not work before C++11.
   BasicSortCall basic_sort_pointers[5] = {&Sorter::BubbleSort, &Sorter::InsertionSort, &Sorter::SelectionSort, &Sorter::CallQuickSort, &Sorter::CallRadixSort};
   AdvancedSortCall advanced_sort_pointer = &Sorter::MergeSort;
   std::vector<int> sorted_vector; // = test_sorter.GetList();
  
   for (int sort_type = 0; sort_type < 5; sort_type++)
   {
      std::cout << "Testing " << Sorter::sort_names[sort_type] << ":\n";
      sorted_vector = test_sorter.TestAlgorithm(basic_sort_pointers[sort_type]);
      PrintResults(sorted_vector);
   } 
   
   std::cout << "Testing " << Sorter::sort_names[5] << ":\n";
   sorted_vector = test_sorter.TestAlgorithm(advanced_sort_pointer);
   PrintResults(sorted_vector);
}

/* Driver Function
 *
 * Gets runtime of each function 
 *    @param sort_type: designates the sort type used
 *    @return time_passed: time passed by the sort */

double TimeRun(int sort_type)
{
   // Initialization
   #define BILLION 1E9
   #define VECTOR_SIZE 100

   // Allows ths user to call from the array with a class instance
   #define CALL_SORTER_FUNCTION(object, ptr_to_member) ((object).*ptr_to_member)
   
   typedef std::vector<int> (Sorter::*BasicSortCall)();
   typedef std::vector<int> (Sorter::*AdvancedSortCall) (int, int);
   struct timespec function_start, function_end;
   double time_passed;
   Sorter test_sorter(VECTOR_SIZE);

   BasicSortCall basic_sort_pointers[5] = {&Sorter::BubbleSort, &Sorter::InsertionSort, &Sorter::SelectionSort, &Sorter::CallQuickSort, &Sorter::CallRadixSort};
   AdvancedSortCall advanced_sort_pointer = &Sorter::MergeSort;

   test_sorter.GenerateRandomVector();

   if (sort_type == 5)
   {
      // measures time of that function run
      clock_gettime (CLOCK_REALTIME, &function_start);
      CALL_SORTER_FUNCTION (test_sorter, advanced_sort_pointer)(0, test_sorter.GetSize() - 1);
      clock_gettime (CLOCK_REALTIME, &function_end);

      time_passed = (function_end.tv_sec - function_start.tv_sec) + 
         (function_end.tv_nsec - function_start.tv_nsec) / BILLION;

      return time_passed;

   }
   // measures time of that function run
   clock_gettime (CLOCK_REALTIME, &function_start);
   CALL_SORTER_FUNCTION (test_sorter, basic_sort_pointers[sort_type])();
   clock_gettime (CLOCK_REALTIME, &function_end);

   time_passed = (function_end.tv_sec - function_start.tv_sec) + 
      (function_end.tv_nsec - function_start.tv_nsec) / BILLION;

   return time_passed;
}

/* Driver Function
 *
 * Computes the average of the array
 *    @param runs: the array whose average is being computed*/

double CalculateAverage(double data[], int size)
{
   double cumulative = 0;

   for (int data_pos = 0; data_pos < size; data_pos++)
   {
      cumulative += data[data_pos];
   }

   double average = cumulative / size;

   return average;
}

/* Driver Function
 *
 * Tests the running times of the three algorithms */


void CompareRunningTimes()
{
   // Initialization
   #define VECTOR_SIZE 100
   #define SORT_RUNS 100

   double time_elapsed[6][SORT_RUNS];
   double average_time[6];
   
   for (int sort_type = 0; sort_type < 5; sort_type++)
   {
      std::cout << Sorter::sort_names[sort_type] << ":\n";
      std::cout << " --------------------------------------------\n";

      for (int sort_run = 0; sort_run < SORT_RUNS; sort_run++)
      {
         time_elapsed[sort_type][sort_run] = TimeRun(sort_type);
         std::cout << "Run " << sort_run << " took " << time_elapsed[sort_type][sort_run] << " seconds to sort a size " << VECTOR_SIZE << " array.\n";
      }
      
      average_time[sort_type] = CalculateAverage(time_elapsed[sort_type], SORT_RUNS);
      std::cout << "Average time for " << Sorter::sort_names[sort_type] << " to sort a " << VECTOR_SIZE << " array is " << average_time[sort_type] << " seconds.\n\n";
   }
   std::cout << Sorter::sort_names[5] << ":\n";
   std::cout << " --------------------------------------------\n";

   for (int sort_run = 0; sort_run < SORT_RUNS; sort_run++)
   {
      time_elapsed[5][sort_run] = TimeRun(5);
      std::cout << "Run " << sort_run << " took " << time_elapsed[5][sort_run] << " seconds to sort a size " << VECTOR_SIZE << " array.\n";
      }
      
      average_time[5] = CalculateAverage(time_elapsed[5], SORT_RUNS);
      std::cout << "Average time for " << Sorter::sort_names[5] << " to sort a " << VECTOR_SIZE << " array is " << average_time[5] << " seconds.\n\n";
}

int main()
{
   // Initialization
   int input_size = PromptForSize();
   Sorter test_sorter(input_size);
   test_sorter.GenerateRandomVector();
   
   // Part 1
   TestSortFunctionality(test_sorter);

   // Part 2
   CompareRunningTimes();

   return 0;
}
