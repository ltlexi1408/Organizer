#ifndef EVENTS
#define EVENTS

#include "base.h"

class event{
    public:
        enum EventType {
            school,
            work,
            friends
        };

        event();
        ~event();

        EventType getEventType();
        date getStartDate();
        date getEndDate();
        bool getComplete();

        void setEvent(EventType event);
        void setStartDate(date startDate);
        void setEndDate(date endDate);
        void setComplete(bool status);

        std::string getEvent();

    private:
        EventType eventType;
        date startDate;
        date endDate;
        bool complete;

};

#endif //EVENTS