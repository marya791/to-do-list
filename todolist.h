#pragma once
#include <string>
using namespace std;
struct Task {
    string task;
    bool done;
    Task* next;
};

class todolist {
private:
    Task* head;
public:
    todolist() {
        Task* head = NULL;
    }
   
    bool isempty();
    bool found(const string& taskk);
   
    void addtask(const string& taskk);

    void removetask(const string& taskk);

    void displaytodolist();

     void marktaskdone(const string& taskk);

 
    void istaskdone(const string& taskk);
    int  count();
    ~todolist();
};