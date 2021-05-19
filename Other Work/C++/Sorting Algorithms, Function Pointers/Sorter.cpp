// Domenico D'Erasmo
// 19 January 2020
// CISC 4080 - Lab 1
// Implementation file for Sorter Class

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include "Sorter.h"

/* Constant
 * 
 * Defines a constant for sort names */

const std::string Sorter::sort_names[6] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Radix Sort", "Merge Sort"};

/* Constructor Function
 *
 * @param input_size: determines the size of the vector to be sorted*/

Sorter::Sorter(int input_size)
{
   size = input_size;
}

Sorter::Sorter(std::vector<int> input_list)
{
   int_list = input_list;
}

/* Helper Function
 * 
 * Generates a vector and fills it with integers from 1 to 10,000 */

void Sorter::GenerateRandomVector ()
{ 
   // Deletes the vector so that the Sorter class may be reused with different vectors
   int_list.clear();

   // Initializes random seed for generating numbers
   srand (time(NULL));
   
   // Other initialization
   int number = 0;
   const int RAND_RANGE = 10000;

   for (int result_pos = 0; result_pos < size; result_pos++)
   {
      // rand() % RAND_RANGE  gives a number from 0 to RAND_RANGE - 1, so we add 1
      number = rand() % RAND_RANGE + 1;
      
      int_list.push_back(number);
   }
}

/* Helper Function
 *
 *    Slices the vector
 *       @param start: the subvector start
 *       @param range: how many elements to copy
 *       @return subvector: the subvector */

std::vector<int> Sorter::Slice(int start, int range)
{
   auto first = int_list.cbegin() + start;
   auto last = int_list.cbegin() + range + 1;

   std::vector<int> subvector(first, last);
   return subvector;
}

/* Accessor Function
 *
 * Returns the Sorter class' size
 *    @return size: the sorter class' size */

int Sorter::GetSize()
{
   return size;
}

/* Accessor Function
 *
 * Returns the Sorter class' vector 
 *    @return int_list: The Sorter class' vector */

std::vector<int> Sorter::GetList()
{
   return int_list;
}

/* Helper Function
 *
 * Displays the contents of the vector in ascending index order.
 *    @param list_to_print: The list of integers that the function prints */

void Sorter::PrintVector(const std::vector<int>& list_to_print)
{
   // Cycles through the whole list, printing out each entry
   for (int list_pos = 0; list_pos < list_to_print.size(); list_pos++)
   {
      std::cout << list_to_print[list_pos] << ", ";
   }

   std::cout << "\n";
}

/* Testing Function
 *
 * Performs one of the sorting algorithms.
 *    @param SortingFunction(): A sorting algorithm in the Sorter class
 *    @return sorted_vector: The vector after sorting */

std::vector<int> Sorter::TestAlgorithm(std::vector<int>(Sorter::*SortingFunction)(int, int))
{
   std::cout << "Sorting vector ";
   PrintVector(int_list);
   
   // Sorts the vector with one of the sorting functions specified in the Sorter class.
   //    Because of this implementation, other sorting algorithms could easily be implemented.
   std::vector<int> sorted_vector = (this->*SortingFunction)(0, int_list.size()-1);

   std::cout << "After: ";
   PrintVector(sorted_vector);

   return sorted_vector;
}

/* Testing Function
 *
 * Performs one of the sorting algorithms.
 *    @param SortingFunction(): A sorting algorithm in the Sorter class
 *    @return sorted_vector: The vector after sorting */

std::vector<int> Sorter::TestAlgorithm(std::vector<int>(Sorter::*SortingFunction)())
{
   std::cout << "Sorting vector ";
   PrintVector(int_list);
   
   // Sorts the vector with one of the sorting functions specified in the Sorter class..
   //    Because of this implementation, other sorting algorithms could easily be implemented.
   std::vector<int> sorted_vector = (this->*SortingFunction)();

   std::cout << "After: ";
   PrintVector(sorted_vector);

   return sorted_vector;
}

/* Sorter Function
 *
 * Implements Bubble Sort to sort the vector 
 *    @return list_copy: the copy of int_list that is sorted */

