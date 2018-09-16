#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void prin(int ii)
{
     char word[100]={0};
     int i=0;
     char k='a';
     while(k!=' ')
     {
        k=getchar();
        if(k=='\n')
        {
          break;
        }
        else if(k!=' ')
        {
        	word[i]=k;
		}
        i++;
     }
     if(k=='\n')
	 {
	 	cout<<word<<" ";
	 	 return;
	 }
     else 
     {
     	prin(ii+1);
	 }
     cout<<word;
     if(ii==0)
     {
     	cout<<endl;
	 }
	 else if(ii!=0)
     {
     	cout<<" ";
	 }
     return;
}
int main() 
{
    int times;
    cin>>times;
    getchar();
    for(int i=0;i<times;i++)
    {
       prin(0);
    }
}

