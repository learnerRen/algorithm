#include <iostream>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
template <class T>
class SearchTree
{
public:
	T *tree;
	int n;
	T S;
	void initial()
	{
		cout<<"please enter the number of nodes:";
		cin>>n;
		tree=new T[n+1];
		for(int i=1;i<n+1;++i)
		{
			tree[i]=i;
		}
		cout<<"please enter the number which you want to query:";
		cin>>S;
		cout<<endl;
	}
	void BFS()
	{
		cout<<"Breadth First Search:"<<endl;
		queue<T> q;
		int check=0;
		q.push(tree[1]);
		cout<<"search queue: ";
		while(check!=S)
		{
			check=q.front();
			q.pop();
			cout<<check<<"  ";
			if(tree[2*check+1]>0)
			{
				q.push(tree[2*check]);
				q.push(tree[2*check+1]);
			}
			else if(tree[2*check]>0)
			{
				q.push(tree[2*check]);
			}
			else
			{}
		}
		cout<<endl<<endl;
	}
	void DFS()
	{
		cout<<"Depth First Search:"<<endl;
		stack<T> s;
		int check=0;
		s.push(tree[1]);
		cout<<"search queue:" ;
		while(S!=check)
		{
			check=s.top();
			s.pop();
			cout<<check<<"  ";
			if(tree[2*check+1]>0&&tree[2*check+1]<=n)
			{
				s.push(tree[2*check+1]);
				s.push(tree[2*check]);
			}
			else if(tree[2*check]>0&&tree[2*check+1]<=n)
			{
				s.push(tree[2*check]);
			}
			else
			{}
		}
		cout<<endl<<endl;
	}
	void Best()
	{
		cout<<"Best First search:"<<endl;
		int check;
		cout<<"search queue:" ;
		T w[n+1];
		for(int i =0;i<n+1;++i)
			w[i]=1000000;
		w[1]=0+S-1;
		check=tree[1];
		while(S!=check)
		{
			int c=check;
			for(int i=1;i<n+1;++i)
			{
				if(w[c]>w[i])
				{
					c=i;
				}
			}
			check=c;
			cout<<check<<"  ";
			int layer;
			layer=w[check]-8+check;
			if(tree[2*check+1]>0&&tree[2*check+1]<=n)
			{
				w[2*check]=layer+1+8-2*check;
				w[2*check+1]=layer+1+8-2*check-1;
			}
			else if(tree[2*check]>0&&tree[2*check+1]<=n)
			{
				w[2*check]=layer+1+8-2*check;
			}
			else
			{}
			w[c]=1000000;
		}
		cout<<endl<<endl;
	}
 }; 
int main()
{
	SearchTree<int> ST;
	ST.initial();
	ST.BFS();
	ST.DFS();
	ST.Best();
}
