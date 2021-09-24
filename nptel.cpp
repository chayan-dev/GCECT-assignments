#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int data[]={10,20,30,40,50};
    for(int i=0;i<1;i++)
    {
        int j=data[i];
        replace(data,data+5,j,*(data+4));
        for(auto i:data)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        replace(&data[i+1],&data[5],*(data+4),j);
    }

    for(auto i:data)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}