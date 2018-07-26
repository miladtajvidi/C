#include <stdio.h>
#include <stdlib.h>
void addToFront(void);
void addToBack(void);
void printList(void);
void deleteFront(void);
void deleteBack(void);
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
    maxChoices=6;
    choice=0;
    while(choice< maxChoices)
        {
            printf("%s\n", "************** MAIN MENU ****************");
            printf("%s\n", "Please Enter one of the following Choices");
            printf("%s\n\n", "************** MAIN MENU ****************");
            printf("%s\n\n","1:Add to the front of the list");
            printf("%s\n\n","2:Add to the back of the list");
            printf("%s\n\n","3:Print the list");
            printf("%s\n\n","4:Delete from the front of the list");
            printf("%s\n\n","5:Delete from the end of the list");
            printf("%s\n\n","6:Exit the program");
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
                    deleteFront();
                    break;

                case 5:
                    deleteBack();
                    break;

                case 6:
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
        printf("%d\n\n",current->data);
        current=current->next;
    }
    printf("NULL");
}

void deleteFront(void)
{
    if (start==0)
    {
        printf("%s","List is empty; no node to delete");

    }

    struct node *current;
    struct node *currentNext;
    current =start;
    currentNext=current->next;
    if(currentNext==0)
    {
        start=0;
    }

    else
    {
        currentNext->prev=0;
        start=currentNext;
    }

    free(current);
    printf("Node deleted from the front successfully\n\n");
    printList();

}

void deleteBack()
{
    if (start==0)
    {
        printf("%s","List is empty; no node to delete");

    }

    struct node * current;
    struct node * currentNext;
    current=start;
    currentNext=current->next;
    if (currentNext==0)
    {
        start=0;
        free(current);

    }

    while (currentNext->next !=0)
    {
        current=current->next;
        currentNext=current->next;
    }
    current->next=0;
    free(currentNext);
    printf("Node deleted from the back successfully\n\n");
}

