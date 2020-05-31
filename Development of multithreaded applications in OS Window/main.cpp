#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");

	cout << "Star main" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << this_thread::get_id() << endl;

	return 0;
}
