#include<iostream>
using namespace std;
double taylor(int x,int n)
{
   static double num=1;
   static double den=1;
   static double term;
    if(n==0)
    {
        return 1;
    }
    else{
        term=taylor(x,n-1);
        num=num*x;
        den=den*n;
        return (term + num/den);
    }
        return 0;
}
double taylorLoop(int x,int n)//taylor series using loop
{
    double tylor =1;
    double num=1;
    double den=1;

    for(int i=1;i<=n;i++){
        num*=x;
        den*=i;
        tylor +=(num/den);
    }
    return tylor;
}
double homer(double x,double n)//taylor series using homer formula
{
    static double temp=1;
    if(n==0){
        return temp;
    }
    else{
        temp=1+((x/n)*temp);
        return homer(x,n-1);
    }
}
int main()
{
    cout<<taylor(1,10)<<endl;
    cout<<taylorLoop(1,10)<<endl;
    cout<<homer(1,10)<<endl;
}
