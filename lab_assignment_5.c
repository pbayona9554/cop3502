#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	char letter;
	struct node* next;
} node;

int length(node* head)
{
    node *temp = head; //temp ptr to iterate through list
	int len = 0; //counter to track len of list

	while(temp != NULL){
		len++;
		temp = temp->next;
	}

	return len;
}

char* toCstring(node* head) 
{
    node *temp = head; //ptr to iterate through list

	int len = length(head); //calc len of list

	char* cstring = (char*)malloc(len + 1); //dynamic string

	for(int i = 0;temp != NULL; i++, temp = temp->next){
		cstring[i] = temp -> letter; //create cstring using data from LL 
	}

	cstring[len] = '\0'; //add null terminator
	return cstring;

}

void insertChar(node** pHead, char c)
{
    node *new = (node*)malloc(sizeof(node)); //creating new node
	new->letter = c; //node data
	new->next = NULL; //node will b at end of LL

    if (*pHead == NULL) {
	 	*pHead = new;
	} else {
        node *temp = *pHead;

        while(temp->next != NULL){ //iterate through LL
            temp = temp->next;
	    }

        temp->next = new; //add new node to end of list
    }
	
}

void deleteList(node** pHead) 
{
    node* temp = *pHead; //ptr to list head
	
	while (temp != NULL) //iterate through list
	{
		node* temp2 = temp; //track old node to b deleted 
		temp = temp->next;
		free(temp2);
	}
	
	*pHead = NULL;
}

//main method
int main(void) 
{
	//declare local variables
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");
	fscanf(inFile, "%d\n", &numInputs);
	//use while loop to read until 
	//input greater than 0
	while (numInputs > 0) 
	{
		//read the string length
		fscanf(inFile, "%d\n", &strLen);
		//use for loop to read the string 
		for (i = 0; i < strLen; i++) 
		{
			//read the character
			fscanf(inFile, "%c", &c);
			//insert the charctare into linked list
			//by calling the function
			insertChar(&head, c);
		}
		//convert the characters to string
		//by calling function and store 
		//return variable to str
		str = toCstring(head);
		//print the string
		printf("String is: (%s)\n", str);
		//free the string
		free(str);
		//selete the current string
		deleteList(&head);
		//if head is null
		//list is empty, print the message
		if (head != NULL)
		{
			printf("deleteList is not correct!\n");
			break;
		}
		//decrement the count
		numInputs--;
	}
	//close the file
	fclose(inFile);
	return 0;
}