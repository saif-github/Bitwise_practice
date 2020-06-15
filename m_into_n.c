/*
Inserting m into n such that m starts at bit j and ends at bit i.

1. Clear the bits j through i in n 

2. Shift m so that it lines up with bits j through i 

3. Return Bitwise AND of m and n. 
*/

// C program for implementation of updateBits() 
#include <stdio.h>
  
// Function to updateBits M insert to N. 
int updateBits(int n, int m, int i, int j) 
{
    /* Create a mask to clear bits i through j 
      in n. EXAMPLE: i = 2, j = 4. Result 
      should be 11100011. For simplicity, we'll 
      use just 8 bits for the example. */
  
    int allOnes = ~0; // will equal sequence of all ls 
  
    // ls before position j, then 0s. left = 11100000 
    int left= allOnes << (j + 1); 
  
    // l's after position i. right = 00000011 
    int right = ((1 << i) - 1); 
  
    // All ls, except for 0s between i and j. mask 11100011 
    int mask = left | right; 
  
    /* Clear bits j through i then put min there */
    int n_cleared = n & mask; // Clear bits j through i. 
    int m_shifted = m << i;   // Move m into correct position. 
  
    return (n_cleared | m_shifted); // OR them, and we're done! 
}

// Function to updateBits M insert to N. 
int updateBits_2(int n, int m, int i, int j) 
{
	int masked_bits = j - i;
	int Mask = 0;

  	while(masked_bits){
		Mask <<= 1;
		masked_bits--;
	}
	Mask <<= i;
  	Mask = ~Mask;
  
    /* Clear bits j through i then put min there */
    int n_cleared = n & Mask; // Clear bits j through i.
    int m_shifted = m << i;   // Move m into correct position.
  
    return (n_cleared | m_shifted); // OR them, and we're done! 
}



// Driver Code 
int main() 
{ 
    int n = 1024; // in Binary N= 10000000000 
    int m = 19;   // in Binary M= 10011 
    int i = 2, j = 6; 
  
    printf("Result = %d\n",updateBits(n,m,i,j));
    printf("Result = %d\n",updateBits_2(n,m,i,j));
  
    return 0; 
} 