std::vector<int> Sorter::BubbleSort()
{

   // making a copy so that int_list remains unchanged
   std::vector<int> list_copy = int_list;

   for (int outer_loop = 0; outer_loop < size; outer_loop++)
   {
      for (int inner_loop = 0; inner_loop < size - 1; inner_loop++)
      {
         if (list_copy[inner_loop] > list_copy[inner_loop + 1])
         {    
            std::swap(list_copy[inner_loop], list_copy[inner_loop + 1]);
         }
      }
   }

   return list_copy;

}

/* Sorter Function
 *
 * Implements Insertion Sort to sort the vector
 *    @return list_copy: the copy of int_list that is sorted */

std::vector<int> Sorter::InsertionSort()
{

   // making a copy so that int_list remains unchanged
   std::vector<int> list_copy = int_list;

   for (int list_pos = 1; list_pos < size; list_pos++)
   {
      int entry_to_sort = list_copy[list_pos];      
      int pos_to_check = list_pos - 1;

      while (pos_to_check >= 0 && entry_to_sort < list_copy[pos_to_check])
      {
         list_copy[pos_to_check + 1] = list_copy[pos_to_check];
         pos_to_check--;
      }

      pos_to_check++;
      list_copy[pos_to_check] = entry_to_sort;
   }
   
   return list_copy;
}

/* Sorter Function
 *
 * Implements Selection Sort to sort the vector
 *    @return list_copy: the copy of int_list that is sorted */

std::vector<int> Sorter::SelectionSort()
{
   // making a copy so that int_list remains unchanged
   std::vector<int> list_copy = int_list;
   
   for (int list_pos = 0; list_pos < size; list_pos++)
   {
      int min_pos = list_pos;

      for (int unsorted_list_pos = list_pos + 1; unsorted_list_pos < size; unsorted_list_pos++)
      {
         if (list_copy[unsorted_list_pos] < list_copy[min_pos])
         {
            min_pos = unsorted_list_pos;
         }
      }

      std::swap(list_copy[list_pos], list_copy[min_pos]);
   }

   return list_copy;
}

/* Sort Function
 *
 *    Recursively implements Merge Sort to sort the function 
 *       @param left: The start of the subarray 
 *       @param right: The end of the subarray
 *       @return sorted_list: the sorted list */

std::vector<int> Sorter::MergeSort(int left, int right)
{
   if (left == right)
   {
      std::vector<int> single_entry;
      single_entry.push_back(int_list[left]);
      return single_entry;
   }

   int mid = (left + right) / 2;
   
   // std::cout << "Calling MergeSort on left half (" << left << ", " << mid << ") :\n";
   std::vector<int> left_half = MergeSort(left, mid);
   // std::cout << "Done! left half = "; PrintVector(left_half);
   
   // std::cout << "Calling MergeSort on right half (" << mid + 1 << ", " << right << ") :\n";
   std::vector<int> right_half = MergeSort(mid+1, right);
   // std::cout << "Done! right half = "; PrintVector(right_half);
   
   // std::cout << "Merging both halves (" << left << "," << right << ") :\n";

   std::vector<int> sorted_list;
   int left_list_pos = 0, right_list_pos = 0;

   while (left_list_pos < left_half.size() && right_list_pos < right_half.size())
   {
      // std::cout << "left_list_pos = " << left_list_pos << ", right_list_pos = " << right_list_pos << "\n";
      if (left_half[left_list_pos] < right_half[right_list_pos])
      {
         // std::cout << "left_list_pos (" << left_half[left_list_pos] << ") < right_list_pos(" << right_half[right_list_pos] << ")\n";
         sorted_list.push_back(left_half[left_list_pos]);
         left_list_pos++;
      }
      else
      {
         // std::cout << "left_list_pos (" << left_half[left_list_pos] << ") > right_list_pos(" << right_half[right_list_pos] << ")\n";
         sorted_list.push_back(right_half[right_list_pos]);
         right_list_pos++;
      }
   } 
   
   while (left_list_pos < left_half.size())
   {
      sorted_list.push_back(left_half[left_list_pos]);
      left_list_pos++;
   }
   while (right_list_pos < right_half.size())
   {
      sorted_list.push_back(right_half[right_list_pos]);
      right_list_pos++;
   }
   
   return sorted_list;
}

