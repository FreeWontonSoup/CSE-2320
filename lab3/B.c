//
//  main.c
//  B2
//
//  Created by Brandon Carter on 7/13/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int G;
    int num;
    struct node* next;
};

struct data
{
    int G;
    int num;
};

struct node* head = NULL;

void print2(struct data Q[], int top, int rear);

void dequeue(struct data Q[], int top)
{
    printf("%d\n",Q[top].num);
}

void enqueue(struct data Q[], int num, int top, int rear)
{
    struct node *temp = head;
    int key = -1;
    while(temp != NULL)
    {
        if(temp->num == num)
        {
            key = temp->G;
            break;
        }
        temp = temp->next;
    }
    int i, spot = 0;
    for(i = top; i < rear; i++)
    {
        if(Q[i].G == key)
        {
            spot = i+1;
        }
    }
    if(spot == 0)
    {
        Q[rear].G = key;
        Q[rear].num = num;
    }
    else
    {
        for(i = rear; i >= spot - 1; i--)
        {
            Q[i+1].G = Q[i].G;
            Q[i+1].num = Q[i].num;
        }
        Q[spot].num = num;
    }
    temp = NULL;
    free(temp);
}

void input()
{
    int i, j, T, r;
    scanf("%d",&T);
    struct node* temp = NULL;
    for(r = 1; r <= T; r++)
    {
        int G, nums, top = 0;
        scanf("%d",&G);
        temp = (struct node*)malloc(sizeof(struct node));
        head = temp;
        for(i = 0; i < G; i++)
        {
            scanf("%d",&nums);
            for(j = 0; j < nums; j++)
            {
                temp->G = i+1;
                scanf("%d",&(temp->num));
                top++;
                if(i != G - 1 || j != nums - 1)
                {
                    temp->next = (struct node*)malloc(sizeof(struct node));
                    temp = temp->next;
                }
            }
        }
        temp->next = NULL;
        struct data Q[top];
        for(i = 0; i < top; i++)
        {
            Q[i].G = 0;
        }
        int casee = 0;
        top = 0;
        int rear = -1;
        while(1)
        {
            char com[20];
            fgets(com,20,stdin);
            if(strcmp(com, "\n") == 0)
            {
                fgets(com,20,stdin);
            }
            char *word1 = strtok(com," \n");
            char *word2 = strtok(NULL,"\n");
            int num;
            
            if(strcmp(word1,"ENQUEUE") == 0)
            {
                if(rear == top-1 && rear != 0 && top != 0)
                {
                    top = 0;
                    rear = -1;
                }
                rear++;
                num = atoi(word2);
                enqueue(Q,num,top,rear);
                //print2(Q,top,rear);
            }
            else if(strcmp(word1,"DEQUEUE") == 0)
            {
                if(casee == 0)
                {
                    printf("Case #%d:\n",r);
                    casee++;
                }
                dequeue(Q,top);
                top++;
            }
            else if(strcmp(word1,"DONE") == 0)
            {
                break;
            }
        }
    }
    
    while(head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    
}

void print()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d: %d ",temp->G,temp->num);
        temp = temp->next;
    }
    temp = NULL;
    free(temp);
}

/*void print2(struct data Q[], int top, int rear)
{
    int i;
    for(i = top; i <= rear; i++)
    {
        printf("G-%d: %d ",Q[i].G,Q[i].num);
        printf("\n");
    }
    printf("\n");
}*/

int main(void)
{
    //FILE *in;
    //in = freopen("input.txt","r",stdin);
    input();
    //fclose(in);
    //print();
    return 0;
}
