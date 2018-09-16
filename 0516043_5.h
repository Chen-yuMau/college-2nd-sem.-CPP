#ifndef CircularDeque
#define CircularDeque
using namespace std;
class CirDeque{
	
	private:
		int data[10];
		int front, rear;
    
    public:
		CirDeque(){rear = front = 9;};
		void push_front(int);  // push an element to the front of the deque
		void push_back(int); // push an element to the end of the deque
		int pop_front();       // pop an element from the front of the deque
		int pop_back();        // pop an element from the end of the deque
		friend ostream& operator<<(ostream&, const CirDeque&);  
		// print the elements in queue from front to rear and separate each element by a space.
};
// you may write your code below this line
void CirDeque::push_front(int n)
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
void CirDeque::push_back(int n)
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
int CirDeque::pop_front()
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
int CirDeque::pop_back()
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
ostream& operator<<(ostream& c, const CirDeque& d);
{
	for(int i=d.front;i!=d.rear;i++)
	{
		if(i>9)
		{
			i=0;
		}
		c<<d.data[i];
	}
	return(c);
}
// you may write your code above this line
#endif