/* Sort Helper Function
 *
 *    Partitions the subarray
 *       @param arr[]: the array
 *       @param low: the start of the subarray
 *       @param high: the end of the subarray 
 *       @return i: the partition value */ 

int Sorter::Partition(std::vector<int> sorted_list, int low, int high) 
{ 
   int pivot = sorted_list[high];
   int i = (low - 1);
  
   for (int j = low; j <= high - 1; j++) 
   { 
      if (sorted_list[j] <= pivot) 
      { 
         i++;
         std::swap(sorted_list[i], sorted_list[j]); 
      } 
   } 
   i++; 
   std::swap(sorted_list[i], sorted_list[high]); 
   return i; 
}
  
/* Sort Helper Function
 *
 * Creates a random pivot
 *    @param arr[]: the array
 *    @param low: the subarray start 
 *    @param high: the subarray end */

int Sorter::RandomPartition(std::vector<int> sorted_list, int low, int high) 
{ 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    std::swap(sorted_list[random], sorted_list[high]); 
  
    return Partition(sorted_list, low, high); 
} 
  
/* Sort Helper Function
 * 
 * Implements Quick Sort to sort the array
 *    @param arr[]: the array
 *    @param low: the subarray start
 *    @param high: the subarray end */

void Sorter::QuickSort(std::vector<int> sorted_list, int low, int high) 
{ 
   if (low < high) 
   { 
      int pivot = RandomPartition(sorted_list, low, high); 
  
      QuickSort(sorted_list, low, pivot - 1); 
      QuickSort(sorted_list, pivot + 1, high); 
   } 
} 

/* Sort Function
 *
 * Calls QuickSort */

std::vector<int> Sorter::CallQuickSort()
{
   std::vector<int> sorted_list = int_list;
   QuickSort(sorted_list, 0, sorted_list.size()-1);

   return sorted_list;
}

/* Sort Helper Function
 *
 * Gets the max of the array 
 *    @param list: the list being checked*/

int Sorter::GetMax(std::vector<int> list) {
   int max = list[0];
   for(int i = 1; i < list.size(); i++)
   {
      if(list[i] > max)
         max = list[i];
   }
   return max;
}

/* Sort Function
 * 
 * Implements Counting Sort to sort the array
 *    @param list: the list being sorted
 *    @param exp: the digit */

void Sorter::CountingSort(std::vector<int> list, int exp) 
{ 
   std::vector<int> output; // output array 
   output.reserve(list.size());
   int i, count[10] = {0}; 
  
   // Store count of occurrences in count[] 
   for (i = 0; i < list.size(); i++) 
   {
      count[ (list[i]/exp)%10 ]++; 
   }

   // Change count[i] so that count[i] now contains actual 
   //  position of this digit in output[] 
   for (i = 1; i < 10; i++) 
      count[i] += count[i - 1]; 
  
   // Build the output array 
   for (i = list.size() - 1; i >= 0; i--) 
   { 
      output[count[ (list[i]/exp)%10 ] - 1] = list[i]; 
      count[ (list[i]/exp)%10 ]--; 
   } 
  
   // Copy the output array to arr[], so that arr[] now 
   // contains sorted numbers according to current digit 
   for (i = 0; i < list.size(); i++) 
   {
        list[i] = output[i]; 
   }
} 
  
/* Sort Function
 *
 * Calls Radix Sort to sort the function
 *    @param list: the list being sorted */

void Sorter::RadixSort(std::vector<int> list) 
{ 
    // Find the maximum number to know number of digits 
    int m = GetMax(list); 
  
    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        CountingSort(list, exp); 
} 

/* Sort Helper Function
 *
 * Calls Radix Sort
 *    @return sorted_list: the sorted list */

std::vector<int> Sorter::CallRadixSort()
{
   std::vector<int> sorted_list = int_list;
   RadixSort(sorted_list);
   return sorted_list;
}
