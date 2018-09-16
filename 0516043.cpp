#include <fstream>
#include <iostream>
using namespace std;
string t;
int a[200001]={0};
int a_[200001]={0};
int aa[3];
int aa_;
int b[200001]={0};
int b_[200001]={0};
int bb[3];
int bb_;
int max_digit;
int ans[400005]={0};
int ans_[400005]={0};
char sign;
int top;
int bottom;
int repeat_time;
int r;
int size_checker=1;//a is bigger
void clear(char x)
{
	if(x=='a')
	{
		for(int i=0;i<aa[1]+1;i++)
		{
			a[i]=0;
			a_[i]=0;
		}
	}
	else if(x=='b')
	{
		for(int i=0;i<bb[1]+1;i++)
		{
			b[i]=0;
			b_[i]=0;
		}
	}
	else if(x=='s')
	{
		for(int i=0;i<aa[1]+bb[1]+3;i++)
		{
			ans[i]=0;
			ans_[i]=0;
		}
	}
	else if(x=='l')
	{
		clear('a');
		clear('b');
		clear('s');
	}
}

void whole_check_size()
{
	if(aa[1]>bb[1])
	{
		size_checker=1;
		return;
	}
	else if(aa[1]<bb[1])
	{
		size_checker=0;
		return;
	}
	else if(aa[1]==bb[1])
	{
		int i=aa[1];
		while(a[i]==b[i])
		{
			i--;
		}
		if(a[i]>b[i])
		{
			size_checker=1;
			return;
		}
		else if(a[i]<b[i])
		{
			size_checker=0;
			return;
		}
	}
}
void print(char sym)
{
	if(sym=='n')
	{
		cout<<"-";
		for(int i=top;i>=bottom;i--)
	    {
	    	cout<<ans[i];
	    }
	}
	else if(sym>48&&sym<58)
	{
		for(int i=(sym-48);i>=0;i--)
	    {
	    	cout<<ans[i];
	    }
	}
    else
    {
	    for(int i=top;i>=bottom;i--)
	    {
	    	cout<<ans[i];
	    }
    }
    
    cout<<endl;
    return;
}

