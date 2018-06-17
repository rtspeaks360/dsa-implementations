/*
* @Author: sherlock
* @Date:   2017-08-04 18:21:46
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 18:26:09
*/

#include <iostream>


using namespace std;

template <typename T>
T add(T a, T b){
	return a+b;
}

int main(){
	int a, b;
	float c, d;
	a = 5;
	b = 6;
	c = 7.5;
	d = 8.9;

	cout <<  add<int>(a, b) << endl;
	cout <<  add<float>(c, d) << endl;

    return 0;
}