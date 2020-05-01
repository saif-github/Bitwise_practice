/*
 * reverse_bit.c
 *
 *  Created on: Mar 28, 2020
 *      Author: 7325588
 */

#include <stdio.h>

unsigned int reverseBits(unsigned int num)
{
    unsigned int count = sizeof(num) * 8 - 1;
    unsigned int reverse_num = num;

    num >>= 1;
    while(num)
    {
       reverse_num <<= 1;
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

int main()
{
    unsigned int x = 1;
    printf("%u", reverseBits(x));
    getchar();
}

/*
suppose 8 bit num

num = 0001 0101   ans = 1010 1000
rev_num = num

rev_num = 0001 0101 << 1

rev_num = 001 01010 | (num & 1)
rev_num = 001 01011
num = 0000 1010

rev_num = 0101 0110
rev_num = 0101 0110 | (num & 1)
rev_num = 0101 0110
num = 0000 0101

rev_num = 1010 1100
rev_num = 1010 1100 | (num & 1)
rev_num = 1010 1101
num = 0000 0010

rev_num = 0101 1010
rev_num = 0101 1010 | (num & 1)
rev_num = 0101 1010
num = 0000 0001

rev_num = 1011 0101
num = 0000 0000

rev_num = 1010 1000

*/

