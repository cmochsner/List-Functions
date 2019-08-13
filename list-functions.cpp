//Program by Christina Ochsner
//PS#: 1166214

#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void add(struct Node** head, int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->next = (*head);
	(*head) = node;
}

void deletes(struct Node **head, int key)
{
	struct Node* temp = *head;
	struct Node* prev=0;

	if (temp != NULL && temp->data == key)
	{
		*head = temp->next;  
		free(temp);              
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL) return;

	prev->next = temp->next;

	free(temp); 
}

void print(struct Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout<<endl<< endl;
}

void search(struct Node *node, int key)
{
	bool found = false;
	while (node != NULL)
	{
		if (node->data == key)
		{
			cout << node->data << " was found.\n" << endl;
			found = true;
			break;
		}
		node = node->next;
	}
	if (!found)
	{
		cout << key << " was not found.\n" << endl;
	}
}

int main()
{
	struct Node* head = NULL;
	int input=0;
	int num;
	cout << "Welcome to the Linked List Program! \nType in the corresponding number of one of the operations below!\n" << endl;
	while (input != 5)
	{
		cout << "1: Add to your list" << endl;
		cout << "2: Delete from your list" << endl;
		cout << "3: Search your list" << endl;
		cout << "4: Print your list" << endl;
		cout << "5: Exit the program" << endl;
		cin >> input;
		switch (input)
		{
			case 1:
				cout << "Enter the number you want to add: ";
				cin >> num;
				cout << endl;
				add(&head, num);
				break;
			case 2:
				cout << "Enter the number you want to delete: ";
				cin >> num;
				cout << endl;
				deletes(&head, num);
				break;
			case 3:
				cout << "Enter the number you want to search for: ";
				cin >> num;
				search(head, num);
				break;
			case 4:
				print(head);
				break;
			case 5:
				cout << "Exiting..." << endl;
				return 0;
				break;
			default:
				cout << "Invaild option. Try again." << endl;
				break;
		}
	}

	return 0;
}