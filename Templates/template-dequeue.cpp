/*
* @Author: sherlock
* @Date:   2017-08-04 19:12:21
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 19:19:16
*/

#include <iostream>
#include <deque>

using namespace std;

int main(){
	deque<int> d(5);

	for (int i = 0; i < 5; ++i)
	{
		/* code */
		d[i] = i+1;
	}

	d.push_back(19);
	d.push_front(21);

	for (int i = 0; i != d.size(); ++i)
	{
		/* code */
		cout << d[i] << " ";
	}


	return 0;
}