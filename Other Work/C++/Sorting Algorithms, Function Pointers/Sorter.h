// Domenico D'Erasmo
// 19 January 2020
// CISC 4080 - Lab 1
// Interface file for Sorter class

#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>

class Sorter
{

public:

   // Constants
   static const std::string sort_names[6];

   // Constructor
   Sorter(int input_size);
   Sorter(std::vector<int> int_list);

   // Helper Functions
   void GenerateRandomVector();
   void PrintVector(const std::vector<int>& list_to_print);
   std::vector<int> Slice(int start, int range);

   // Sort Helper Functions
   int Partition(std::vector<int> sorted_list, int low, int high);
   int RandomPartition(std::vector<int> sorted_list, int low, int high);
   void QuickSort(std::vector<int> sorted_list, int low, int hight);
   void RadixSort(std::vector<int> list);
   int GetMax(std::vector<int> list);

   // Accessors
   std::vector<int> GetList();
   int GetSize();

   // Mutators
   void SetList(std::vector<int> input_list);

   // Testing Function
   std::vector<int> TestAlgorithm(std::vector<int>(Sorter::*SortingFunction)());
   std::vector<int> TestAlgorithm(std::vector<int>(Sorter::*SortingFunction)(int, int));

   // Sorting Algorithms
   std::vector<int> BubbleSort();
   std::vector<int> InsertionSort();
   std::vector<int> SelectionSort();
   
   std::vector<int> MergeSort(int left, int right);
   std::vector<int> CallQuickSort();
   std::vector<int> CallRadixSort();
   void CountingSort(std::vector<int> list, int exp);

private:

   std::vector<int> int_list;
   int size;
};

#endif
