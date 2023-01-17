#include "event.h"


event::event(){
    complete = false;
}

event::~event(){

}

std::string event::getEventType(){
    return eventType;
}

date event::getStartDate(){
    return startDate;
}

date event::getEndDate(){
    return endDate;
}

bool event::getComplete(){
    return complete;
}

void event::setEvent(std::string eventType){
    this->eventType = eventType;
}

void event::setStartDate(date startDate){
    this->startDate = startDate;
}

void event::setEndDate(date endDate){
    this->endDate = endDate;
}

void event::setComplete(bool status){
    this->complete = status;
}

std::string event::getEvent(){
    return "Event type: " + eventType + "\n" 
        + "Start date: " + std::to_string(startDate.day) + "/" +  std::to_string(startDate.month) + "/" + std::to_string(startDate.year)+ "\n"
        + "End date: " + std::to_string(endDate.day) + "/" +  std::to_string(endDate.month) + "/" + std::to_string(endDate.year) + "\n"
        + "Complete: " + std::to_string(complete); 
}