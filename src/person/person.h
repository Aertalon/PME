#include <string>
#include "src/job/job.h"

#ifndef PERSON_H_
#define PERSON_H_

template<
    class J//,
    //class std::enable_i<std::is_base_of<Job, J>::value>
    >
class Person
{
    std::string name_;
    J job_;

    public:
        Person(std::string name) :
            name_(name),
            job_{}
            {}

        // Buys at most a quantity q of resource R
        template<class R>
        void buy(R q)
        {
            //Person find_seller<R>(); // optional?

        }

        // Finds a seller of resource R
        // TODO: cannot return a person, must return a ref (optional?)
        template<class R>
        auto find_seller() -> Person<typename producer_of<R>::job>
        {
            using person_job = typename producer_of<R>::job;
            return Person<person_job>{};
        }
};

#endif // PERSON_H_