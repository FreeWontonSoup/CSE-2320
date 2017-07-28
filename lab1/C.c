//
//  main.c
//  C
//
//  Created by Brandon Carter on 6/9/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>

void input()
{
    int T, i = 0, N = 0, k;
    //printf("Enter how many test cases: ");
    scanf("%d",&T);
    while(i < T)
    {
        //printf("Enter number of websites: ");
        scanf("%d",&N);
        char websites[N][201];
        int relevance[N];
        for(k = 0; k < N; k++)
        {
            scanf("%s %d",websites[k],&relevance[k]);
            /*
            if(relevance[k] < 1 || relevance[k] > 100)
            {
                k--;
                printf("That relevance value is not valid, please try again.\n");
            }
             */
        }
        int max = relevance[0];
        for(k = 1; k < N; k++)
        {
            if(relevance[k] > max)
            {
                max = relevance[k];
            }
        }
        printf("\n\nCase #%d: \n",i+1);
        for(k = 0; k < N; k++)
        {
            if(relevance[k] == max)
            {
                printf("%s\n",websites[k]);
            }
        }
        i++;
        printf("\n\n");
    }
        
}

int main()
{
    input();
    return 0;
}
