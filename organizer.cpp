#include "event.h"
#include "base.h"
#include <vector>

void menu();

void list(std::vector<event> *eventList);
void add(std::vector<event> *eventList);
void remove(std::vector<event> *eventList);

int main(){
    std::vector<event> *eventList;

    //Load events

    char option;

    menu();

    while(std::cin >> option){ 
        switch(option){
            case 'L':
            case 'l':
                list(eventList);
                break;
            case 'A':
            case 'a':
                add(eventList);
                break;
            case 'R':
            case 'r':
                remove(eventList);
                break;
        }
        
        menu();
    }
}

void menu(){
    printf("l: list current events\n");
    printf("a: add new event\n");
    printf("r: remove event\n");
    printf(">");
}

void list(std::vector<event> *eventList){
    printf("list\n");
}

void add(std::vector<event> *eventList){
    printf("add\n");
}

void remove(std::vector<event> *eventList){
    printf("remove\n");
}