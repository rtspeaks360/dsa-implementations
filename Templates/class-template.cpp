/*
* @Author: sherlock
* @Date:   2017-08-04 18:30:31
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 18:38:59
*/

#include <iostream>

using namespace std;

template <class T>

class test
{
public:
	T a[2];
	T add();
	test(); 
	
};

template <class T>
test<T>::test(){
	cin >> a[0] >> a[1];
}

template <class T>
T test<T>::add(){
	return a[0] + a[1];
}

int main(){
	test<int> test_object_int;
	cout << test_object_int.add();
	
	test<float> test_object_float;
	cout << test_object_float.add();

    return 0;
}