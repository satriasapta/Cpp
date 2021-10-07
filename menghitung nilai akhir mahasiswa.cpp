#include<iostream>
#include<conio.h>

using namespace std;
int main ()
{
    struct data
    {
     int no;
        char nama[20];
        int nim;
        int tugas;
        int uts;
        int uas;
        int hasil;
    };struct data mahasiswa[30];

cout<<"-------------------------------------------------\n";
cout<<"Program Menghitung Nilai Akhir Mahasiswa\n";
cout<<"-------------------------------------------------\n";
int x,y;
cout<<"Masukan Data Mahasiswa : ";
cin>>y;
for(x=0;x<y;x++)
{
 cout<<endl;
 cout<<"no : ";
 cin>>mahasiswa[x].no;
    cout<<"Masukan Nama Mahasiswa : ";
    cin>>mahasiswa[x].nama;
    cout<<"Masukan NPM Mahasiswa  : ";
    cin>>mahasiswa[x].nim;
    cout<<"Masukan Nilai DDP    : ";
    cin>>mahasiswa[x].tugas;
    cout<<"Masukan Nilai Matematika      : ";
    cin>>mahasiswa[x].uts;
    cout<<"Masukan Nilai Logika      : ";
    cin>>mahasiswa[x].uas;
    int hasil=(mahasiswa[x].tugas*0.3)+( mahasiswa[x].uts*0.3)+(mahasiswa[x].uas*0.4);
 cout<<"Nilai Akhir         : "<<hasil;
 cout<<endl;
}
system ("cls");
cout<<endl;
cout<<"------------------------------------------------------------\n";
cout<<"No"<<"\t"<<"Nama"<<"\t"<<"NPM"<<"\t"<<"DDP"<<"\t"<<"Matematika"<<"\t"<<"Logika"<<"\t"<<endl;
cout<<"------------------------------------------------------------\n";

for(x=0;x<y;x++)
{
cout<<mahasiswa[x].no<<"\t"<<mahasiswa[x].nama<<"\t"<<mahasiswa[x].nim<<"\t"<<mahasiswa[x].tugas<<"\t"<<mahasiswa[x].uts<<"\t"<<mahasiswa[x].uas<<"\t";

cout<<endl;
}
cout<<endl;
}