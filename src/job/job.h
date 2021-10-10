#include "src/resource/resource.h"

#ifndef JOB_H_
#define JOB_H_

class Job {};


class Farmer : public Job
{
    public:
        Grain work()
        {
            return Grain(2);
        }
};

class Smith : public Job
{
    public:
        Tool work()
        {
            return Tool(1);
        }
};


template<class>
struct producer_of {};

template<>
struct producer_of<Grain>
{
    using job = Farmer;
};

template<>
struct producer_of<Tool>
{
    using job = Smith;
};

#endif // JOB_H_