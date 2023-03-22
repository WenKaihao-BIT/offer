//
// Created by Q on 2023/2/6.
//
#include <iostream>

using namespace std;
void ReplaceBlank(char string[],int length){
    if(string == NULL||length<=0)
        return;
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while (string[i]!='\0'){
        ++originalLength;
        if(string[i]==' ')
            ++ numberOfBlank;
        ++i;
    }
    int newLength = originalLength+numberOfBlank*2;
    if(newLength>length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while (indexOfOriginal>=0&&indexOfNew>indexOfOriginal){
        if(string[indexOfOriginal] == ' '){
            string[indexOfNew--] = '0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        } else{
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}
//
//int main(){
//    char name[] = "We are happy.";
//    string s ="123";
////    cout<<s.length();
//    int i=2;
//    cout<<s[i--]<<' '<<i;
////    ReplaceBlank(name,20);
////    cout<<name;
//
//
//    return 0;
//}