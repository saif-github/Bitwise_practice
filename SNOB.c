/**********Problem Statement*******************************
------Next higher number with same number of set bits----

Given a number x, find next number with same number of 1 bits in it’s binary representation.

EXAMPLE:

x = 156

x = 10011100

Part 1:  00011100 - Right Most Bit Pattern

00011100 - right most string of 1's in x
00000011 - right shifted pattern except left most bit ------> [A]

00010000 - isolated left most bit of right most 1's pattern
00100000 - shiftleft-ed the isolated bit by one position ------> [B]

Part 2:
10000000 - left part of x, excluding right most 1's pattern ------> [C]

Part 3 :
10100000 - add B and C (OR operation) ------> [D]

Part 4 :
10100011 - add A and D which is required number 163


**********************************************************/


#include<stdio.h>
#include<string.h>

// this function returns next higher number with same number of set bits as x. 
unsigned int snoob(unsigned int  x) 
{ 
  
  unsigned int rightOne; 
  unsigned int nextHigherOneBit; 
  unsigned int rightOnesPattern; 
  
  unsigned int next = 0; 
  
  if(x) 
  {
    // right most set bit 
    rightOne = x & -(signed)x; 
  
    // reset the pattern and set next higher bit 
    // left part of x will be here 
    nextHigherOneBit = x + rightOne; //........part [D]
  
    // nextHigherOneBit is now part [D] of the above explanation. 
  
    // isolate the pattern
    rightOnesPattern = x ^ nextHigherOneBit; 
  
    // right adjust pattern 
    rightOnesPattern = (rightOnesPattern)/rightOne; 
  
    // correction factor 
    rightOnesPattern >>= 2;	   //.........part [A]
  
    // rightOnesPattern is now part [A] of the above explanation. 
  
    // integrate new pattern (Add [D] and [A])  
    next = nextHigherOneBit | rightOnesPattern; 
  } 
  
  return next; 
} 

int main() 
{ 
  int x = 156; 
  printf("Next higher number with same number of set bits is %d ",snoob(x)); 
  printf("\r\n"); 
  
  getchar(); 
  return 0; 
}


