#include <bits/stdc++.h>
using namespace std;

// Pakai linked list
struct dataBarang{
    string namaBarang;
    int jumlahBarang, hargaBarang;
    float totalBarang;

    //pointer
    dataBarang *prev;
    dataBarang *next;
};

dataBarang *head, *tail, *cur, *newNode, *del;
int maksimalBarang = 5;

void createBarang(string namaBarang, int jumlahBarang, int hargaBarang, float totalBarang){
            head = new dataBarang();
            head->namaBarang = namaBarang;
            head->jumlahBarang = jumlahBarang;
            head->hargaBarang = hargaBarang;
            head->totalBarang = jumlahBarang * hargaBarang;
            head->prev = NULL;
            head->next = NULL;
            tail = head;
}

int countBarang()
{
    if(head == NULL){
        return 0;
    } else{
        int banyak = 0;
        cur = head;
        while(cur != NULL){
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}


bool isFullBarang()
{
    if (countBarang() == maksimalBarang){
        return true;
    }else {
        return false;
    }
}

bool isEmptyBarang()
{
    if (countBarang() == 0){
        return true;
    }else {
        return false;
    }
}

void pushBarang(string namaBarang, int jumlahBarang, int hargaBarang, float totalBarang){

    if(isFullBarang() ){
        cout << "stack full!!"<< endl;
    }else{
        if (isEmptyBarang() ){
        createBarang(namaBarang, jumlahBarang, hargaBarang, totalBarang);
        } else{
            newNode = new dataBarang();
            newNode->namaBarang = namaBarang;
            newNode->jumlahBarang = jumlahBarang;
            newNode->hargaBarang = hargaBarang;
            newNode->totalBarang = jumlahBarang * hargaBarang;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    } 

}

void popBarang()
{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void displayBarang()
{
    if(isEmptyBarang()){
        cout << "Data Barang kosong" << endl;
    } else{
        cout << "\n\nData Barang : " << endl;
        cur = tail;
        while(cur != NULL){
            cout << "Data Barang : " << cur->namaBarang << "jumlah barang : "<< cur->jumlahBarang<< "- Rp." << cur->hargaBarang <<"total barang : "<<cur->totalBarang <<endl;
            cur = cur->prev;
        }
    }
}

void peekBarang(int posisi){

    if(isEmptyBarang()){
        cout << "Data Barang kosong" << endl;
    } else{
      int nomor =1;
      cur = tail;
      while(nomor < posisi){
          cur = cur->prev;
          nomor++;
      }  
     cout << "Data Barang posisi ke-" <<posisi<< cur->namaBarang << "jumlah barang : "<< cur->jumlahBarang<< "- Rp." << cur->hargaBarang <<"total barang : "<<cur->totalBarang <<endl;
    }

}

void changeBarang(string namaBarang, int jumlahBarang, int hargaBarang, float totalBarang, int posisi){

    if(isEmptyBarang()){
        cout << "Data Barang kosong" << endl;
    } else{
      int nomor =1;
      cur = tail;
      while(nomor < posisi){
          cur = cur->prev;
          nomor++;
      }  
     cur-> namaBarang = namaBarang;
     cur-> jumlahBarang = jumlahBarang;
     cur-> namaBarang = namaBarang;
     cur-> totalBarang = jumlahBarang * hargaBarang;
    }

}

void destroyBarang()
{

    cur = head;
    while(cur != NULL){
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }

}

int main(){
    system("color b");
    char pilih;
    do{
    int n;
    string namaBarang;
    int jumlahBarang, hargaBarang, posisi;
    float totalBarang;
cout<<endl;
cout<<"====================================="<<endl;
cout<<"|Selamat datang di UNILA.com        |"<<endl;     
cout<<"|1.Push barang                      |"<<endl;
cout<<"|2.Pop barang                       |"<<endl;
cout<<"|3.Menampilkan semua barang         |"<<endl;
cout<<"|4.Menghapus semua barang           |"<<endl;
cout<<"|5.Mengganti barang                 |"<<endl;
cout<<"|6.Peek barang                      |"<<endl;
cout<<"|7.Exit                             |"<<endl;
cout<<"====================================="<<endl;
cout<<"Enter your choice:";
    cin>>n;
     
    switch(n){
        case 1:  

            cout<<"Masukan nama barang   : ";
            cin >> namaBarang;
            cout<<"Masukan jumlah  barang : ";
            cin>> jumlahBarang;
            cout<<"Masukan harga barang   : ";
            cin >> hargaBarang;
            cout<<"total  barang : ";
            totalBarang = jumlahBarang * hargaBarang;
            //push data into the stack
            pushBarang(namaBarang, jumlahBarang, hargaBarang, totalBarang);
            break;

        case 2 : 
            //pop barang from stack
            popBarang();
            break;
         
        case 3 : 
            //display barang
           displayBarang();
            break;
             
        case 4:
        //menghapus semua barang 
        destroyBarang();   
        break;

        case 5 :
            cout<<"Masukan nama barang   : ";
            cin >> namaBarang;
            cout<<"Masukan jumlah  barang : ";
            cin>> jumlahBarang;
            cout<<"Masukan harga barang   : ";
            cin >> hargaBarang;
            cout<<"total  barang : ";
            totalBarang = jumlahBarang * hargaBarang;
            cout<<"Tentukan posisi       :";
            cin>>posisi;
        changeBarang( namaBarang, jumlahBarang, hargaBarang, totalBarang, posisi);
        break;
        
        case 6:
        //mengintip suatu barang
        peekBarang(posisi);
        break;

        case 7:
        return 0;
    }
    cout<<""<<endl;
    cout<<"Apakah anda ingin mencoba lagi? (Y/y) : ";
    cin>>pilih;
 
    }while(pilih=='Y'||pilih=='y');
     
    return 0;
}