int add()
{
	int temp_sum_saver;
	for(int i=0;i<(max_digit+1);i++)
	{
		temp_sum_saver=a[i]+b[i];
        ans[i]+=temp_sum_saver;
		if(ans[i]>9)
		{
			ans[i+1]++;
			ans[i]-=10;
		}
	}
	return(0);
}
int subtract(char x)
{
	if(x=='a')
	{
		for(int i=0;i<(max_digit+1);i++)
		{
			if(a[i]<b[i])
			{
				a[i+1]--;
				a[i]+=10;
			}
			ans[i]=a[i]-b[i];
		}
	}
	else if(x=='b')
	{
		for(int i=0;i<(max_digit+1);i++)
		{
			if(b[i]<a[i])
			{
				b[i+1]--;
				b[i]+=10;;
			}
			ans[i]=b[i]-a[i];
		}
	}
	else
	{
		cout<<"error"<<endl;
	}
	return(0);
}
int multiply()
{
	int temp_product_saver;
	for(int i=0;i<(aa[1]+1);i++)
	{
		for(int j=0;j<(bb[1]+1);j++)
		{
			temp_product_saver=a[i]*b[j];
			ans[i+j]+=temp_product_saver;
			if(ans[i+j]>9)
			{
				ans[i+j+1]+=ans[i+j]/10;
				ans[i+j]=ans[i+j]%10;
				
			}
		}
	}
}
void shift(int n)
{	
	r++;
	for(int i=bb_;i>=0;i--)
		{
			b_[i+n]=b_[i];
		}		
	for(int i=(n-1);i>=0;i--)
		{
			b_[i]=0;
		}	
	bb_+=n;
}
int check_size()
{
	int kase=1;
	for(int i=0;i<=bb_;i++)
		{
			if(a_[i]>b_[i])
			{
				return(1);
			}
			else if(a_[i]<b_[i])
			{
				kase = 0;
				break;
			}
			else
			{}
		}
	if(kase==1)
	{
		return(1);
	}
	else if(kase==0)
	{
		if(aa_<=bb_)
		{
			return(2);
		}
		else if(aa_>bb_)
		{
			return(0);
		}
		else
		{
			cout<<"error"<<endl;
		}
	}
}
void menus()
{
	for(int i=bb_;i>=bb_-bb[1];i--)
	{
		if(a_[i]<b_[i])
		{
			a_[i-1]=a_[i-1]-1;
			a_[i]=a_[i]+10;
		}
		a_[i]=a_[i]-b_[i];
	}
}
int divide()
{
	aa_=aa[1];
	bb_=bb[1];
	int chek;
	int i=0;
	while(1)
	{
		//cout<<"checksize"<<endl;
		chek=check_size();
		if(chek==1)
		{
			menus();
			ans_[i]++;
			continue;
		}
		else if(chek==0)
		{
		shift(1);
			i++;
			continue;
		}
		else if(chek==2)
		{
			break;
		}
	}
	return(i);
}
int main(int argc, char **argv) 
{
	aa[3]=1;
	bb[3]=1;
	fstream fin;	
    fin.open(*(argv+1),ios::in);
    int temp_space_checker = 54;
    int temp_end_digit_saver;
	
    fin>>repeat_time;
    for(int i=0;i<repeat_time;i++)
    {	
        temp_space_checker = 54;
    		fin>>t;
//    		if(t=='-')
//			{
//				aa[3]=0;
//				fin>>t;
//			}
		for(int i = 0; (temp_space_checker<58&&temp_space_checker>47); i++)
		{
			temp_space_checker=t[i];
			temp_end_digit_saver=i-1;
		}
			aa[1]=temp_end_digit_saver;
		for(int i=0;temp_end_digit_saver>=0;temp_end_digit_saver--)
		{
			a[i]=t[temp_end_digit_saver]-48;
			i++;
		}
			aa[0]=a[aa[1]];//ex:875 aa[1]=2; aa[0]=8;
			fin>>sign;
			temp_space_checker=50;
			fin>>t;
//			if(t=='-')
//			{
//				bb[3]=0;
//				fin>>t;
//			}
		for(int i = 0; (temp_space_checker<58&&temp_space_checker>47); i++)
		{
			temp_space_checker=t[i];
			temp_end_digit_saver=i-1;
		}
			bb[1]=temp_end_digit_saver;
		for(int i=0;temp_end_digit_saver>=0;temp_end_digit_saver--)
		{
			b[i]=t[temp_end_digit_saver]-48;
			i++;
		}
			bb[0]=b[bb[1]];
			fin>>bottom;
			fin>>top;
			if(aa[1]>=bb[1])
			{
				max_digit=aa[1];
			}
			else 
			{
				max_digit=bb[1];
			}
		if(sign=='+')
		{
			add();
			//cout<<"sum = ";
			print('p');
		}
		else if(sign=='-')
		{
			whole_check_size();
			cout<<"size"<<size_checker<<endl;
			if(size_checker==1)
			{
				subtract('a');
				//cout<<"difference = ";
				print('p');
			}
			else
			{
				subtract('b');
				//cout<<"difference = ";
				print('n');
			}
		}
		else if(sign=='*')
		{
			multiply();
			//cout<<"product = ";
			print('p');
		}
		else if(sign=='/')
		{
			for(int i=0;i<aa[1]+1;i++)
			{
				a_[i]=a[aa[1]-i];
			}
			for(int i=0;i<bb[1]+1;i++)
			{
				b_[i]=b[bb[1]-i];
			}
			int flipper=divide();
			for(int i=0;i<flipper+1;i++)
			{
				ans[i]=ans_[flipper-i];
			}
			//cout<<"quotient = ";
			print('p');
			//cout<<"remainder = ";
			// int j=r;
			// int k=0;
			// for(int i=0;i<=bb[1];i++)
			// {
			// 	cout<<a_[r+i];
			// }
			// cout<<endl;
		}
		clear('l');
		r=0;
	}
}
