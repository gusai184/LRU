#include<iostream>
#include <unordered_map>
#include "deque.h"

using namespace std;


template <class T,class U>
class Node
{
	public:
		T key;
		U value;
		bool dirty;
	public:
		Node(T key,U value)
		{
			this->key = key;
			this->value = value;
			dirty = false;
		}
};
/*
template <class T,class U>
std::ostream& operator<<(std::ostream &strm,  Node<T,U> node) {

	return (node->key);
}*/


template <class T,class U>
class LRU
{

	public:
		Deque<Node<T,U>> deq;
		unordered_map<T,ll> mp;
		ll capacity,csize;
	
	public:
		LRU(ll capacity)
		{
			this->capacity = capacity;
			csize = 0;
		}
		void set(T key,U value)
		{
			Node<T,U> node(key,value);
			Node<T,U> temp(key,value);
			if(mp.find(key)==mp.end())
			{
				if(csize < capacity)
				{
					deq.push_back(node);
					mp[key] = deq.Rear;
				}
				else
				{		
					temp = deq.front();			
					deq.pop_front();
					
					while(temp.dirty==true)
					{
						//mp.erase(temp.key);
						temp = deq.front();
						deq.pop_front();
					}
					mp.erase(temp.key);

					deq.push_back(node);
					mp[key] = deq.Rear;
				}

				csize++;
			}
			else
			{
				ll index = mp[key];
				deq.q[index].dirty = true;
				deq.push_back(node);
				mp[key] = deq.Rear;
			}

		}

		pair<bool,U> get(T key)
		{
			U temp;
			if(mp.find(key) == mp.end())
			{
				//cout<<"key not fount ";
				return make_pair(false,temp);
			}
			else
			{
				ll index = mp[key];
				deq.q[index].dirty = true;
				Node<T,U> node = deq.q[index];
				node.dirty = false;
				deq.push_back(node);
				return make_pair(true,deq.q[index].value);
			}
		}

		void printQueue()
		{
			ll j = deq.Front;
			
			f(i,0,deq.csize-1)
			{			
				//cout<<deq.q[j].key<<" : "<<deq.q[j].value<<endl;
				cout<<deq.q[j].key<<" - "<<deq.q[j].value<<" - "<<deq.q[j].dirty<<":";
				j = (j+1)%deq.msize;
			}
			cout<<endl;
			}

			void printmap()
			{
				for(auto i:mp)
					cout<<i.first <<" : "<<i.second<<endl;
			}

};

int main()
{
	
	float key;
	string value;
	ll frames,query;
	char type;
	
	cin>>frames;
	cin>>query;
	LRU <float,string>lru(frames);

	while(query--)
	{
		cin>>type;
		if(type=='G')
		{
			cin>>key;
			pair<bool,string> p = lru.get(key);
			if(p.first==false)
				cout<<"-1"<<endl;
			else
				cout<<p.second<<endl;
		}
		else
		{
			cin>>key>>value;
			lru.set(key,value);
		}
		//lru.printQueue();

	}
	
	return 1;
}
