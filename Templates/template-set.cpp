/*
* @Author: sherlock
* @Date:   2017-08-04 19:36:28
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 19:59:32
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	multiset<int> s;

	for(int i = 0; i < 10; i++){
		s.insert(10-i);
	}

	set<int>::iterator it;
	it = s.find(6);

	s.erase(it);
	s.insert(1);
	s.insert(6);
	s.insert(7);

	// for (set<int>::iterator i = s.begin(); i != s.end(); ++i)
	// {
		// cout<< *i << " ";		
	// }
	// cout << s.contains(5);
    set<int>::iterator itr;
    itr = s.find(24);
    const bool is_in = s.find(10) != s.end();
    cout << is_in;

    return 0;
}