#include <iostream>
#include <thread>
#include <mutex>

int gNum = 0;
std::mutex mu;

void thread_function()
{
	std::cout << "Hello" << std::endl;
}

void function1()
{
	for (int i = 0; i < 100000; i++)
	{
		// Turn off the mutex lock to see the numbers unsynchronize
		mu.lock();
		gNum++;
		mu.unlock();
	}
}

int main()
{
	//std::thread t1(&thread_function); // Thread 1
	//std::thread t2(&thread_function); // Thread 2

	std::thread t1(&function1); // Thread 1
	std::thread t2(&function1); // Thread 2

	t1.join();
	t2.join();

	std::cout << gNum << std::endl;

	return 0;
}