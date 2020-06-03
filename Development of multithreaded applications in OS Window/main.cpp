#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <Windows.h>

using namespace std;

void Work1(string str)
{
	cout << "ID потока = " << this_thread::get_id() << endl;
	int a;
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] - 129;
		cout << str[i];
	}
	cout << endl << endl;
}

void lab1(string str)
{
	auto start = chrono::system_clock::now();

	thread th1(Work1, str);
	th1.join();

	auto end = chrono::system_clock::now();

	chrono::duration<double> time = end - start;
	cout << "Time = " << time.count() << endl;
}

void lab2(string str)
{
	auto start1 = chrono::system_clock::now();

	thread th1(Work1, str);
	SetThreadPriority(th1.native_handle(), THREAD_PRIORITY_NORMAL);
	th1.join();

	auto end1 = chrono::system_clock::now();

	chrono::duration<double> time1 = end1 - start1;
	cout << "Time Normal = " << time1.count() << endl << endl;


	auto start2 = chrono::system_clock::now();

	thread th2(Work1, str);
	SetThreadPriority(th2.native_handle(), THREAD_PRIORITY_TIME_CRITICAL);
	th2.join();

	auto end2 = chrono::system_clock::now();

	chrono::duration<double> time2 = end2 - start2;
	cout << "Time Critical = " << time2.count() << endl << endl;
}

int main()
{
	setlocale(LC_ALL,"ru");

	string str;
	cout << "Введите строку. (использовать только латинские буквы)" << endl;
	cin >> str;
	cout << endl;

	lab1(str);

	lab2(str);

	return 0;
}
