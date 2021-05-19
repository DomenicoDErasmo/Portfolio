#include <iostream>
#include <bitset>
#include <vector>
#include <time.h>

const double BILLION = 1E9;

/* Print ALL pairs of number from the given array a[0...a_len-1] that adds up to K 
    @param intList: the list of int values 
    @param K: the sum we want to make
*/

void PairsAddupToK (int a[], int a_len,  int K)
{
   for (int first_number = 0; first_number < a_len; first_number++)
   {
      for (int second_number = first_number + 1; second_number < a_len; second_number++)
      {
         if (a[first_number] + a[second_number] == K)
         {
            std::cout << a[first_number] << " + " << a[second_number] << " = " << K << ".\n";
         }
      }
   }
}
   
/* Print ALL triples of numbers from the given array a[0...a_len-1] that adds up to K 
    @param intList: the list of int values 
    @param K: the sum we want to make
*/

void TriplesAddupToK (int a[], int a_len, int K)
{
   for (int first_number = 0; first_number < a_len; first_number++)
   {
      for (int second_number = first_number + 1; second_number < a_len; second_number++)
      {
         for (int third_number = first_number+1; third_number <  a_len; third_number++)   
         {
            if (a[second_number] + a[third_number] == K - a[first_number])
            {
               std::cout << a[first_number] << " + " << a[second_number] << " + " << a[third_number] << " = " << K << ".\n";
            }
         }
      }
   }
}
   
/* Raises a base to a power using binary exponentiation
    returns result: the base raised to the power
    @param base: the number being exponentiated
    @param exponent: the number of times to multiply base
*/

int Power(int base, int exponent)
{
   int result = 1;
   while (exponent > 0)
   {
      if (exponent % 2 == 0)
      {
         exponent /= 2;
         base = base * base;
      }
      else
      {
         exponent--;
         result *= base;
         exponent /= 2;
         base = base * base;
      }
   }
   return result;

}

/* Print ALL subsets of numbers from the given array, a[0...a_len-1 that adds up to K 
    this function solves the problem iteratively 
   NOTE: WE assume a_len<32 (so that we can use int (which uses 32 or 64 bits) 
    as code to decide subset  
    @param intList: the list of int values 
    @param K: the sum we want to make
*/

void SubsetsAddupToK (int a[], int a_len, int K)
{
   int num_subsets = Power(2, a_len);
   int binary_places[a_len];

   for (int subset = 0; subset < num_subsets; subset++)
   {
      int sum = 0;
      int subset_val = subset;

      // ordering subsets in binary
      //   1. start with binary_places as all 1's
      //   2. for every multiple of 2 larger than subset, set the leftmost current 1 to 0
      //   3. if subset >= current multiple of 2, subtract 2^(1 position) and restart
      
      // step 1
      for (int position = 0; position < a_len; position++)
      {
         binary_places[position] = 1;
      }

      // steps 2 and 3
      for (int digit = a_len - 1; digit >= 0; digit--)
      {
         if (subset_val < Power(2, digit))
            binary_places[a_len - digit] = 0;
         else
            subset_val -= Power(2, digit);
      }

      std::vector<int> results;

      // adding the subset up
      for (int array_pos = 0; array_pos < a_len; array_pos++)
      {
         if (binary_places[a_len - array_pos] == 1)
         {
            sum += a[array_pos];
            results.push_back(a[array_pos]);
         } 
      }
      
      // finish print statement
      if (sum == K)
      {
         for (int results_pos = 0; results_pos < results.size(); results_pos++)
         {
            std::cout << results[results_pos] << " + ";
         }
         std::cout << " = " << K << ".\n";
      }
   }
}

	    
	
// Recursive solution to SubsetAddupToK 

/* This functions tries to use numbers from a[left...right] to make sum 
     @param a[] array of int
     @n: a[left...right] is the list of numbers to use
     @currentSum: current sum we have made using numbers in numsUsed
     @finalSum: final sum that we need to make
     @numsUsed: numbers that are used to get us here 
*/

