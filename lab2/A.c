//
//  main.c
//  A
//
//  Created by Brandon Carter on 6/23/17.
//  Copyright © 2017 Brandon Carter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputter();
void get_input(char word[], int *heapSize);
void print(int heapSize);
void restart(int *heapSize, int *length);
void build_max_heap(int heapSize);
void max_heapify(int i, int heapSize);
void build_min_heap(int heapSize);
void min_heapify(int i, int heapSize);
void heap_sort_max(int heapSize);
void heap_sort_min(int heapSize);
void heap_size(int heapSize);
void print_max_item(int heapSize);
void insert_max(char word[], int *heapSize);
void insert_min(char word[], int *heapSize);
void check_min(int i, int heapSize);
void check_max(int i, int heapSize);
void del_max(int *heapSize);
void del_min(int *heapSize);

char arr[1000][51];

void del_min(int *heapSize)
{
    build_min_heap(*heapSize);
    strcpy(arr[0],arr[*heapSize]);
    //strcpy(arr[*heapSize],"");
    (*heapSize)--;
    build_min_heap(*heapSize);
}

void del_max(int *heapSize)
{
    build_max_heap(*heapSize);
    strcpy(arr[0],arr[*heapSize]);
    //strcpy(arr[*heapSize],"");
    (*heapSize)--;
    build_max_heap(*heapSize);
}

void check_max(int i, int heapSize)
{
    int left = 2*i+1;
    int right = 2*i+2;
    if(i < (heapSize / 2) + 1 && left <= heapSize && strcmp(arr[left],arr[i]) > 0)
    {
        printf("Max-heap: FALSE\n");
        return;
    }
    if(i < (heapSize / 2) + 1 && right <= heapSize && strcmp(arr[right],arr[i]) > 0)
    {
        printf("Max-heap: FALSE\n");
        return;
    }
    if(i < (heapSize / 2) + 1)
    {
        check_max(++i,heapSize);
        return;
    }
    printf("Max-heap: TRUE\n");
}

void check_min(int i, int heapSize)
{
    int left = 2*i+1;
    int right = 2*i+2;
    if(i < (heapSize / 2) + 1 && left <= heapSize && strcmp(arr[left],arr[i]) < 0)
    {
        printf("Min-heap: FALSE\n");
        return;
    }
    if(i < (heapSize / 2) + 1 && right <= heapSize && strcmp(arr[right],arr[i]) < 0)
    {
        printf("Min-heap: FALSE\n");
        return;
    }
    if(i < (heapSize / 2) + 1)
    {
        check_min(++i,heapSize);
        return;
    }
    printf("Min-heap: TRUE\n");
}

void insert_min(char word[], int *heapSize)
{
    (*heapSize)++;
    strcpy(arr[*heapSize],word);
    build_min_heap(*heapSize);
}

void insert_max(char word[], int *heapSize)
{
    (*heapSize)++;
    strcpy(arr[*heapSize],word);
    build_max_heap(*heapSize);
}

void print_min_item(int heapSize)
{
    heap_sort_min(heapSize);
    printf("Min item: %s\n",arr[heapSize]);
}

void print_max_item(int heapSize)
{
    heap_sort_max(heapSize);
    printf("Max item: %s\n",arr[heapSize]);
}

void heap_sort_min(int heapSize)
{
    int i;
    build_min_heap(heapSize);
    for(i = heapSize+1; i > 1; i--)
    {
        char temp[51];
        strcpy(temp,arr[0]);
        strcpy(arr[0],arr[i-1]);
        strcpy(arr[i-1],temp);
        heapSize--;
        min_heapify(0,heapSize);
    }
}

void heap_sort_max(int heapSize)
{
    int i;
    build_max_heap(heapSize);
    for(i = heapSize+1; i > 1; i--)
    {
        char temp[51];
        strcpy(temp,arr[0]);
        strcpy(arr[0],arr[i-1]);
        strcpy(arr[i-1],temp);
        heapSize--;
        max_heapify(0,heapSize);
    }
}

void build_min_heap(int heapSize)
{
    int i;
    for(i = heapSize / 2; i >= 0; i--)
    {
        min_heapify(i,heapSize);
    }
}

