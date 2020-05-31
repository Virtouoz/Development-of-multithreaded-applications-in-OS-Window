#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

void Work1(string str)
{
	cout << "ID потока = " << this_thread::get_id() << "\tWork1" << endl;
	int a;
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] - 129;
		cout << str[i];
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL,"ru");

	string str;
	cout << "Введите строку. (использовать только латинские буквы)" << endl;
	cin >> str;
	cout << endl;

	thread th1(Work1,str);
	th1.join();

	return 0;
}
