#include <iostream>
#include<queue>

using namespace std;

template <typename T>
class QueueToStack
{
	queue<T> inQueue;
	queue<T> outQueue;
	public:

	void Push(T data)
	{
		inQueue.push(data);
	}
	T Pop()
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
		while (!outQueue.empty())
		{
			T temp = outQueue.front();
			outQueue.pop();
			inQueue.push(temp);
		}
		return data;
	}
	bool IsEmpty()
	{
		return inQueue.empty()&& outQueue.empty();
	}
};
int main()
{
	QueueToStack<int> test1;

	test1.Push(1);
	test1.Push(2);
	test1.Push(3);
	test1.Push(4);

	cout << test1.Pop() << endl;
	cout << test1.Pop() << endl;
	cout << test1.Pop() << endl;

	test1.Push(5);
	test1.Push(6);

	cout << test1.Pop() << endl;
	cout << test1.Pop() << endl;

	return 0;
}




