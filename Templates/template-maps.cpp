/*
* @Author: sherlock
* @Date:   2017-08-04 20:14:33
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 22:40:21
*/

#include <iostream>
#include <map>
using namespace std;

int main(){
	pair<char, int> x;
	map<char, int> m;
    
	for (char c = 'a'; c<='z' ; c++){
		x.first = c;
		x.second = (int)c;

		m.insert(x);
	}

	map<char, int>::iterator it = m.begin();

	// for(it = m.begin(); it != m.end(); it++){
	// 	cout << it->first << "->" << it->second << endl;
	// }


	it = m.find('j');
	cout << it->first  << "->" << it->second;
	it -> second = it->second + 1;
	cout << it->first  << "->" << it->second;
    return 0;
}