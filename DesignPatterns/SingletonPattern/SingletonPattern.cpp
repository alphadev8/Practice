// SingletonPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Database {

public:
    static Database& getInstance()
    {
        static Database dbobj;
        return dbobj;
    }

    void printData() {
        std::cout << "Printing data!!" <<"\n";
    }

private:
    Database() {};
    ~Database() {};

    Database(const Database& instance) = delete;
    Database operator = (const Database&) = delete;
};

int main()
{
    Database& obj0= Database::getInstance();
    Database& obj1 = Database::getInstance();
    obj0.printData();
    obj1.printData();

    std::cout <<"The address of instance: obj0:" << &obj0 << "\n";
    std::cout << "The address of instance: obj1:" << &obj1<<"\n";

}
