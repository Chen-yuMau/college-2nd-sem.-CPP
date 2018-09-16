#ifndef CircularDequeTemplate
#define CircularDequeTemplate
using namespace std;

template<class T> class CirDequeTemplate;
template<class T> std::ostream& operator<< (std::ostream& o, const CirDequeTemplate<T>& q);


template <class T>
class CirDequeTemplate{
	
	private:
		T data[10];
		int front, rear;
    
    public:
		CirDequeTemplate(){rear = front = 9;};
		void push_front(T);  // push an element to the front of the deque
		void push_back(T);   // push an element to the end of the deque
		T pop_front();       // pop an element from the front of the deque
		T pop_back();        // pop an element from the end of the deque
		friend ostream& operator<< <>(ostream&, const CirDequeTemplate&);  
		// print the elements in queue from front to rear and separate each element by a space.
};
// you may write your code below this line
template <class T>
void CirDequeTemplate<T>::push_front(T n)
{
	int k;
	k=this->front-1;
	if(k<0)
	{
		k=9;
	}
	if(k==this->rear)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
	this->front=k;
	this->data[k]=n;
	}
	return;
}
template <class T>
void CirDequeTemplate<T>::push_back(T n)
{
	int k;
	k=this->rear+1;
	if(k>9)
	{
		k=0;
	}
	if(k==this->front)
	{
		cout<<"queue is full"<<endl;
	}
	else
	{
	this->data[this->rear]=n;
	this->rear=k;
	}
	return;
}
template <class T>
T CirDequeTemplate<T>::pop_front()
{
	if(front!=rear)
	{
	int n=data[front];
	front++;
	if(front>9)
		{
			front=0;
		}
	return(n);
	}
	else
	{
		cout<<"deque is empty"<<endl;
		return(0);
	}
}
template <class T>
T CirDequeTemplate<T>::pop_back()
{
	if(front!=rear)
	{
	rear--;
		if(rear<0)
		{
			rear=9;
		}
	int n=data[rear];
	return(n);
	}
	else
	{
		cout<<"deque is empty"<<endl;
		return(0);
	}
}
template <class T>
ostream& operator<<(ostream&o, const CirDequeTemplate<T>&C)
{
		for(int i=C.front;i!=C.rear;i++)
	{
		if(i>9)
		{
			i=0;
			if(i==C.rear)
			{
				break;
			}
		}
		
		o<<C.data[i]<<" ";
	}
	return(o);
}
// you may write your code above this line
#endif
