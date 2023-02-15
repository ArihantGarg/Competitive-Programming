#include <bits/stdc++.h>
using namespace std;


typedef struct node
{
    int key;
    struct node* next;
}linklist;

linklist* createNode(int data)
{
    linklist* newNode=(linklist*)malloc(sizeof(linklist));
    newNode->key=data;
    newNode->next=NULL;
    return newNode;
}

void insertatfirst(linklist** head,int data)
{
    linklist* newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}

void insertatend(linklist** head,int data)
{
    linklist* newNode=createNode(data);

    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        linklist* last=*head;
        while(last->next!=NULL)
            last=last->next;

        last->next=newNode;
    }
}

int main()
{
    
}