void min_heapify(int i, int heapSize)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = 0;
    if(left <= heapSize && strcmp(arr[left],arr[i]) < 0)
    {
        smallest = left;
    }
    else
    {
        smallest = i;
    }
    if(right <= heapSize && strcmp(arr[right],arr[smallest]) < 0)
    {
        smallest = right;
    }
    if(smallest != i)
    {
        char temp[51];
        strcpy(temp,arr[i]);
        strcpy(arr[i],arr[smallest]);
        strcpy(arr[smallest],temp);
        min_heapify(smallest,heapSize);
    }
    
}

void build_max_heap(int heapSize)
{
    int i;
    for(i = heapSize / 2; i >= 0; i--)
    {
        max_heapify(i,heapSize);
    }
}

void max_heapify(int i, int heapSize)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = 0;
    if(left <= heapSize && strcmp(arr[left],arr[i]) > 0)
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if(right <= heapSize && strcmp(arr[right],arr[largest]) > 0)
    {
        largest = right;
    }
    if(largest != i)
    {
        char temp[51];
        strcpy(temp,arr[i]);
        strcpy(arr[i],arr[largest]);
        strcpy(arr[largest],temp);
        max_heapify(largest,heapSize);
    }
    
}

void heap_size(int length)
{
    printf("Heapsize = %d\n",length);
}

void restart(int *heapSize, int *length)
{
    *heapSize = -1;
    *length = 0;
    //memset(arr,NULL,sizeof(arr[0][0]) * 1000 * 51);
}

void print(int heapSize)
{
    int i;
    printf("Here is the current array:\n");
    for(i = 0; i <= heapSize; i++)
    {
        printf("%s\n",arr[i]);
    }
}

void get_input(char word[], int *heapSize)
{
    (*heapSize)++;
    strcpy(arr[*heapSize],word);
}

void inputter()
{
    char input[2001];
    int heapSize = -1;
    int length = 0;
    int i = 0;
    while(i < 1000)
    {
        fgets(input, sizeof(input), stdin);
        char *command = strtok(input," \n");
        //printf("%d: %s\n\n",i+1,command);
        char *word = strtok(NULL," \n");
        //char *word2 = strtok(NULL,"\n");
        
        if(strcmp(command,"INPUT") == 0)
        {
            get_input(word, &heapSize);
        }
        else if(strcmp(command,"PRINT") == 0)
        {
            print(heapSize);
        }
        else if(strcmp(command,"RESTART") == 0)
        {
            restart(&heapSize,&length);
        }
        else if(strcmp(command,"HEAPSIZE") == 0)
        {
            heap_size(length);
        }
        else if(strcmp(command,"BUILD-MAX-HEAP") == 0)
        {
            build_max_heap(heapSize);
            length = heapSize+1;
        }
        else if(strcmp(command,"BUILD-MIN-HEAP") == 0)
        {
            build_min_heap(heapSize);
            length = heapSize+1;
        }
        else if(strcmp(command,"HEAPSORT-MAX") == 0)
        {
            heap_sort_max(heapSize);
            length = heapSize+1;
        }
        else if(strcmp(command,"HEAPSORT-MIN") == 0)
        {
            heap_sort_min(heapSize);
            length = heapSize+1;
        }
        else if(strcmp(command,"PRINT-MAX-ITEM") == 0)
        {
            print_max_item(heapSize);
        }
        else if(strcmp(command,"PRINT-MIN-ITEM") == 0)
        {
            print_min_item(heapSize);
        }
        else if(strcmp(command,"INSERT-MAX") == 0)
        {
            insert_max(word,&heapSize);
            length = heapSize+1;
        }
        else if(strcmp(command,"INSERT-MIN") == 0)
        {
            insert_min(word,&heapSize);
            length = heapSize+1;
        }
        else if(strcmp(command,"CHECK-MIN") == 0)
        {
            check_min(0, heapSize);
        }
        else if(strcmp(command,"CHECK-MAX") == 0)
        {
            check_max(0, heapSize);
        }
        else if(strcmp(command,"DELETE-MAXIMUM") == 0)
        {
            del_max(&heapSize);
            length--;
        }
        else if(strcmp(command,"DELETE-MINIMUM") == 0)
        {
            del_min(&heapSize);
            length--;
        }
        i++;
    }
}

int main(void)
{
    //FILE *in;
    //in = freopen("aa.txt","r",stdin);
    inputter();
    //fclose(in);
    return 0;
}
