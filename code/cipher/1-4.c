#include <iostream>
#include <cctype>
#include <cstdio>
using namespace std;
 
int main()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i+=2){
        swap(s[i],s[i+1]);
    }
    cout<<s;
    return 0;
}
