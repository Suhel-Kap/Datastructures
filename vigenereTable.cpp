#include<iostream>
using namespace std;
int main(){
    string vigenereTable[26][26];
    for(int i = 0; i<=25; i++){
        int inc = 0;
        for(int j = 0; j<=25; j++){
            if(i+65+inc >90){
                vigenereTable[i][j] = (char)((i+65+inc)-26);
                inc++;
            }
            else{
                vigenereTable[i][j] = (char)(i+65+inc);
                inc++;   
            }
        }
    }
    for(int i = 0; i<=25; i++){
        for(int j = 0; j<=25; j++){
            cout<<vigenereTable[i][j];
        }
        cout<<endl;
    }
    return 0;
}
