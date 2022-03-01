#include<iostream>
using namespace std;

struct Tas{
	string merek, jenis, tipe;
	int harga;
	
	Tas *next;
	
};

Tas *head, *tail, *cur, *newValue, *del;


void createSingleLinkedList(string merek, string jenis, string tipe, int harga){
	head = new Tas();
	head->merek = merek;
	head->jenis = jenis;
	head->tipe = tipe;
	head->harga = harga;
	head->next = NULL;
	tail = head;
	
}

void addLast(string merek, string jenis, string tipe, int harga){
	newValue = new Tas();
	newValue->merek = merek;
	newValue->jenis = jenis;
	newValue->tipe = tipe;
	newValue->harga = harga;
	newValue->next = NULL;
	tail->next = newValue;
	tail=newValue;
}

void removeFirst(){
	del = head;
	head = head->next;
	delete del;
}

void printSingleLinkedList(){
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
	
	addLast("Converse", "Kanvas", "Tas Ransel", 500000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeFirst();
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
}
