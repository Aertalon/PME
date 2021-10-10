#include <gtest/gtest.h>
#include "src/person/person.h"
#include "src/job/job.h"


TEST(PersonTest, CreatePerson)
{
  Person<Smith> smith("Joe");
  Person<Farmer> farmer("Marez");
}
