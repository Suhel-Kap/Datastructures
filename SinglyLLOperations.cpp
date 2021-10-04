#include<iostream>

using namespace std;

template <class T>

class node{

        public:

        T info;

        node* next;

        node(){

            next=NULL;

        }

        node(T x, node<T>* n=NULL){

            info=x;
            next=n;

        }

};

template <class T>

class Singlylist{

                node<T>* head;
                public:

                Singlylist(){
                head=NULL;
                }

                node<T>* createnewnode(T m);
                int isempty();
                void createnewlist(node<T> *nptr);
                int count();
                void insertatpos(node<T>*nptr);
                T removefromend();
                void reverse();
                Singlylist<T> concatenate(Singlylist<T>);
                node<T>* search();
                void display();

};

template<class T>
node<T>* Singlylist<T>::createnewnode(T m){
	node<T> *nptr;
	nptr = new node<T>;
	nptr->info = m;
	nptr->next = NULL;
	return nptr;
}

template<class T>
void Singlylist<T>::createnewlist(node<T>* newptr)
{
    node<T>* temp;
	temp = head;
	head = newptr;
	newptr->next = temp;
}

template <class T>
int Singlylist<T>::count(){
node<T> *temp;
int c = 0;
for(temp = head; temp != NULL; temp = temp->next)
c++;
return c;
}

template<class T>

void Singlylist<T>::insertatpos(node<T>*nptr){

    int i,j;
    node<T> *temp;
    cout<<"Enter the position at which you want to enter the element: ";
    cin>>i;
    if(i<=count()){
    for(temp=head,j=0; temp!=NULL && j<i-2; temp=temp->next, j++){
    }
    nptr->next=temp->next;
    temp->next=nptr;          
    }
    else
        cout<<"Enter a valid position!\n";

}

template <class T>
void Singlylist<T>::insertatend(T x){
node<T> *temp = new node<T>(x);
node<T> *temp1;
if(isempty())
head = temp;
else{
for(temp1 = head; temp1->next != NULL; temp1 = temp1->next){
}
temp1->next = temp;
}
}

template <class T>
int Singlylist<T>::isempty(){
if(head == NULL)
return 1;
else
return 0;
}

template <class T>
T Singlylist<T>::removefromend(){
T del;
node<T> *tmp;
if(head->next == NULL){
del = head->info;
delete head;
head = NULL;
}
else{
for(tmp = head; tmp->next->next != NULL; tmp = tmp->next){
}
del = tmp->next->info;
delete tmp->next;
tmp->next = NULL;
}
return del;
}

template<class T>

void Singlylist<T>::reverse(){

                node<T> *prev=NULL;
                node<T> *curr=NULL;
                node<T> *nextn=NULL;
                curr = head;
                while(curr!=NULL){
                    nextn = curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=nextn;
                }
                head = prev;
}

template <class T>
void Singlylist<T>::display(){
if(!isempty()){
node<T> *temp;
cout<<"The elements of the list from head to tail are:";
for(temp = head; temp != NULL; temp = temp->next)
cout<<" "<<temp -> info;
cout<<endl;
}
else
cout<<"List is empty! Nothing to display\n";
}

template<class T>
Singlylist<T> Singlylist<T>::concatenate(Singlylist<T> l1){

    Singlylist<T> l2;
    node<T> *temp1;
    node<T> *temp2;
    node<T> *nptr1;
    temp1=this->head;
	temp2=l1.head;
	while(temp2!=NULL){
                nptr1=l2.createnewnode(temp2->info);
                l2.createnewlist(nptr1);
                temp2=temp2->next;
                }
    while(temp1!=NULL){
                nptr1=l2.createnewnode(temp1->info);
                l2.createnewlist(nptr1);
                temp1=temp1->next;
    }
    l2.reverse();
    return l2;
}

template<class T>
node<T>* Singlylist<T>::search(){
	T s;
	node<T> *temp;
	cout<<"Enter the info part of the node to search: ";
	cin>>s;
	for(temp = head; temp != NULL; temp = temp->next){
		if(temp->info == s)
			return temp;
	}
	return NULL;
}

int main(){
Singlylist<int> l1,l2,l3;
char ch='Y';
node<int>* nptr;
int x,i,choice,n,n1;

cout<<"Creating new Linked List\nEnter number of nodes: ";

                cin>>n;

                for(int i=n-1; i>=0; i--){

                                cout<<"Enter information for node["<<i+1<<"]: ";
                                cin>>n;
                                nptr=l1.createnewnode(n);
                                if(nptr==NULL){
                                                cout<<"Compiler out of memory";
                                                exit(0);
                                }

                                else
                                                l1.createnewlist(nptr);

                }

cout<<"\tMENU\n";
cout<<"1. Insert at position\n";
cout<<"2. Delete from the end\n";
cout<<"3. Search an element\n";
cout<<"4. Concatenate two lists\n";



while(ch=='y'||ch=='Y'){
cout<<"Enter choice: ";
cin>>choice;

switch(choice){

case 1:{
cout<<"Enter the element you want to insert: ";
cin>>x;
nptr=l1.createnewnode(n);
l1.insertatpos(x);
l1.display();
break;
}

case 2:{
if(l1.isempty())
cout<<"Linked list is empty! Nothing to delete\n";
else{
x=l1.removefromend();
cout<<"Deleted element: "<<x<<endl;
l1.display();
}
break;
}

case 3:{
node<int> *nptr=l1.search();
if(nptr == NULL)
cout<<"Element not found\n";
else
cout<<"Element found and pointer returned\n";
break;
}

case 4:
    cout<<"Creating second Linked List\nEnter number of nodes: ";
        cin>>n1;
   for(int i=n1-1; i>=0; i--){
   cout<<"Enter information for node["<<i+1<<"]: ";
   cin>>n;
   nptr=l2.createnewnode(n);

        if(nptr==NULL){
            cout<<"Compiler out of memory";
            exit(0);

       }

        else
            l2.createnewlist(nptr);

    }

    cout<<"Concatenating first and second list\n";
    l3=s2.concatenate(l1);
    l3.display();

break;

default:
cout<<"Invalid Choice!\n";
}
cout<<"\n\nDo you want to continue?(Y/N) ";
cin>>ch;
}

return 0;
}



