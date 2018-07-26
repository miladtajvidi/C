#include <stdio.h>
#include <stdlib.h>
void addToFront(void);
void addToBack(void);
void printList(void);
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node * start;

void main()
{
    start =0;
    int choice, maxChoices;
    maxChoices=4;
    choice=0;
    while(choice< maxChoices)
        {
            printf("%s\n", "************** MAIN MENU ****************");
            printf("%s\n", "Please Enter one of the following Choices");
            printf("%s\n\n", "************** MAIN MENU ****************");
            printf("%s\n\n","1:Add to the front of list");
            printf("%s\n\n","2:Add to the back of the list");
            printf("%s\n\n","3:Print the list");
            printf("%s\n\n","4:Exit the program");
            printf("%s", "Please give me your choice?");
            // Print Your choices here
            scanf("%d", &choice);
            switch(choice)
            {
                case 1:
                    addToFront();
                    break;

                case 2:
                    addToBack();
                    break;

                case 3:
                    printList();
                    break;

                case 4:
                    return 0;

            }
        }
    return 0;
}


void addToFront(void)
{
    struct node * newNode;
    newNode = malloc(sizeof(struct node));
    scanf("%d", &newNode->data);
    if(start==0)
    {
        newNode->prev=0;
        newNode->next=0;
        start=newNode;
    }
    else
    {
        newNode->prev=0;
        newNode->next=start;
        start=newNode;
    }
}


void addToBack(void)
{
    struct node * newNode;
    newNode= malloc(sizeof(struct node));
    scanf("%d",&newNode->data);
    if (start==0)
    {
        newNode->prev=0;
        newNode->next=0;
        start=newNode;
    }

    else
    {
    struct node * current;
    current =start;
    while(current->next!=0)
    {
        current=current->next;
    }

    newNode->prev=current;
    current->next=newNode;
    newNode->next=0;
    }
}

void printList(void)
{
    struct node * current;
    current=start;
    while(current!=0)
    {
        printf("%d",current->data);
        current=current->next;
    }
    printf("NULL");
}





