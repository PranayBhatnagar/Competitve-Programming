//
// Created by bhatn on 11-06-2024.
//
#include<iostream>
#include<cmath>
using namespace std;
void palindrome(int num) {//131
    int ans = num;//ans = 131
    int sum = 0;
    int digit=0;
    while(num>0) {//131,13,1
        num = num/10;//13,1,0.1
        digit++;//1,2,3
    }
    num = ans;//num = 131
    while(num>0 && digit>0) {//131
        int lastdigit = num % 10;//1
        digit--;
        sum = sum + lastdigit * pow(10,digit);
        num = num/10;

    }
    if(ans==sum) {
        cout<<"It is a palindrome.";
    }
    else {
        cout<<"It is not a palindrome.";
    }
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    palindrome(n);
    return 0;
}