// CommandPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Command {
public:
    virtual void Execute() = 0;
};

//The concrete command classes

class ConcreteCommand1:public Command{
public:
    void Execute() {
        std::cout << "Executing concrete command1" << "\n";
    }
};

class ConcreteCommand2 :public Command {
public:
    void Execute() {
        std::cout << "Executing concrete command2" << "\n";
    }
};

//invoker class

class Invoker {
private:
    Command* m_command;

public:
    void SetCommand(Command* command) {
        m_command = command;
    }
public:
    void executeCommand()
    {
        m_command->Execute();
    }
};

int main()
{
    Invoker inv;
    ConcreteCommand1 cc0;
    ConcreteCommand2 cc1;

    inv.SetCommand(&cc0);
    inv.executeCommand();

    inv.SetCommand(&cc1);
    inv.executeCommand();

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
