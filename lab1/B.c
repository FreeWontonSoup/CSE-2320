//
//  main.c
//  B
//
//  Created by Brandon Carter on 6/9/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calc()
{
    char time[6];
    double degree;
    int hour, min;
    while(1)
    {
        //printf("Enter the time: ");
        scanf("%s",time);
        char *s1 = strtok(time,":");
        char *s2 = strtok(NULL,":");
        hour = atoi(s1);
        min = atoi(s2);
        if(min == 0 && hour == 0)
        {
            exit(0);
        }
        /*
        else if(hour > 12 || hour <= 0 || min >= 60 || min < 0)
        {
            printf("Error, invalid hour/minute, please try again.\n");
        }
         */
        else
        {
            break;
        }
    }
    
    
    degree = min + (5*(12-hour) - (min/60.0)*(5));
    degree *= 6;
    if(degree > 180)
    {
        degree = abs(360 - degree);
    }
    printf("%.3f\n",degree);
}

int main(void)
{
    while(1)
    {
        calc();
    }
    return 0;
}
