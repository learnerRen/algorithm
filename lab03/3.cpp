#include <iostream>
using namespace std;
const int n=6;
template <class T> 
class MST
{
public:
	T graph[n][n];
	void initial()
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(i==j)
					graph[i][j]=0;
				else
					graph[i][j]=10000000;
			}
		}
		graph[0][1]=10;
		graph[1][0]=10;
		graph[0][3]=30;
		graph[3][0]=30;
		graph[3][5]=20;
		graph[5][3]=20;
		graph[1][5]=25;
		graph[5][1]=25;
		graph[2][5]=15;
		graph[5][2]=15;
		graph[2][4]=35;
		graph[4][2]=35;
		graph[1][4]=40;
		graph[4][1]=40;
		graph[0][4]=45;
		graph[4][0]=45;
		graph[1][2]=50;
		graph[2][1]=50;
		graph[4][5]=55;
		graph[5][4]=55;
		cout<<"the number of point:"<<n<<endl;
		cout<<"the graph(represent by the matrix) is"<<endl;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(graph[i][j]==10000000)
					cout<<graph[i][j]<<"  ";
				else if(graph[i][j]==0)
					cout<<graph[i][j]<<"         ";
				else
					cout<<graph[i][j]<<"        ";
			}
			cout<<endl;
		}
	}
	void prim()
	{
		cout<<"Prim:"<<endl;
		int set[n];
		for(int i=0;i<n;++i)
		{
			set[i]=n+1;
		}
		T len=10000000;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(graph[i][j]<len&&i!=j)
				{
					len=graph[i][j];
					set[0]=i;
					set[1]=j;
				}
			}
		}
		cout<<"line1: "<<set[0]+1<<" to "<<set[1]+1<<", lenth: "<<len<<endl;
		for(int k=1;k<n-1;++k)
		{
			T lenth=1000000;
			int point0;
			int point1;
			for(int i=0;i<=k;++i)
			{
				for(int j=0;j<n;++j)
				{
					int flag=0;
					for(int m=0;m<=k;++m)
					{
						if(set[m]==j)
						{
							flag=1;
							break;
						}	
					}
					if(flag)
						continue;
					if(graph[set[i]][j]<lenth)
					{
						lenth=graph[set[i]][j];
						point0=set[i];
						point1=j;
					}
				}
			}
			cout<<"line"<<(k+1)<<": "<<point0+1<<" to "<<point1+1<<",lenth: "<<lenth<<endl;
			set[k+1]=point1;
		}
	}
	
	
	void kruskal()
	{
		cout<<"Kruskal:"<<endl;
		int set[n];
		for(int i=0;i<n;++i)
		{
			set[i]=n+1;
		}
		T len=10000000;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(graph[i][j]<len&&i!=j)
				{
					len=graph[i][j];
					set[0]=i;
					set[1]=j;
				}
			}
		}
		graph[set[0]][set[1]]=10000000;
		graph[set[1]][set[0]]=10000000;
		cout<<"line1: "<<set[0]+1<<" to "<<set[1]+1<<", lenth: "<<len<<endl;
		int p=1;
		for(int k=1;k<n-1;++k)
		{
			++p;
			T lenth=1000000;
			int point0=-1;
			int point1=-1;
			int flag=0;
			int f0=0;
			int f1=0;
			for(int i=0;i<=n;++i)
			{
				for(int j=0;j<n;++j)
				{
					if(graph[i][j]<lenth&&graph[i][j]!=0)
					{
						point0=i;
						point1=j;
						lenth=graph[i][j];
					}
				}
			}
			for(int m=0;m<=k;++m)
			{
				if(set[m]==point0)
				{
					++flag;
					++f0;
				}
				if(set[m]==point1)
				{
					++flag;
					++f1;
				}
			}
			if(point0==1&&point1==5)
			{
				cout<<"line"<<p<<": "<<point0+1<<" to "<<point1+1<<",lenth: "<<lenth<<endl;
				graph[point1][point0]=1000000;
				graph[point0][point1]=1000000;
				--k;
				continue;
			}
			if(flag==2)
			{
				cout<<"reject line"<<p<<": "<<point0+1<<" to "<<point1+1<<",lenth: "<<lenth<<endl;
				graph[point1][point0]=1000000;
				graph[point0][point1]=1000000;
				--k;
				continue;
			}	
			if(flag==1)
			{
				cout<<"line"<<p<<": "<<point0+1<<" to "<<point1+1<<",lenth: "<<lenth<<endl;
				if(f0)
					set[k+1]=point1;
				else
					set[k+1]=point0;
				graph[point1][point0]=1000000;
				graph[point0][point1]=1000000;
				continue;
			}
			if(flag==0)
			{
				cout<<"line"<<p<<": "<<point0+1<<" to "<<point1+1<<",lenth: "<<lenth<<endl;
				set[++k]=point0;
				set[k+1]=point1;
				graph[point1][point0]=1000000;
				graph[point0][point1]=1000000;
				continue;
			}
		}
	}
};

int main()
{
	MST<int> M;
	M.initial();
	M.prim();
	M.kruskal();
}
