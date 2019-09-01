#include <iostream>
#include <string>
#include <deque>
#define QSIZE 1
#define mf(i,a,b) for(int i=(int)a;i<=(int)b;i=(i+1)%msize)
#define f(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ll long long int 
#define inc(x) (x+1)%msize
#define dec(x) (x-1<0) ?  x -1 + msize : x-1	
using namespace std;

template <typename T>
class Deque
{
	//csize = current size && msize = maxsize
	public:
		ll Front,Rear,csize,msize = QSIZE;
		T *q;

	Deque()
	{
		Front = Rear = -1;
		csize = 0;
		
		q = (T *) malloc(sizeof(T)*msize);
	}

	Deque(ll n,T value)
	{
		if(n>msize)
			msize = n;
		Front = 0;
		Rear = n-1;
		csize = n;		
		q = (T *)malloc(sizeof(T)*msize);
		f(i,0,n-1)
			q[i] = value;
	}
	
	public:
	void push_back(T value)
	{
		
		//empty dequeu
		if(Front == -1 && Rear == -1)
		{
			Front = Rear = msize/2;
			q[msize/2] = value;
			
		}
		else if(inc(Rear)!= Front)
		{
			Rear = inc(Rear);
			q[Rear] = value;
		}
		else
		{
			T * q1 = (T *)malloc(sizeof(T)*3*msize);

			ll j =Front;
			f(i,0,csize-1)
			{			
				q1[i+msize] = q[j];
				j = inc(j);
			}
			q = q1;
			Front = msize;
			Rear = 2*msize;
			q[Rear] = value;
			msize = 3*msize;

		}
		csize++;

	}


	void push_front(T value)
	{
		
		//empty dequeu
		if(Front == -1 && Rear == -1)
		{
			Front = Rear = msize/2;
			q[msize/2] = value;
			
		}
		else if((dec(Front))!= Rear)
		{
			Front = dec(Front);
			q[Front] = value;
		}
		else
		{
			T * q1 = (T *)malloc(sizeof(T)*3*msize);

			ll j =Front;
			f(i,0,csize-1)
			{			
				q1[i+msize] = q[j];
				j = inc(j);
			}
			q = q1;
			Front = msize-1;
			Rear = 2*msize-1;
			q[Front] = value;
			msize = 3*msize;

		}
		csize++;

	}

	void pop_front()
	{
		if(Front == -1 && Rear == -1)
		{
			cout<<"Error : Empty Queue Deletion !!"<<endl;		
			return;
		}

		if(Front == Rear)
		{
			//q[Front] = 0;
			//Front = Rear = -1;
			clear();

		}
		else{
			//q[Front] = {};
			Front = inc(Front);
		}
		csize--;
	}


	void pop_back()
	{
		if(Front == -1 && Rear == -1)
		{
			cout<<"Error : Empty Queue Deletion !!"<<endl;		
			return;
		}

		if(Front == Rear)
		{
			//q[Front] = 0;
			//Front = Rear = -1;
			clear();

		}
		else{
			//q[Rear] = 0;
			Rear = dec(Rear);
		}
		csize--;
	}

	T front()
	{
		return q[Front];
	}

	T back()
	{
		return q[Rear];
	}

	void resize(ll newsize)
	{

		if(csize == 0)
		{
			free(q);
			q = (T *) malloc(sizeof(T)*newsize);
			Front = Rear = -1;
			return;
		}

		if(csize == newsize)
			return;
		else
		{
			if(csize > newsize)
			{
				int extra_elem = csize - newsize;
				while(extra_elem--)
					pop_back();

			}
			else
			{
				int extra_elem = newsize - csize;
				
				while(extra_elem--)
					push_back(front());

			}

		}
	}
	
	T operator [](ll index)
	{
		if(index<csize)
			return q[(index +Front+ msize) % msize];
		else
			throw 1;

	}
	
	void print()
	{
		ll j = Front;
		//cout<<"csize "<<csize<<endl; 
		//cout<<"msize "<<msize<<endl; 
		f(i,0,csize-1)
		{			
			cout<<q[j]<<" ";
			j = inc(j);
		}
		cout<<endl;
	}

	

	bool empty()
	{
		return csize == 0;
	}

	ll size()
	{
		return csize;
	}

	void clear()
	{
		Front = Rear = -1;
		csize = 0;
		free(q);
		msize = QSIZE;
		q = (T *) malloc(sizeof(T)*msize);
	}
};

