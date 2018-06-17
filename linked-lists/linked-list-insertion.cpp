/*
* @Author: sherlock
* @Date:   2017-07-31 04:22:37
* @Last Modified by:   sherlock
* @Last Modified time: 2017-07-31 05:17:38
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

    return 0;
}