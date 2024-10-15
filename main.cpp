#include <iostream>
#include "todolist.h"

using namespace std;
int main() {
    todolist t1;
    int num;
    string task;
    do {
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Display ToDoList\n";
        cout << "4. Mark Task as Done\n";
        cout << "5. Check if Task is Done\n";
        cout << "6. number of tasks::\n";
        cout << "0 Exit\n";
        cout << "pick a number::\n";
        cin >> num;
        switch (num) {
        case 1: {
            cout << "Enter task: ";
            cin >> task;
            t1.addtask(task);
            break;

        }
        case 2: {
            cout << "Enter the removed one: ";
             cin >> task;
            t1.removetask(task);

            break;

        }
        case 3: {
            cout << "TO DO LIST: ";
            t1.displaytodolist();

            break;

        }    
        case 4: {
            cout << "What is done ?: ";
            cin >> task;
            t1.marktaskdone(task);

            break;
        }
        case 5: {
            cout << "which one u want to check: ";
            cin >> task;
            t1.istaskdone(task);

            break;
        }
        case 6: {
            cout << "Number of tasks:: ";
            cout << t1.count() << endl;
            break;

        }
        case 0: {
            cout << "bye bye: ";

            break;
        }
        default:
            cout << "not an option" << endl;

        
        
        }} while (num != 0);
        return 0;
}