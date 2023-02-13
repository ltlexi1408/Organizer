#ifndef EVENTS
#define EVENTS

#include "../base.h"

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
        std::string getDescription();

        void setEvent(EventType event);
        void setStartDate(date startDate);
        void setEndDate(date endDate);
        void setDescription(std::string description);
        void setComplete(bool status);

        std::string getEvent();

    private:
        EventType eventType;
        date startDate;
        date endDate;
        std::string description;
        bool complete;

};

#endif //EVENTS