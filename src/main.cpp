#include <iostream>
#include <ctime>
#include "src/person.hpp"
#include "src/job.hpp"
#include "src/resource.hpp"
#include <vector>

int main()
{

    std::vector<pme::PersonInterface*> people{};
    std::vector<pme::Farmer> farmers{};
    std::vector<pme::Smith> smiths{};


    for (int i{0}; i < 50; i++)
    {
        farmers.push_back(pme::Farmer("Marez" + i));
        people.push_back(&farmers[i]);
    }

    for (int i{0}; i < 50; i++)
    {
        smiths.push_back(pme::Smith("Denis" + i));
        people.push_back(&smiths[i]);
    }

        std::size_t max_steps{100};
        for(std::size_t i{0U}; i < max_steps; ++i)
    {
        std::cout << "ASDAS" << std::endl;
    }



    return 0;
}