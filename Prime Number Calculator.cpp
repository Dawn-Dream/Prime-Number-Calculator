#include<cmath>
#include<iostream>
#include<fstream>
#include<windows.h> 
#include<cstring>
using namespace std;
const int maxn=1000000100;
ofstream fout("Prime Number Calculator.out");
int n=0,i=0,j,begin,biggest,a1=0,a2=0;
bool flag=true;
bool prime[maxn];
int p[50847534+10];
void input()
{
	do
	{
		cout<<"Please enter the initial value of the prime number (initial value> = 0)：";
		cin>>begin;  
	}
	while(begin<0);
	do
	{
		cout<<"Please enter the final value of the prime number (initial value <final value <= 1000000000):";
		cin>>biggest; 
	}
	while(begin>=biggest||biggest>1000000000);
}
void s1()
{
	n=0;
	cout<<"This time using method A, the calculation speed is the same.\n";
	memset(prime,false,sizeof(prime));
	system("pause");
	system("cls"); 
	cout<<"Calculating...\n";
	for(i=begin;i<=biggest;i++)
	{
		if(i<=1) continue;
		flag=true;
		for(j=2;j<=floor(sqrt(i));j++)
		  if(i%j==0)
		  {
			flag=false;
			break;
		  }
		prime[i]=flag;
		a1=floor(float(i-begin)/float(biggest-begin)*100);
		if(a1!=a2)
		{
			system("cls");
			cout<<"已经计算"<<a1<<"%";
		}
		a2=a1; 
	}
}
void s2()
{
	n=0;
	cout<<"本次使用方法B，越算越快。\n";
	memset(prime,true,sizeof(prime));
	system("pause");
	system("cls");
	cout<<"正在计算中...\n"; 
	prime[0]=false; prime[1]=false; 
	for(i=2;i<=floor(sqrt(biggest));i++)
	{
		for(j=2;j<=biggest/i;j++) if((unsigned long long)i*(unsigned long long)j<maxn)prime[i*j]=false;
		a1=floor(float(i-2)/sqrt(biggest)*100);
		if(a1!=a2)
		{
			system("cls");
			cout<<"已经计算"<<a1<<"%";
		}
		a2=a1; 
	}
} 
void print()
{
	n=0;
	for(i=begin;i<=biggest;i++)
	{
		if(prime[i])
		{
			fout<<i<<"   ";
			n++;
			if(n%7==0)fout<<endl<<endl; 
		}
		a1=floor(float(i-begin)/float(biggest-begin)*100);
		if(a1!=a2)
		{
			system("cls");
			cout<<"已经打印"<<a1<<"%";
		}
		a2=a1; 
	}		
	if(n%7!=0) fout<<"\n";
	fout<<"\nTotal prime"<<n<<"Pc。";
	cout<<"\nPlease open the text file Prime Number Calculator.out and check the calculation result.\n";
}
int main()
{
	input();
	fout<<begin<<"到"<<biggest<<"的质数有：\n\n"; 
	system("cls");
	if((begin>1000&&biggest-begin+1<=10000)||biggest-begin+1<=100) 	s1();
  	  else s2();
  	cout<<"\n";
  	system("pause");
  	system("cls");
  	cout<<"计算完毕，准备打印结果。\n";
  	system("pause");
  	system("cls"); 
	print();
	system("pause");
	return 0;
}
