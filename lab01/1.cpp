#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;
template <class T>
class exp
{
public:
	int N;
	T *data;
	T *newdata;
	void initial()
	{
		cout<<"array size:";
		cin>>N;
		data=new T[N];
		cout<<"the random data is:...(the size is too large)";
		for (int i=0;i<N;++i)
		{
			srand((int)time(0)+i);
			data[i]=rand()%(N*10);
		}
		cout<<endl;
	}
	void quicksort(double newdata[],int left,int right)
	{
		double t0=GetTickCount();
		if(left>=right)
		return;
		int first=left;
		int last=right;
		T pivot=newdata[first];
		while(first < last)
    	{
	        while(first < last && newdata[last] >= pivot)
	        {
	            --last;
	        }
	        newdata[first] = newdata[last];
	        while(first < last && newdata[first] <= pivot)
	        {
	            ++first;
	        }
	        newdata[last] = newdata[first];   
		}
    	newdata[first] = pivot;
    	quicksort(newdata,left, first-1);
    	quicksort(newdata,first+1, right);
	}
	void selectionsort()
	{
		T newdata[N];
		for (int i=0;i<N;++i)
		{
			newdata[i]=data[i];
		}
		double t0=GetTickCount();
		for(int m=0;m<N-1;++m)
		{
			double a=newdata[m];
			int id;
			for(int n=m+1;n<N;++n)
			{
			if(a>newdata[n])
				{
					a=newdata[n];
					id=n;
				}
			}
			int temp=newdata[m];
			newdata[m]=newdata[id];
			newdata[id]=temp;
		}
		double t1=GetTickCount();
		cout<<"The time of selection sort used is:"<<(t1-t0)/1000<<"s"<<endl;
	}
	void bubblesort()
	{
		T newdata[N];
		for (int i=0;i<N;++i)
		{
			newdata[i]=data[i];
		}
		int t0=GetTickCount();
		for(int m=0;m<N;++m)
		{
			for(int n=0;n<N-1;++n)
			{
				if(newdata[n]>newdata[n+1])
				{
					int temp=newdata[n];
					newdata[n]=newdata[n+1];
					newdata[n+1]=n;
				}
			}
		}
		/*for(int i=0;i<N;++i)
		{
			cout<<newdata[i]<<"   ";
		}*/
		double t1=GetTickCount();
		cout<<"After bubble sort:..."<<endl;
		cout<<"The time of bubble sort used is:"<<(t1-t0)/1000<<"s"<<endl;
	}
};
int main()
{	
	exp<double> E;
	E.initial();
	E.bubblesort();
	E.selectionsort();
	double newdata[E.N];
	for(int i=0;i<E.N;++i)
		newdata[i]=E.data[i];
	double t0=GetTickCount();
	E.quicksort(newdata,0,E.N-1);
	double t1=GetTickCount();
	cout<<"After bubble sort:..."<<endl;
	cout<<"The time of quick sort used is:"<<(t1-t0)/1000<<"s"<<endl;
}
