//
//  main.c
//  A
//
//  Created by Brandon Carter on 6/8/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>

void lockInputs()
{
    int locks[4];
    int total = 0, run = 0;
    
    while(run != -1)
    {
        //printf("Enter the 4 numbers for the lock in one line as so # # # #: ");
        scanf("%d %d %d %d",&locks[0],&locks[1],&locks[2],&locks[3]);
        
        /*
        if(locks[0] >= 40 || locks[1] >= 40 || locks[2] >= 40 || locks[3] >= 40 || locks[0] < 0 || locks[1] < 0 || locks[2] < 0 || locks[3] < 0)
        {
            printf("One of the numbers entered is invalid. Please try again.\n");
        }
         */
        
        run = -1;
        total += 120;
        if(locks[0] > locks[1])
        {
            total += locks[0] - locks[1];
        }
        else if(locks[0] < locks[1])
        {
            total += 40 - locks[1] + locks[0];
        }
                    
        if(locks[2] > locks[1])
        {
            total += locks[2] - locks[1];
        }
        else if(locks[2] < locks[1])
        {
            total += 40 - locks[1] + locks[2];
        }
            
        if(locks[2] > locks[3])
        {
            total += locks[2] - locks[3];
        }
        else if(locks[2] < locks[3])
        {
            total += locks[2] + 40 - locks[3];
        }
            
        total *= 9;
        printf("%d\n",total);
        
    }
}

int main(void)
{
    int N, i;
    //printf("Enter number of test cases: ");
    scanf("%d",&N);
    for(i = 0; i < N; i++)
    {
        lockInputs();
    }
    return 0;
}
