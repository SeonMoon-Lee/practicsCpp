#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class StackToQueue
{
	stack<T> inStack;
	stack<T> outStack;

public:
	void Enqueue(T data)
	{
		inStack.push(data);
	}
	T Dequeue()
	{
		if (isEmpty())
			return 0;
		T data;
		while (!inStack.empty())
		{
			data = inStack.top();
			inStack.pop();
			outStack.push(data);
		}
		data = outStack.top();
		outStack.pop();

		while (!outStack.empty())
		{
			T temp = outStack.top();
			outStack.pop();
			inStack.push(temp);
		}

		return data;

	}
	bool isEmpty()
	{
		return inStack.empty()&& outStack.empty();
	}
};

int main()
{
	StackToQueue<int> stackToQueue;
	stackToQueue.Enqueue(1);
	stackToQueue.Enqueue(2);
	stackToQueue.Enqueue(3);
	stackToQueue.Enqueue(4);

	cout << stackToQueue.Dequeue() << endl;
	cout << stackToQueue.Dequeue() << endl;
	cout << stackToQueue.Dequeue() << endl;

	stackToQueue.Enqueue(5);
	stackToQueue.Enqueue(6);

	cout << stackToQueue.Dequeue() << endl;
	cout << stackToQueue.Dequeue() << endl;

	return 0;
}