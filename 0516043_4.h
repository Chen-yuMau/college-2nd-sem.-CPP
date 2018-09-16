#include <iostream>
using namespace std;
class Polynomial
{
	private:
	
	public:
		long long int num[20000];
		int max;
		Polynomial()
		{
			for(int i=0;i<max;i++)
	        {
	        	num[i]=0;
			}
		}
		int get_value(int a)
		{
			int ans=0;
			int temp;
			int k;
			for(int i=0;i<this->max+1;i++)
			{
				k=1;
				for(int j=0;j<i;j++)
				{
					k=k*a;	
				}
				temp=num[i]*k;
				ans=ans+temp;
			}
			return ans;
		}
		Polynomial operator+(const Polynomial& a) 
		{
	        Polynomial p;
	        for(int i=0;i<max+1;i++)
	        {
	        	p.num[i]=this->num[i]+a.num[i];
			}
			if(this->max>a.max)
			{
				p.max=this->max;
			}
			else
			{
				p.max=a.max;
			}
	        return p;
      	}
      	Polynomial operator-(const Polynomial& a) 
		{
	        Polynomial p;
	        for(int i=0;i<max+1;i++)
	        {
	        	p.num[i]=this->num[i]-a.num[i];
			}
			for(int i=this->max+2;p.num[i]==0;i--)
			{
				p.max=i;
			}
	        return p;
      	}
          Polynomial operator~() 
          { 	
          	for(int i=0;i<max;i++)
           	{
            		num[i]=num[i+1]*(i+1);
              	}
               	num[20000]=0;
               	max--;
               	return *this; 
 }
      	friend istream & operator>>(ostream & s, Polynomial & o);
};
istream & operator>>(istream & s,Polynomial & p)
		{
			int n;
			char num;
			int rnum;
			int deg;
			p.max=0;
            while(num!='!')
			{
                s>>num;
                n=1;
                if(num=='-')
                {
                   cin>>num;
                   n=-1;
                }
                else if (num=='!')
                {
                break;
                }
				rnum=(num-'0')*n;
				s>>deg;
				if(p.max<deg)
				{
					p.max=deg;
				}
				p.num[deg]=rnum;
			}
			return s;
		}

