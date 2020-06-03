#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <Windows.h>
#include <list>

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

void lab3()
{
	/*
	проверить, дек пуст/не пуст;
	добавить элемент в левый конец дека;
	добавить элемент в правый конец дека;
	удалить элемент слева;
	удалить элемент справа;
	просмотреть элемент слева;
	просмотреть элемент справа;
	обмен€ть значени€ми элементы на концах дека;
	*/
	
	list<PVOID> query;
	int choise = 0;
	bool isEmpty = false;
	while (!isEmpty) {
		cout << "-----------Menu------------" << endl;
		cout << "1. check" << endl
			<< "2. add left" << endl
			<< "3. add right" << endl
			<< "4. delete left" << endl
			<< "5. delete right" << endl
			<< "6. read left" << endl
			<< "7. read right" << endl
			<< "8. swap" << endl
			<< "9. clear" << endl
			<< "0. exit" << endl;
		cout << "Input choise:";
		cin >> choise;
		switch (choise)
		{
		case 1: {
			if (query.empty())
				cout << "List is empty" << endl;
			else
				cout << "List is not empty" << endl;
		}
			  break;
		case 2: {
			PVOID Region = VirtualAlloc(NULL, 15 * 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			query.push_front(Region);
		}
			  break;
		case 3: {
			PVOID Region = VirtualAlloc(NULL, 15 * 1024, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
			query.push_back(Region);
		}
			  break;
		case 4: {
			if (query.empty())
				cout << "List is empty" << endl;
			else {
				PVOID Region = query.front();
				cout << "Head is deleted: " << endl;
				VirtualFree(query.front(), 0, MEM_RELEASE);
				query.pop_front();
			}
		}
			  break;
		case 5: {
			if (query.empty())
				cout << "List is empty" << endl;
			else {
				PVOID Region = query.back();
				cout << "Head is deleted: " << endl;
				VirtualFree(query.back(), 0, MEM_RELEASE);
				query.pop_front();
			}
		}
			  break;
		case 6: {
			if (query.empty())
				cout << "List is empty" << endl;
			else {
				PVOID Region = query.front();
				cout << "front: " << Region << endl;
			}
		}
			  break;
		case 7: {
			if (query.empty())
				cout << "List is empty" << endl;
			else {
				PVOID Region = query.back();
				cout << "back: " << Region << endl;
			}
		}
			  break;
		case 8: {
			PVOID Front = query.front();
			PVOID Back = query.back();
			if (query.empty())
				cout << "List is empty" << endl;
			else {
				VirtualFree(query.front(), 0, MEM_RELEASE);
				query.pop_front();
				VirtualFree(query.back(), 0, MEM_RELEASE);
				query.pop_back();
				query.push_front(Back);
				query.push_back(Front);
			}
		}
			  break;
		case 9: 
			system("cls");
			break;
		case 0:
			system("cls");
			return;
			break;
		default: 
			cout << "Wrong imput!" << endl;
			break;
		}
	}

}

int main()
{
	setlocale(LC_ALL,"ru");

	string str;
	cout << "¬ведите строку. (использовать только латинские буквы)" << endl;
	cin >> str;
	cout << endl;

	lab1(str);

	lab2(str);

	lab3();

	return 0;
}
