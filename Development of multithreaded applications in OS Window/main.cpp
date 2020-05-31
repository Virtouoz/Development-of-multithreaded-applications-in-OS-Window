#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Work1()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tWork1" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
}


void Work2()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tWork2" << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main()
{
	setlocale(LC_ALL,"ru");

	thread th1(Work1);
	th1.detach();

	thread th2(Work2);
	th2.join();

	cout << "Star main" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << "\tmain" << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	cout << "End main" << endl;

	
	return 0;
}
