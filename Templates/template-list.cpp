/*
* @Author: sherlock
* @Date:   2017-08-04 19:22:08
* @Last Modified by:   sherlock
* @Last Modified time: 2017-09-14 11:32:16
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
	list<int> l;
	l.push_back(0);
	
	for(int i = 0; i< 10; i++){

		l.push_back(i + 1);
	}

	for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
		cout << *itr << endl;
	}

	cout << endl;

	list<int>::iterator it = find(l.begin(), l.end(), 8);

	l.insert(it, 5);

	// for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
	// 	cout << *itr << endl;
	// }

	// cout << endl;

	it = find(l.begin(), l.end(), 7);
	cout << *it;
	cout << endl;
	l.erase(it);

	for(list<int>::iterator itr = l.begin(); itr!=l.end(); itr++){
		cout << *itr << endl;
	}

	cout << endl;
	l.pop_front()
	// cout << l.pop_front();
	// cout << l.pop_back();

    return 0;
}