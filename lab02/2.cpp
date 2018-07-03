#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace std;
template <class T>
class Knapsack
{
public:
	int weight;
	int n;
	T *w;//weight
	T *p;//profit
	int *choice;
	void initial()
	{
		cout<<"the number of all things:";
		cin>>n;
		cout<<"the upper bound of weight is ";
		cin>>weight;
		w=new T[n];
		p=new T[n];
		choice=new int[n];
		for (int i=0;i<n;++i)
		{
			srand((int)time(0)+i);
			w[i]=rand()%(2*n)+10;
		}
		for (int i=0;i<n;++i)
		{
			srand((int)time(0)+i*i);
			p[i]=rand()%10+1;
		}
		cout<<"all things:"<<endl;
		cout<<"weight     profit"<<endl; 
		for(int i=0;i<n;++i)
		{
			cout<<w[i]<<"          "<<p[i]<<endl;
		}
	}
	void greedy()
	{
		map< T,T,greater<T> > m;
		for (int i=0;i<n;++i)
		{
			m.insert(make_pair(p[i],w[i]));
		}
		T wei=0;
		T pro=0;
		map<int,int>::iterator m_iter;
		cout<<"we choose:"<<endl;
		cout<<"weight     profit"<<endl; 
		for (m_iter=m.begin();m_iter!=m.end();++m_iter)
		{
			wei+=m_iter->second;
			if(wei>weight)
			{
				wei-=m_iter->second;
				continue;
			}
			pro+=m_iter->first;
			cout<<m_iter->second<<"          "<<m_iter->first<<endl;
		}
		cout<<"all profit:"<<pro<<endl;
		cout<<"all weight:"<<wei<<endl;
	}
	int searchtree(int N,int W)
	{
		for(int i=N-1;i>=0;--i)
		{
			if(w[i]>W)
			{
				choice[i]=0;
				return searchtree(N-1,W);
			}
			else
			{
				if(searchtree(N-1,W)>=p[i]+searchtree(N-1,W-w[i]))
				{
					choice[i]=0;
					return searchtree(N-1,W);
				}
				else
				{
					choice[i]=1;
					return p[i]+searchtree(N-1,W-w[i]);
				}
			}
		 }
		 return 0;
	}
	void print()
	{
		cout<<endl<<"tree algorithm";
		 cout<<"we choose:"<<endl;
		 cout<<"weight    profit"<<endl;
		 T ap=0;
		 T aw=0;
		 for(int i=0;i<n-1;++i)
		 {
		 	if(choice[i]==1)
		 	{
		 		cout<<w[i]<<"        "<<p[i]<<endl;
		 		ap+=p[i];
		 		aw+=w[i];
			}
		 }
		 cout<<"all weight:"<<aw<<endl;
		 cout<<"all profit:"<<ap<<endl;
	}
};
int main()
{
	Knapsack<int> K;
	K.initial();
	K.greedy();
	K.searchtree(K.n,K.weight);
	K.print();
}
