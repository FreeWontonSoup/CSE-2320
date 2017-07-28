//
//  main.c
//  C
//
//  Created by Brandon Carter on 7/9/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int T, int lengthA, int lengthB, int max);

struct node
{
    char c;
    struct node* next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;

void sum(int max)
{
    int i = 0;
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *temp3 = (struct node*)malloc(sizeof(struct node));
    head3 = temp3;
    int remainder = 0;
    int sum = 0;
    while(i < max || sum != 0)
    {
        if((temp1 == NULL || temp2 == NULL) && sum != 0)
        {
            temp3->c = sum + '0';
            break;
        }
        int num1 = temp1->c - '0';
        int num2 = temp2->c - '0';
        sum = num1 + num2 + remainder;
        temp3->c = (sum % 10) + '0';
        sum = sum / 10;
        remainder = sum;
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(i < max-1 || sum != 0)
        {
            temp3->next = (struct node*)malloc(sizeof(struct node));
            temp3 = temp3->next;
        }
        i++;
    }
    temp3->next = NULL;
    temp1 = NULL;
    temp2 = NULL;
    temp3 = NULL;
    free(temp1);
    free(temp2);
    free(temp3);
}

void reverse(struct node **head)
{
    struct node *curr, *prev, *next;
    curr = *head;    //start current node at head
    prev = NULL;    //prev will begin as NULL bc first element will become the last and point to NULL
    while(curr != NULL)
    {
        next = curr->next;  //next becomes next element
        curr->next = prev;  //current now points to previous element
        prev = curr;        //now previous becomes the next element
        curr = next;        //current ='s next element, repeat until current reaches end and becomes NULL
    }
    *head = prev;    //head will now point at end making it the 1st element, linked list is reversed
    curr = NULL;
    prev = NULL;
    next = NULL;
    free(curr);
    free(prev);
    free(next);
}

void split(char a[], char b[], int max)
{
    int i;
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    struct node *temp2 = (struct node*)malloc(sizeof(struct node));
    head1 = temp1;
    head2 = temp2;
    for(i = 0; i < max-1; i++)
    {
        temp1->c = a[i];
        temp1->next = (struct node*)malloc(sizeof(struct node));
        temp1 = temp1->next;
    }
    temp1->c = a[i];
    temp1->next = NULL;
    
    for(i = 0; i < max-1; i++)
    {
        temp2->c = b[i];
        temp2->next = (struct node*)malloc(sizeof(struct node));
        temp2 = temp2->next;
    }
    temp2->c = b[i];
    temp2->next = NULL;
    temp1 = NULL;
    temp2 = NULL;
    free(temp1);
    free(temp2);
}

int fill(char a[], char b[], int lengthA, int lengthB)
{
    int i, max, dif;
    
    if(lengthA > lengthB)
    {
        max = lengthA;
        dif = max - lengthB;
        for(i = lengthB - 1; i >= -1; i--)
        {
            b[i+dif] = b[i];
        }
        for(i = 0; i < dif; i++)
        {
            b[i] = '0';
        }
    }
    else
    {
        max = lengthB;
        dif = max - lengthA;
        for(i = lengthA - 1; i >= -1; i--)
        {
            a[i+dif] = a[i];
        }
        for(i = 0; i < dif; i++)
        {
            a[i] = '0';
        }

    }
    return max;
}

void input()
{
    int i, T;
    scanf("%d",&T);
    for(i = 1; i <= T; i++)
    {
        char a[5001], b[5001];
        scanf("%s %s",a,b);
        int lengthA = (int)strlen(a);
        int lengthB = (int)strlen(b);
        int max = fill(a,b,lengthA,lengthB);
        split(a,b,max);
        reverse(&head1);
        reverse(&head2);
        sum(max);
        reverse(&head1);
        reverse(&head2);
        reverse(&head3);
        print(i,lengthA,lengthB,max);
    }
    
}

void print(int T, int lengthA, int lengthB, int max)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    struct node *temp3 = head3;
    printf("Case #%d:\n",T);
    int i = 0;
    int difA = max - lengthA;
    int difB = max - lengthB;
    while(temp1 != NULL)
    {
        if(i >= difA)
        {
            printf("%c ",temp1->c);
            if(temp1->next != NULL)
            {
                printf("-> ");
            }
        }
        temp1 = temp1->next;
        i++;
    }
    printf("\n");
    i = 0;
    while(temp2 != NULL)
    {
        if(i >= difB)
        {
            printf("%c ",temp2->c);
            if(temp2->next != NULL)
            {
                printf("-> ");
            }
        }
        temp2 = temp2->next;
        i++;
    }
    printf("\n");
    while(temp3 != NULL)
    {
        printf("%c ",temp3->c);
        if(temp3->next != NULL)
        {
            printf("-> ");
        }
        temp3 = temp3->next;
    }
    printf("\n");
    temp1 = NULL;
    temp2 = NULL;
    temp3 = NULL;
    free(temp1);
    free(temp2);
    free(temp3);
}

int main(void)
{
    input();
    return 0;
}
