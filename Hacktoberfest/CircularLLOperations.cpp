#include<iostream> 
using namespace std; 
const int SIZE = 5; 
template<class T> class Circular_Queue
{
    public:
    T cq[SIZE];
    int f,r; 
    Circular_Queue(){
    f=r=-1;
    }
    void insert(T); 
    T remove(); 
    int isempty(); 
    int isfull(); 
    void display(); 
    void clear();
    T frontmost(); 
    T raremost(); 
    int count();
} 
template<class T>
void Circular_Queue<T>::insert(T i)
{
    if(r==-1)
    {
        f=r=0; 
        cq[r]=i;
    }
    else if(r==SIZE-1)
    {
        r=0;
        cq[r]=i;
    } 
    else
    {
        r++;
        cq[r]=i;
    }
}
template<class T>
T Circular_Queue<T>::remove()
{ 
    T rem;
    if(f==r)
    {
        rem=cq[f]; f=r=-1;
    }
    else if(f==SIZE-1)
    {
        rem=cq[f]; f=0;
    }
    else
    {
        rem=cq[f]; f++;
    }
    return rem;
}
template<class T>
int Circular_Queue<T>::isempty()
{
    if(f==-1 && r==-1) 
    return 1;
    else 
    return 0;
}
template<class T>
int Circular_Queue<T>::isfull()
{
    if(f==0 && r==SIZE-1 || r==f-1) 
    return 1;
    else 
    return 0;
}
template<class T>
void Circular_Queue<T>::display()
{
    int i=0; if(f==-1)
    cout<<"Queue is empty"<<endl;
    if(r>=f)
    {
        cout<<"Contents of queue starting from front to rear end are :"; 
        for(i=f;i<=r;i++)
        cout<<cq[i]<<"\t";
    }
    else
    {
        for( i=0;i<=r;i++) 
        cout<<cq[i]<<"\t"; 
        for(int i=f;i<SIZE;i++) 
        cout<<cq[i]<<"\t";
    }
}
template<class T> void Circular_Queue<T>::clear()
{
    f=r=-1;
}
template<class T> T Circular_Queue<T>::frontmost()
{
    T res;
    res=cq[f]; 
    return res;
}
template<class T> T Circular_Queue<T>::raremost()
{
    T res; 
    res=cq[r]; 
    return res;
}
template<class T> int Circular_Queue<T>::count()
{
    int c=0; 
    if(f==-1) 
    return 0; 
    else if(f<=r)
    {
        for(int j=f;j<=r;j++) 
        c++;
        return c;
    }
    else if(f>r)
    {
        for(int j=0;j<=r;j++) c++;
        return c;
    }
}
int main()
{
    Circular_Queue<int> C; 
    char ch;
    int choice,i,rem,empty,full,count,f,r; 
    int val;
    do
    {
        cout<<"\n MAIN MENU "<<endl; 
        cout<<"\n 1. INSERT "; 
        cout<<"\n 2. REMOVE "; 
        cout<<"\n 3. CLEAR ";
        cout<<"\n 4. CHECK isEMPTY "; 
        cout<<"\n 5. CHECK isFULL "; 
        cout<<"\n 6. FRONTMOST "; 
        cout<<"\n 7. RAERMOST "; 
        cout<<"\n 8. DISPLAY "; 
        cout<<"\n 9. COUNT ELEMENTS ";
        cout<<"\n Enter your choice (1-9) : "; 
        cin>>choice;
        switch(choice)
        {
            case 1: 
            if(C.isfull()==1)
            cout<<"\n QUEUE IS FULL !!! ";
            else
            {
                cout<<"Input for Insert Operation : "<<endl; 
                cin>>val;
                C.insert(val);
            }
            case 2:
            C.display(); 
            break;
            if(C.isempty()==1)
            cout<<"\n UNDERFLOW !!! ";
            else
            break;
            C.remove();
            C.display();
            case 3: 
            C.clear();
            break; 
            case 4: 
            if (C.isempty()==1)
            cout<<"\n Queue is Empty"; 
            else
            cout<<"\n Queue is not Empty"; 
            break;
            case 5: 
            if (C.isfull())
            cout<<"\n Queue is Full"; 
            else
            cout <<"\n Queue is not Full"; 
            break;
            case 6: 
            cout<<"\n FRONTMOST ELEMENT : ";
            cout<<C.frontmost(); 
            break;
            case 7: 
            cout<<"\n RAREMOST ELEMENT : ";
            cout<<C.raremost(); 
            break;
            case 8: 
            C.display();
            break;
            case 9: 
            cout<<C.count();
            break;
            default: 
            cout<<"\n INVALID CHOICE !!!"; 
            break;
}
cout<<"\n To Continue press (y/Y) : "; 
cin>>ch;
}
while(ch=='y' || ch=='Y'); 
return 0;
}
