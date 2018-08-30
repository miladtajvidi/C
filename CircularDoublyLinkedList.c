#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int Data;
	float Time;
    struct Node * Next;
    struct Node * Previous;
};
struct Node * Start;
struct Node * Tail;


void PrintListForward();
void AddToBack();
void PrintListBackward();
void DeleteFromFront();


int main()
{

    Start = 0;
    Tail=0;
	int Choice;
	int MaxChoices;
	char Username[10];

	// set up your Maximum Choice here
	MaxChoices = 5;
	// It creates a menu with 10 items
	Choice = 0;
	printf("%s\n", "Please Enter your name?");
	scanf("%s", Username);
	while (Choice < MaxChoices)
	{

		printf("%s", "Welcome ");
		printf("%s\n\n", Username);
		printf("%s\n", "************** MAIN MENU ****************");
		printf("%s\n", "Please Enter one of the following Choices");
		printf("%s\n\n", "**********Linked List Processing **********");
		printf("%s\n\n", "1: Add a node to end of the list");
		printf("%s\n\n", "2: Delete a node from front of the list");
		printf("%s\n\n", "3: Print the list forward");
		printf("%s\n\n", "4: Print the list backward");
		printf("%s\n\n\n\n", "5: Exit The Program");
		// Print Your choices here
		scanf("%d", &Choice);
		switch (Choice)
		{

		case 1:
			AddToBack();
			break;
		case 2:
			DeleteFromFront();
			break;
		case 3:
			PrintListForward();
			break;
		case 4:
			PrintListBackward();
			break;
		case 5:
			return 0;
		}
	}

    return 0;

}

void PrintListForward()
{
	if (Start == 0)
	{
		printf("Empty List!\n");
		return;
	}



    else
    {

	struct Node * Current;
	Current = Start;

	while (Current->Next != Start)
	{
	    printf("%s\t","Data: ");
		printf("%d\n", Current->Data);
		printf("%s\t","Time: ");
		printf("%f\n",Current->Time);
		printf("->");
		Current = Current->Next;
	}
        printf("%s\t","Data: ");
		printf("%d\n", Current->Data);
		printf("%s\t","Time: ");
		printf("%f\n",Current->Time);

    }

	//printf("NULL\n");
}





void AddToBack()
{
	struct Node * NewNode;
	if (Start == 0)
	{
		// Empty list
		NewNode = malloc(sizeof(struct Node));
		printf("Please Enter This Node's Data ");
		scanf("%d", &NewNode->Data);
		//printf("\n");
		printf("%s","Please Enter This Node's Time ");
		//printf("\n");
		scanf("%f",&NewNode->Time);
		NewNode->Next = NewNode;
		NewNode->Previous = NewNode;
		Start = NewNode;
		Tail=NewNode;

		printf("The First Node added succesfully\n");
		//PrintListForward();
	}



	else{

        NewNode=malloc(sizeof(struct Node));
        printf("Please Enter This Node's Data ");
		scanf("%d", &NewNode->Data);
		printf("\n");
		printf("Please Enter This Node's Time ");
		printf("\n");
		scanf("%f",&NewNode->Time);

        Tail->Next=NewNode;
		NewNode->Next=Start;

		NewNode->Previous=Tail;
		Tail=NewNode;
		Start->Previous=Tail;

	}





}



void PrintListBackward()
{
	if (Start == 0)
	{
		printf("Empty List!\n");
		return;
	}
	else {
	//Traverse to the end
	struct Node * Current;
	//Current = Start;
	Current=Tail;

	while (Current->Previous != Tail)
	{
		printf("%s\t","Data: ");
		printf("%d\n", Current->Data);
		printf("%s\t","Time: ");
		printf("%f\n",Current->Time);
		printf("->");
		Current = Current->Previous;
	}

        printf("%s\t","Data: ");
		printf("%d\n", Current->Data);
		printf("%s\t","Time: ");
		printf("%f\n",Current->Time);
		printf("->");

	//printf("NULL\n");
	}
}




void DeleteFromFront()
{
	if (Start == 0)
	{
		//List is empty, nothing to Delete
		printf("%s", "List is Empty, no node to delete");
		//PrintListForward();
		return;
	}
	// list is not empty
	struct Node * Current;
	struct Node * NextOfCurrent;
	Current = Start;
	NextOfCurrent = Current->Next;
	if (NextOfCurrent == Start)
	{
		Start = 0;
		Tail=0;
	}
	else
	{
	    Tail->Next=NextOfCurrent;
	    Start=NextOfCurrent;
	    Start->Previous=Tail;

	}
	free(Current);
	printf("Node deleted from the front succesfully\n");
	//PrintListForward();
}