bool SubsetsAddupToK (int a[], int left, int right, int currentSum, int finalSum, std::vector<int> numsUsed)
{
   //Three base cases: 
   //case 1: what remains to make is negative: we have overshot... 
   if (currentSum>finalSum)
      return false; 

   //case 2: we made it! 
   // Result is only displayed at the base case. 
   if (currentSum==finalSum)
   {
      std::cout <<"Solution:";
      for (int i=0;i<numsUsed.size();i++)
         std::cout << numsUsed[i] << ",";
      std::cout << std::endl;
      return true;
   }

   //case 3: we don't have any number to use: fails. 
   if (left>right && currentSum < finalSum)
      return false;

   //General case: what remains to make is positive, and we have numbers to use 
   bool res1=false, res2=false;

   // Explore both possibilities: Use a[left] or not 
   //  1) include a[left] in the sum, i.e., make sum-a[left] using a[left+1...right]  
   if (a[left]+currentSum<=finalSum) //if adding a[left] will not overshoot... 
   {
      std::vector<int> newNums = numsUsed;
      newNums.push_back (a[left]); //now a[left] is used ... 

      // here the currentSum is increased by a[left], a[left] is added into list of 
      //    numbers used... 
      res1 = SubsetsAddupToK(a, left+1, right, currentSum+a[left], finalSum,newNums);
   }

   //  2) do not include a[left] in the sum, i.e., make sum using a[left+1...right]  
   //     currentSum, finalSum, numsUsed is not changed 

   //^+1 so that a[left] is not considered any more
   res2 = SubsetsAddupToK (a, left+1, right, currentSum, finalSum, numsUsed);

   //if either of the above two succeeded, return true 
   if (res1 || res2)
      return true;
   else
      return false;
}


/* Compare the running time of three functions for input size n 
 @param n: the length of vecotr/list
 */ 
void  MeasureRunningTime (int a[], int a_len)
{
   struct timespec start, finish;
   double r1, r2, r3, r4;


   clock_gettime (CLOCK_REALTIME, &start);
   PairsAddupToK (a, a_len, 100);
   clock_gettime (CLOCK_REALTIME, &finish);
   r1 = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec-start.tv_nsec)/BILLION;


   clock_gettime (CLOCK_REALTIME, &start);
   TriplesAddupToK (a, a_len, 100);
   clock_gettime (CLOCK_REALTIME, &finish);
   r2 = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec-start.tv_nsec)/BILLION;

   clock_gettime (CLOCK_REALTIME, &start);
   SubsetsAddupToK (a, a_len, 100); 
   clock_gettime (CLOCK_REALTIME, &finish);
   r3 = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec-start.tv_nsec)/BILLION;

   clock_gettime (CLOCK_REALTIME, &start);
   std::vector<int> results;
   
   // current sum=0, final sum=100
   SubsetsAddupToK (a, 0, a_len, 0, 100, results); 
   clock_gettime (CLOCK_REALTIME, &finish);
   r4 = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec-start.tv_nsec)/BILLION;

   std::cout <<"n="<<a_len<<"\t";
   std::cout <<"Pairs"<<"\t"<< r1<<"s\t";
   std::cout <<"Triples"<<"\t"<< r2<<"s\t";
   std::cout <<"Subsets"<<"\t"<< r3<<"s\t";
   std::cout <<"SubsetsR"<<"\t"<< r4 <<"s\t"<<std::endl;
}

int main()
{
   std::vector<int> numsUsed; //this is empty initially 

   int a5[5] = {50,90,20,30,10};
   int a10[10] = {50, 33, 90, 2, 20, 72, 30,10, 92, 8};
   int a20[20] = {50, 33, 11, 79, 90, 2, 20, 72, 30,10, 
		92, 8, 99, 101, 25, 71, 48, 72, 35, 9};
   int a30[30] = {50, 33, 11, 79, 90, 2, 20, 72, 30,10, 
		92, 8, 99, 101, 25, 71, 48, 72, 35, 9,
		37, 41, 55, 73, 67, 66, 22, 11, 6, 4};

   //Testing 
   //Display all different ways to make 100 using a5[0...4]
   int SumToMake = 100;
   int curSum=0; 
   SubsetsAddupToK (a5, 0, 4, curSum, SumToMake, numsUsed);

   /* Measuring and comparing running time  */
   MeasureRunningTime (a5, 5);
   MeasureRunningTime (a10, 10);
   MeasureRunningTime (a20, 20);
   MeasureRunningTime (a30, 30);
}
