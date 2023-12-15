#include <iostream>
using namespace std;

int penjumlahan (int soal, int data){
    soal += data;
    return soal;
}

int main(){
   

    int array[5];
    int (*ptrJumlah) (int,int);
    int hasil=0;
    ptrJumlah = penjumlahan;
    for (int i=0;i<5;i++){
        cout << "masukkan data ke "<<i<<" = ";
        cin >> array[i];
    }
    for (int k=0;k<5;k++){
        hasil= ptrJumlah (hasil,array[k]);
        cout << "hasil penjumlahan dari data array ke " << k <<" adalah " << hasil << endl;
    }
}
