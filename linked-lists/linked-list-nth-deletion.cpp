/*
* @Author: sherlock
* @Date:   2017-07-31 05:45:28
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-02 23:38:22
*/

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void Insert(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
	
}

void Print()
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

void Delete(int n)
{
	Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next ;

		delete temp1;
		return;	
	}

	for(int i; i<n-2 ; i++)
	{
		temp1 = temp1->next;
	}

	Node* temp2 = temp1->next;
	temp1 -> next = temp2 ->next;
	delete temp2;
}

int main(){
	head = NULL;
	int n;
	cout << "How many numbers!\n";
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter number " << i+1 << ": ";
		cin >> x;
		Insert(x);
		Print();
	}
	cout << "Enter index of element to delete: ";
	int del_index;
	cin >> del_index;
	Delete(del_index);
	Print();
    return 0;

}