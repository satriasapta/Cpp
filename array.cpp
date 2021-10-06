#include <iostream>
using namespace std;

int main (){
	int n , bilangan  ;
	bool ditemukan = 0 ;
	cin >> n;
	int array[n];
	
	for(int i=0; i < n; i++){
		cin >> array[i];		
	}
	cin >> bilangan ;

	for(int i=0; i < n; i++){
		if(array[i] == bilangan){
			ditemukan = 1;
		}
	}
		if(ditemukan)
			cout << "Data ditemukan pada indek ke = ";
			
		for(int i=0; i<n; i++){
		if(array[i] == bilangan){
			cout << i << " ";		
		}
	}
		if(!ditemukan)
			cout << "Data tidak ditemukan pada array";
		}
