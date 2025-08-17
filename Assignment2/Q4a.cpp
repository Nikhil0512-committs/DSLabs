#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1,str2,str;
    cout << "Enter your first name: "<<endl;
    cin >> str1;
    cout << "Enter your last name: "<<endl;
    cin >> str2;

    str = str1 + str2;

    cout << "Your full name is " << str << endl;




    return 0;
}