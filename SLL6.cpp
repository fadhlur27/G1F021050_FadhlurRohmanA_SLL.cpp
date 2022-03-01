#include<iostream>
using namespace std;

struct Tas{
	string merek, jenis, tipe;
	int harga;
	
	Tas *next;
	
};

Tas *head, *tail, *cur, *newValue,*del, *after;


void createSingleLinkedList(string merek, string jenis, string tipe, int harga){
	head = new Tas();
	head->merek = merek;
	head->jenis = jenis;
	head->tipe = tipe;
	head->harga = harga; 
	head->next = NULL;
	tail = head;
	
}

int countSingleLinkedList(){
	cur = head;
	int NO = 0;
	while(cur != NULL){
		NO++;
		cur = cur->next;
	}
	return NO;
}

void addFirst(string merek, string jenis, string tipe, int harga){
	newValue = new Tas();
	newValue->merek = merek;
	newValue->jenis = jenis;
	newValue->tipe = tipe;
	newValue->harga = harga;
	newValue->next = head;
	head = newValue;
}

void addMiddle(string merek, string jenis, string tipe, int harga, int posisi){
	newValue = new Tas();
	newValue->merek = merek;
	newValue->jenis = jenis;
	newValue->tipe = tipe;
	newValue->harga = harga;
	
	cur = head;
	int NO = 1;
	while(NO < posisi - 1 ){
		cur = cur->next;
		NO++;
	}
	
	newValue->next = cur->next;
	cur->next = newValue;
}

void removeMiddle(int posisi){
	if ( posisi < 1 || posisi > countSingleLinkedList() ){
		cout << "Posisi Diluar Jangkauan " << endl;
	}else if( posisi == 1 || posisi == countSingleLinkedList() ){
		cout << "Posisi Bukan Posisi Tengah " << endl;
	} else {
	int NO = 1;
	cur = head;
	while (NO <= posisi){
		if (NO == posisi -1){
			after = cur;
		}
		if (NO == posisi){
			del = cur;
		}
		cur = cur->next;
		NO++;
	}
	after->next = cur;
	delete del;
	}
}

void printSingleLinkedList(){
	cout << "Nomor Data Ada : " << countSingleLinkedList() << endl;
	cur = head;
	while(cur != NULL){
		cout << "Merek Tas : "<< cur->merek <<endl;
		cout << "Jenis Tas : "<< cur->jenis <<endl;
		cout << "Tipe Tas : "<< cur->tipe <<endl;
		cout << "Harga Tas : "<< cur->harga <<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("Catnip 308", "Tas Kulit", "Tas Selempang", 160000);
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addFirst("Eiger", "Nylon", "Tas Selempang", 275000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("Voyej", "Genuine Leather", "Pouch", 775000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("Visval Raga", "Polyester Fabric", "Ransel", 350000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeMiddle(2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
