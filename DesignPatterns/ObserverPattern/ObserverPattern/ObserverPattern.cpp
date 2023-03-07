// ObserverPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

class Observer {

public:

	//interface for update value
	virtual void update(int value) = 0;

};

class Subject {
	int value;
	std::vector<Observer*> Observers;  //vector of observers

public:
	void attach(Observer* observer) {  //subscribe observer
		Observers.emplace_back(observer);
	}
public:
	void set_value(int newValue) {    //real-time value
		value = newValue;
		notify();
	}
public:
	void notify() {
		for (Observer* observer : Observers)
		{
			observer->update(value);
		}
	}
};

class ConcreteObserver1 :public Observer {
int value;
public:
	
	//constructor to initialize value
	ConcreteObserver1 (int v): value(v) {}

	void update(int newValue)
	{
		value = newValue;
		std::cout << newValue << "\n";
	}
};

int main()
{
	Subject sobj;
	ConcreteObserver1 c_ob1(0);
	ConcreteObserver1 c_ob2(1);
	sobj.attach(&c_ob1);
	sobj.attach(&c_ob2);
	sobj.set_value(10);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
