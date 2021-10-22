class NodeLingkaran{
public:
    double radius;
    NodeLingkaran *next;

    NodeLingkaran(){
        this->radius=1;
    }
    NodeLingkaran(double radius){
        this->radius = radius;
    }
    NodeLingkaran(NodeLingkaran &Nodelingkaran){
        this->radius = Nodelingkaran.radius;
    }
    double getLuas(){
        return M_PI * radius * radius;
    }
    double getKeliling(){
        return 2 * M_PI * radius;
    }
};
//ADT untuk Single Linked List Non Circular (SLLNC)
class MyList{
public:
    NodeLingkaran *head;
    MyList(){
        head=NULL;
    }
    bool isEmpty(){
        return head==NULL;
    }
    void tambahDepan(NodeLingkaran *baru){
        baru->next=NULL;     
        if (isEmpty()){
            head=baru;
        } else {
            baru->next=head;
            head=baru;
        }
        cout<<"New Data Added"<<endl;
    }
    void tambahDepan(double radius){
        NodeLingkaran *baru;
        baru = new NodeLingkaran(radius);
        baru->next=NULL;     
        if (isEmpty()){
            head=baru;
        } else {
            baru->next=head;
            head=baru;
        }
        cout<<"New Data Added"<<endl;
    }
    void display(){
        if (isEmpty()){
            cout<<"Data kosong"<<endl;
        } else{
            NodeLingkaran *bantu;
            bantu=head;
            while (bantu !=NULL){
                cout<<bantu->radius<<" Luas: "<<bantu->getLuas()<<endl;
                bantu=bantu->next;
            }
        }
    }
    void tambahBelakang(NodeLingkaran *baru){
    	baru->next = NULL;	
    	NodeLingkaran *bantu;
    	if(isEmpty()){
    		head = baru;
		}
		else{
			bantu = head;
			while(bantu->next != NULL){
				bantu = bantu->next;
			}
			bantu->next = baru;
		}
		cout<<"New Data Added"<<endl;
    }
    void tambahBelakang(double radius){
    	NodeLingkaran *baru;
    	baru = new NodeLingkaran(radius);
    	tambahBelakang(baru);
    }
    NodeLingkaran *hapusBelakang(){
    	NodeLingkaran *bantu, *hapus, *simpan = new NodeLingkaran;
    	if(head->next != NULL){
    		bantu = head;
    		while(bantu->next->next != NULL){
    			bantu = bantu->next;
			}
			hapus = bantu->next;
			simpan->radius = hapus->radius;
			bantu->next = NULL;
			delete hapus;
		}
		else{
			simpan->radius = head->radius;
			head = NULL;
		}
		return simpan;
    }
    NodeLingkaran *hapusDepan(){
		NodeLingkaran *hapus, *simpan = new NodeLingkaran;
		if(head->next != NULL){
			hapus = head;
			simpan->radius = hapus->radius;
			head = head->next;
			delete hapus;
		}
		else{
			simpan->radius = head->radius;
			head = NULL;
		}
		return simpan;
    }
};
