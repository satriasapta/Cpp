/*   NAMA    : FERADHA NAWANINGRUM
     NIM     : 120260021
     KELAS   : TPB 36 (FARMASI)
     
BIDANG STUDI MATEMATIKA 
Program 2 Mencari Operasi Matriks */

#include <iostream>
#include <math.h>
using namespace std;

int main () {
	system ("cls");
	int pilihan; 
	char ulang;
    float A[2][2], B[2][2];
    int x=1;
do{
	cout << "=============================================================" << endl;
	cout << "SELAMAT DATANG DI PROGRAM PERHITUNGAN MENCARI OPERASI MATRIKS" << endl;
	cout << "                Created By : Sapta07                         " << endl;
	cout << "=============================================================" << endl;
	cout << endl;	
	
	cout << "Daftar Menu Pilihan Nilai : " << endl;
	cout << "....................OPERASI MATRIKS 2X2 ....................." << endl;
	cout << "=============================================================" << endl;
	cout << "                     (1) Penjumlahan                         " << endl;
	cout << "                     (2) Pengurangan                         " << endl;
	cout << "=============================================================" << endl;
	cout << "  Masukkan Variable Berdasarkan Angka" << endl;
	cout << "  Pilih Variable Yang Diinginkan: ";
	cin >> pilihan;
	cout << endl;
	
	
	switch(pilihan) {
		case 1:
			if (pilihan == 1) { // percabangan ketika memilih pilihan 1
				cout << "Matriks 1 : " << endl;
				for(int i=0; i<2; i++) { //melakukan perulangan sebanyak dua kali
					for (int j=0; j<2; j++) { //melakukan perulangan sebanyak dua kali
						cin >> A[i][j];
					}
				}
				cout << endl;
				cout << "Matriks 2 : " << endl;
				for(int i=0; i<2; i++) {
					for (int j=0; j<2; j++) {
						cin >> B[i][j];
					}
				}
				cout << endl;			
				for (int i=0; i<2; i++) {
					for (int j=0; j<2; j++) {
						cout << A[i][j] + B[i][j] << " ";
						}
					cout << endl;
				}
			}
		case 2:
			if (pilihan == 2) {
				cout << "Matriks 1 : " << endl;
				for(int i=0; i<2; i++) {
					for (int j=0; j<2; j++) {
						cin >> A[i][j];
					}
				}
				cout << endl;
				cout << "Matriks 2 : " << endl;
				for(int i=0; i<2; i++) {
					for (int j=0; j<2; j++) {
						cin >> B[i][j];
					}
				}
				cout << endl;			
				for (int i=0; i<2; i++) {
					for (int j=0; j<2; j++) {
						cout << A[i][j] - B[i][j] << " ";
						}
					cout << endl;
					
				}
		
					}
				}
			
			
			 cout <<"========================================================"<< endl;
			 cout << "   (Ya=Y atau Tidak=T)";

		do{
			cout << "\n   Apakah Anda Ingin Mencoba Lagi (Y/T) ? ";
			 cin >> ulang;
			 if(ulang=='t'){
			 	x=4;
			 	break;
			 } else {
			 	cout << "silahkan coba lagi";
			 	x=x+1;
			 }
	} while (x<=3);		 
		
	}while (ulang == 'y'||ulang=='Y');
			cout << endl;
}

