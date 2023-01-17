#ifndef EVENTS
#define EVENTS

#include "base.h"

class event{
    public:
        event();
        ~event();

        std::string getEventType();
        date getStartDate();
        date getEndDate();
        bool getComplete();

        void setEvent(std::string eventType);
        void setStartDate(date startDate);
        void setEndDate(date endDate);
        void setComplete(bool status);

        std::string getEvent();

    private:
        std::string eventType;
        date startDate;
        date endDate;
        bool complete;
};

#endif //EVENTS