#include <iostream>
#include <iomanip>
using namespace std;

const int size = 10;

template <class T>
class Cqueue{
	T cq[size];
	int f;
	int r;
	
	public:
		void insert(T);
		T remove();
		void display();
		int isempty();
		void clear();
		int count();
		int isfull();
		T frontmost();
		T rearmost();
		
		Cqueue()
		{
			f = -1;
			r = -1;
		}
};

template <class T>
int Cqueue<T>::isempty()
{
	if(f == -1)
	    return 1;
	else
	    return 0;
}

template <class T>
int Cqueue<T>::isfull()
{
	if(f == 0 && r == size-1)
	    return 1;
	else if(f == r+1)
	    return 1;
	else
	    return 0;
}

template <class T>
void Cqueue<T>::display()
{
	if(f == -1)
	    cout<<"Empty Queue! Nothing to Display..\n";
	    
	else if(f<=r)
	{
		cout<<"Contents of Queue starting from Front to Rear are - \n";
		for(int i=0; i<f; i++)
			cout<<setw(3)<<"-";
	    for(int i=f; i<=r; i++)
	        cout<<setw(3)<<cq[i];
	    for(int i=r+1; i<size; i++)
			cout<<setw(3)<<"-";
	}
	
	else
	{
		cout<<"Contents of Queue starting from Front to Rear are - \n";
		for(int i=0; i<=r; i++)
			cout<<setw(3)<<cq[i];
	    for(int i=r+1; i<f; i++)
	        cout<<setw(3)<<"-";
	    for(int i=f; i<size; i++)
			cout<<setw(3)<<cq[i];
	}
}

template <class T>
void Cqueue<T>::insert(T p)
{
	if(r == -1)
	{
		f = r = 0;
		cq[r] = p;
	}
	else if(r == size-1)
	{
		r = 0;
		cq[r] = p;
	}
	else
	{
		r++;
		cq[r] = p;
	}
      
}

template <class T>
T Cqueue<T>::remove()
{
	T del;
	if(f == r)
	{
		del = cq[f];
		f = 0; 
	}
	else if(f == size-1)
	{
		del = cq[f];
		f = 0;
	}
	else
	{
		del = cq[f];
		f++;
	}
	return del;
}

template <class T>
void Cqueue<T>::clear()
{
	f = r = -1;
}

template <class T>
T Cqueue<T>::frontmost()
{
	T fm;
	fm = cq[f];
	return fm;
}

template <class T>
T Cqueue<T>::rearmost()
{
	T rm;
	rm = cq[r];
	return rm;
}

template <class T>
int Cqueue<T>::count()
{
	int c = 0;
	if(f == -1)       //empty
	    return c;
	else if(f <= r)      //before wraparound 
	{
		for(int i=f; i<=r; i++)
		    c++;
		return c;
	}
	else              //after wraparound (f>r)
	{
		for(int i=f; i<=size-1; i++)
		    c++;
		for(int i=0; i<=r; i++)
		    c++;
		return c;
	}
}

int main()
{
	Cqueue<int> qc;
	int choice,p,c,fm,rm,d;
	char ch = 'Y';
	
	cout<<"********MAIN MENU********\n";
	cout<<"1. INSERT an element in Circular Queue.\n";
	cout<<"2. REMOVE an element from Circular Queue.\n";
	cout<<"3. COUNT the number of elements in a Circular Queue.\n";
	cout<<"4. CLEAR the Circular Queue.\n";
	cout<<"5. FRONTMOST element of Circular Queue.\n";
	cout<<"6. REARMOST element of Circular Queue.\n";
	cout<<"7. DISPLAY elements of Circular Queue.\n";
	cout<<"8. Check if Circular Queue is EMPTY.\n";
	cout<<"9. Check if Circular Queue is FULL.\n";
	
	while(ch == 'Y'||ch == 'y')
	{
		cout<<"Enter your choice - ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				if(qc.isfull())
				    cout<<"\nOVERFLOW!! Cannot insert element in Circular queue..\n";
			    else
			    {
			    	cout<<"\nEnter the element you want to insert in the Circular queue - ";
			    	cin>>p;
			    	qc.insert(p);
			    	qc.display();
				}
				break;
				
			case 2:
				if(qc.isempty())
				    cout<<"\nUNDERFLOW!! No element to remove..\n";
				else
				{
					d = qc.remove();
					cout<<"\nElement deleted from the Circular queue is - "<<d<<endl;
					qc.display();
				}
				break;
				
			case 3:
				c = qc.count();
				cout<<"\nThe number of elements in the Circular Queue is - "<<c<<endl;
				break;
				
			case 4:
				qc.clear();
				cout<<"\nCircular Queue is Cleared!"<<endl;
				break;
				
			case 5:
				fm = qc.frontmost();
				cout<<"\nThe frontmost element of Circular Queue is - "<<fm<<endl;
				break;
				
			case 6:
				rm = qc.rearmost();
				cout<<"\nThe rearmost element of Circular Queue is - "<<rm<<endl;
				break;
				
			case 7:
				qc.display();
				break;
				
			case 8:
				if(qc.isempty())
				    cout<<"\nCircular Queue is EMPTY!\n";
				else{
					cout<<"\nCircular Queue is not Empty!\n";
				    qc.display();
				}
				break;
				
			case 9:
				if(qc.isfull()){
					cout<<"\nCircular Queue is FULL!\n";
					qc.display();
				}
				else{
					cout<<"\nCircular Queue is not FULL!\n";
				    qc.display();
				}
				break;
				
			default:
				cout<<"\nINVALID CHOICE!";
				break;
		}
		cout<<"\n\nDo you want to continue?? (Y/N) - ";
		cin>>ch;
	}
return 0;
}















