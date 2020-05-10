#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*********Problem Statement****************************
Find Duplicates of array using bit array
You have an array of N numbers, where N is at most 32,000. 
The array may have duplicates entries and you do not know what N is. 
With only 4 Kilobytes of memory available,
how would print all duplicates elements in the array ?.

Examples:

Input : arr[] = {1, 5, 1, 10, 12, 10}
Output : 1 10
1 and 10 appear more than once in given
array.

Input : arr[] = {50, 40, 50}
Output : 50
*******************************************************/


   // Devide by 32. To store n bits, we need 
   // n/32 + 1 integers (Assuming int is stored 
   // using 32 bits) 
   //32000/32 = 1000 +1 = 1001
   unsigned int arr[1001]; 


// Get value of a bit at given position 
    bool get(int pos) 
    { 
        // Divide by 32 to find position of 
        // integer. 
        int index = (pos >> 5); 
  
        // Now find bit number in arr[index] 
        int bitNo = (pos & 0x1F); 
  
        // Find value of given bit number in 
        // arr[index] 
        return (arr[index] & (1 << bitNo)) != 0; 
    } 
  
    // Sets a bit at given position 
    void set(int pos) 
    { 
        // Find index of bit position 
        int index = (pos >> 5); 
  
        // Set bit number in arr[index] 
        int bitNo = (pos & 0x1F); 
        arr[index] |= (1 << bitNo); 
    } 

    // Main function to print all Duplicates 
    void checkDuplicates(int arr[], int n) 
    { 
        // Traverse array elements 
        for (int i = 0; i < n; i++) 
        { 
            // Index in bit array 
            int num = arr[i]; 
  
            // If num is already present in bit array 
            if (get(num)) 
                printf("Already present = %d\n", num);
  
            // Else insert num 
            else
                set(num); 
        } 
    }

// Driver code 
int main() 
{ 
    int arr[] = {1, 5, 1, 10, 12, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
 
    checkDuplicates(arr, n); 
    return 0; 
} 

/*
 We can create a bit with 32000 bits, where each bit represents one integer.

Using this bit vector, we can then iterate through the array, 
flagging each element v by setting bit v to 1.
When we come across a duplicate element, we print it.

*/
