/*
* @Author: sherlock
* @Date:   2017-08-04 22:06:38
* @Last Modified by:   sherlock
* @Last Modified time: 2017-08-04 22:28:50
*/

#include <iostream>
#include <set>

using namespace std;

class array_soultions{
	public:
		int a[10];
		bool duplicate_within_k();
		array_soultions();
};

array_soultions::array_soultions(){
	cout << "How many numbers: ";
	int n;
	cin >> n;
	cout << "input array : \n";

	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> a[i];
	}
}

bool array_soultions:: duplicate_within_k(){
	int k;
	cout << "Enter the value for k:";
	cin >> k;

	set<int> visited;
	set<int>::iterator it;

	int n = sizeof(a)/sizeof(int);

	for (int i = 0; i < n; ++i){
		/* code */
		if (visited.find(a[i]) != visited.end()){
			cout << "Contains duplicates within " << k; 
			return bool(1);
		}
		else{
			visited.insert(a[i]);
		}
		if (i>k){
			it = visited.find(a[i-k]);
			visited.erase(it);
		}

	}
	cout << "No duplicates found within k";
	return bool(0);
}



int main(){
	array_soultions obj;
	obj.duplicate_within_k();

    return 0;
}