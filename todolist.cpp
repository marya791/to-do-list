#include "todolist.h"
#include <iostream>

using namespace std;

bool todolist::isempty() {
    return (head == nullptr);
}

bool todolist::found(const string& taskk) {
    Task* temp = head;
    while (temp != nullptr) {
        if (temp->task == taskk)
            return true;
        temp = temp->next;
    }
    return false;
}

void todolist::addtask(const string& taskk) {
    Task* newtask = new Task{ taskk, false, nullptr };

    if (isempty()) {
        head = newtask;
    }
    else {
        Task* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newtask;
    }

    cout << "Task added." << endl;
}

void todolist::removetask(const string& taskk) {
    Task* delptr = head;
    Task* prev = nullptr;

    if (found(taskk)) {
        if (delptr->task == taskk) {
            head = delptr->next;
            delete delptr;
            cout << "Task removed." << endl;
            return;
        }

        while (delptr != nullptr && delptr->task != taskk) {
            prev = delptr;
            delptr = delptr->next;
        }

        if (delptr != nullptr) {
            prev->next = delptr->next;
            delete delptr;
            cout << "Task removed." << endl;
            return;
        }
    }

    cout << "Task not found." << endl;
}

void todolist::displaytodolist() {
    if (isempty()) {
        cout << "todolist is empty." << endl;
        return;
    }

    Task* temp = head;
    while (temp != nullptr) {
        cout << temp->task << " ";
        if (temp->done) {
            cout << "is done." << endl;
        }
        else {
            cout << "not done." << endl;
        }
        temp = temp->next;
    }
}

void todolist::marktaskdone(const string& taskk) {
    if (found(taskk)) {
        Task* temp = head;
        while (temp != nullptr) {
            if (temp->task == taskk) {
                temp->done = true;
                cout << "Task marked as done." << endl;
                return;
            }
            temp = temp->next;
        }
    }

    cout << "Task not found." << endl;
}

void todolist::istaskdone(const string& taskk) {
    if (found(taskk)) {
        Task* temp = head;
        while (temp != nullptr) {
            if (temp->task == taskk) {
                if (temp->done)
                    cout << taskk << " is done." << endl;
                else
                    cout << taskk << " not done." << endl;
                return;
            }
            temp = temp->next;
        }
    }
    else {
        cout << "Task not found." << endl;
    }
}
   int todolist::count() {
    int counter = 0;
    Task* temp = head;
    while (temp!= nullptr) {
        counter++;
        temp =temp->next;
    }
    return counter;
}

// Destructor 
todolist::~todolist() {
    while (head != nullptr) {
        Task* temp = head;
        head = head->next;
        delete temp;
    }
}
