#include<iostream>
using namespace std;
class value{
public:
   int data;
   value*next;
   value(int d){
      data=d;
      value*next= NULL;
   }
};
void insertAt(value*&head, int data){
   value*n= new value(data);
   n->next= head;
   head= n;
}
bool searchSequential(value*head,int key){
   if(head==NULL){
      return false;
   }
   if(head->data==key){
      return true;
   }
   else{
      return searchSequential(head->next, key);
   }
}
void printValue(value*head){
   while(head!=NULL){
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}
int main(){
   value*head= NULL;
   insertAt(head,5);
   insertAt(head,4);
   insertAt(head,3);
   insertAt(head,2);
   insertAt(head,1);
   printValue(head);
   if(searchSequential(head,6)){
      cout<<"present"<<endl;
   }
   else{
      cout<<"Not Present"<<endl;
   }
}
