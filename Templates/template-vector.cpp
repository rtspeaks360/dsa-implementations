/*
* @Author: sherlock
* @Date:   2017-08-04 18:41:08
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 20:00:33
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v(10);

	for (int i = 0; i < 10; ++i)
	{
		/* code */
		v[i] = i*10;
	}

	for (int i = 0; i!=v.size(); ++i)
	{
		/* code */
		cout << v[i] << endl;
	}

	cout << v.size() << endl;
	cout << v.empty() << endl;
	v.push_back(-1);
	cout << v.size() << endl;
	v.resize(15);

	for (int i = 0; i!=v.size(); ++i)
	{
		/* code */
		cout << v[i] << endl;
	}

    return 0;
}