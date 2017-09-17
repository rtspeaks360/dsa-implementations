/*
* @Author: sherlock
* @Date:   2017-07-31 05:12:04
* @Last Modified by:   sherlock
* @Last Modified time: 2017-07-31 05:39:23
*/

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void Insert(int x, int n, Node** head)
{
	Node* temp = new Node();
	temp -> data = x;
	temp -> next = NULL;
	if(n == 1)
	{
		temp-> next = *head;
		*head = temp;
		return;
	}

	Node* temp1 = *head;
	for (int i = 0; i < n-2; ++i)
	{
		temp1 = temp1 -> next;
	}

	temp -> next = temp1 -> next;
	temp1 -> next = temp;
	return;
}

void Print(Node *head)
{
	Node* temp = head;
	cout << "List is : ";
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main(){
	Node* head = NULL;

	Insert(5, 1, &head);
	Insert(4, 2, &head);
	Insert(3, 2, &head);
	Print(head);
	Insert(1, 1, &head);
	Insert(2, 2, &head);
	Print(head);

    return 0;

}