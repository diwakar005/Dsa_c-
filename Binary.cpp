#include<iostream>
using namespace std;

int main(){
    // Decimal to binary
    // int num;
    // cout<<"Enter your number: ";
    // cin>>num;
    // int rem,ans=0,mul=1;
    // while (num>0)
    // {
    //     //reminder
    //     rem=num%2;
    //     //quotient
    //     num=num/2;
    //     //ans=ans+rem*mul;
    //     ans+=rem*mul;
    //     //mul
    //     mul*=10;
    // }
    // cout<<ans<<endl;
    

    // Binary to decimal
    int num;
    cout<<"Enter your number: ";
    cin>>num;
    int rem,ans=0,mul=1;
    while (num>0){
        //reminder
        rem=num%10;
        //quotient
        num=num/10;
        //ans=ans+rem*mul;
        ans+=rem*mul;
        //mul
        mul*=2;
    }
    cout<<ans<<endl;
}