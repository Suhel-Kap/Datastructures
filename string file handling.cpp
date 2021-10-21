#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string a;
   fstream out;
   out.open("sample12.txt",ios::out|ios::in);

   for(int i=0;i<5;i++)
{
    cin>>a;
  out<<a[i];
}

   for(int i=0;i<5;i++)
  {
   out<<a[i];
    }
   char s;
   out.seekg(3,ios::beg);
   out.get(s);
     cout<<s<<endl;
     out.close();
     return 0;

}
/*#include<iostream>
#include<fstream>
using namespace std;

int main() {
fstream out;
out.open("sample12.txt", ios::out | ios::in);
string s, t;
char c;
cin>>s;
for(int i = 0; i < 5; i++) {
out<<s[i];
}
out.seekg(0, ios::beg);
for(int i = 0; i < 3; i++) {
out.get(c);
cout<<c;
}
cout<<endl;
out.close();
}




#include<iostream>
#include<fstream>
using namespace std;

class smartPhone {
string brand;
float price;
public:
void input() {
cout<<"Enter brand and price:"<<endl;
cin>>brand>>price;
}
void display() {
cout<<"Brand : "<<brand<<endl;
cout<<"Price : "<<price<<endl;
}
};

int main() {
fstream out;
out.open("data.txt", ios::out | ios::in | ios::binary );
smartPhone samsung, obj;
samsung.input();
out.write((char *)&samsung, sizeof(samsung));
out.seekg(0, ios::beg);
out.read((char *)&obj, sizeof(obj));
obj.display();
out.close();
}*/
