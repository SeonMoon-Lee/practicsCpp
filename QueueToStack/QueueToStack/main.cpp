#include <iostream>
#include<queue>

using namespace std;

template <typename T>
class QueueToStack
{
	queue<T> inQueue;
	queue<T> outQueue;
	public:

	void Enqueue(T data)
	{
		inQueue.push(data);
	}
	T DeQueue()
	{
		if (isEmpty())
			return 0;

		T data = inQueue.back();
		outQueue.push(data);

		data = outQueue.front();
		outQueue.pop();

		while (inQueue.size() > 1)
		{
			T temp = inQueue.front();
			inQueue.pop();
			outQueue.push(temp);
		}
		inQueue.pop();
		while (outQueue.size() > 0)
		{
			T temp = outQueue.front();
			outQueue.pop();
			inQueue.push(temp);
		}
		return data;
	}
	bool isEmpty()
	{
		return inQueue.size() == 0 && outQueue.size() == 0;
	}
};
int main()
{
	QueueToStack<int> test1;

	test1.Enqueue(1);
	test1.Enqueue(2);
	test1.Enqueue(3);
	test1.Enqueue(4);

	cout << test1.DeQueue() << endl;
	cout << test1.DeQueue() << endl;
	cout << test1.DeQueue() << endl;

	test1.Enqueue(5);
	test1.Enqueue(6);

	cout << test1.DeQueue() << endl;
	cout << test1.DeQueue() << endl;

	return 0;
}




