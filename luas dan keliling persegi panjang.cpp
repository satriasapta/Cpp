#include <iostream>
using namespace std;
int main (){
    int p,l,luas,keliling;

    cout<<"masukan panjang persegi panjang : ";
    cin>>p;
    cout<<"masukan lebar persegi panjang : ";
    cin>>l;

    luas=p*l;
    keliling=2*(p+l);
    cout<<"luas persegi panjang adalah "<<luas<<endl;
    cout<< "keliling persegi panjang adalah " <<keliling<<endl;
    
    return 0;

}

