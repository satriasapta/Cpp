#include <iostream>
using namespace std;

int main()

{
	system("color A");
	cout << "===========================" << endl;
	cout << "| KALKULATOR SEDERHANA C++|" << endl;
	cout << "===========================" << endl;
	
	float a, b;
	float jumlah, kurang, kali, bagi;
	
	cout << "Masukkan bilangan pertama : ";
	cin >> a;
	cout << "Masukkan bilangan kedua   : ";
	cin >> b;


	
	jumlah = a+b;
	kurang =a-b ;
	kali = a*b ;
	bagi = a/b ;
	
	cout << "Hasil penjumlahan 2 bilangan = " << jumlah << endl;
	cout << "Hasil pengurangan 2 bilangan = " << kurang << endl;
	cout << "Hasil perkalian 2 bilangan   = " << kali << endl;
	cout << "Hasil pembagian 2 bilangan   = " << bagi << endl;
	
	return 0;

}
