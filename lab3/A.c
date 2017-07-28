//
//  main.c
//  A
//
//  Created by Brandon Carter on 7/7/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>

int checkPop(int A[], int nums);
void input();
void push(int s[], int num);
int isEmpty(int s[]);
void pop();
int peek(int s[]);

int top = -1;

void input()
{
    int T, i, j, nums;
    scanf("%d",&T);
    for(i = 1; i <= T; i++)
    {
        scanf("%d",&nums);
        int A[nums];
        for(j = 0; j < nums; j++)
        {
            scanf("%d",&A[j]);
        }
        int check = checkPop(A,nums);
        if(check == 1)
        {
            printf("Case #%d: Yes\n",i);
        }
        else
        {
            printf("Case #%d: No\n",i);
        }
        top = -1;
    }
    
}

int checkPop(int A[], int size)
{
    int i = 1, j = 0, n;
    n = size;
    int stack[n];
    while(i <= n || j < n)
    {
        if(isEmpty(stack) == 1)
        {
            push(stack,i);
            i++;
        }
        else if(peek(stack) == A[j])
        {
            pop(stack);
            j++;
        }
        else if(peek(stack) > A[j])
        {
            return 0;
        }
        else
        {
            push(stack,i);
            i++;
        }
    }
    return 1;
}

int peek(int s[])
{
    return s[top];
}

int isEmpty(int s[])
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int s[], int num)
{
    s[++top] = num;
}

void pop()
{
    top--;
}

int main(void)
{
    //FILE *in;
    //in = freopen("qa.txt","r",stdin);
    input();
    //fclose(in);
    return 0;
}
