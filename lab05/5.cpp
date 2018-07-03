#include<iostream>
using namespace std;
const int n=9;
template <class T>
class SP
{
public:
	T graph[n][n];
	void initial()
	{
		int a;
		cout<<"please enter the number of node:";
		cin>>a;
		cout<<"please enter the number of edge:";
		cin>>a;
		cout<<"please enter the edge:"<<endl;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				{
					if(i==j)
						graph[i][j]=0;
					else
						graph[i][j]=100000;
				}
		}
		while(a>0)
		{
			int x,y;
			T z;
			cin>>x>>y>>z;
			graph[x-1][y-1]=z;
			--a;
		}
	}
	void forward()
	{
		cout<<endl<<"forward:"<<endl;
		T d[n];
		for(int i=0;i<n;++i)
		{
			d[i]=graph[0][i];
		}
		d[0]=0;
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(d[i]>d[j]+graph[j][i])
				{
					d[i]=d[j]+graph[j][i];
				}
			}
		}
		for(int i=1;i<n-1;++i)
		{
			cout<<"The distance from v1 to v"<<i+1<<" is "<<d[i]<<endl;
		}
		cout<<"The distance from v1 to the end is "<<d[8]<<endl;
		cout<<endl;
	}
	void backward()
	{
		cout<<"backward:"<<endl;
		for(int i=0;i<n;++i)
		{
			for(int j=i;j<n;++j)
			{
				if(graph[i][j]!=100000)
				{
					graph[j][i]=graph[i][j];
					graph[i][j]=100000;
				}
			}
		}
		T d[n];
		for(int i=n-1;i>=0;--i)
		{
			d[i]=graph[n-1][i];
		}
		d[n-1]=0;
		for(int i=n-1;i>=0;--i)
		{
			for(int j=n-1;j>=0;--j)
			{
				if(d[i]>d[j]+graph[j][i])
				{
					d[i]=d[j]+graph[j][i];
				}
			}
		}
		for(int i=n-2;i>0;--i)
		{
			cout<<"The distance from v9 to v"<<i+1<<" is "<<d[i]<<endl;
		}
		cout<<"The distance from v9 to the begin is "<<d[0]<<endl;
	}
 };
int main()
{
	SP<int> S;
	S.initial();
	S.forward();
	S.backward();
}
