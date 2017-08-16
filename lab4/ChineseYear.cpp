#include <iostream>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <string>
#include <stdio.h>
#include "ChineseYear.hpp"

#define CYCLE_YEARS    12

using namespace std;

// Casts to silence compilation warnings
static char *G_animals[CYCLE_YEARS + 1] =
                    {(char *)"Rat",
                     (char *)"Ox",
                     (char *)"Tiger",
                     (char *)"Rabbit",
                     (char *)"Dragon",
                     (char *)"Snake",
                     (char *)"Horse",
                     (char *)"Goat",
                     (char *)"Monkey",
                     (char *)"Rooster",
                     (char *)"Dog",
                     (char *)"Pig",
                     NULL};

//
// --   Utility functions
//
//由string得到对应数字
static int animal_pos(string animal) {
    int         i = 0;
    const char *a = animal.c_str();

    G_animals[CYCLE_YEARS] = (char *)a;
    while (strcasecmp(G_animals[i], (char *)a)) {
      i++;
    }
    if (i == CYCLE_YEARS) {
      return -1;
    }
    return i;
}
//是否存在这个animal
static bool valid_animal(string animal) {
    return (animal_pos(animal) == -1 ? false : true);
}
//由数字返回animal
static string animal(int pos) {
    if ((pos >= 0) && (pos < CYCLE_YEARS)) {
      return string(G_animals[pos]);
    }
    return NULL;
}

//
// From now on, it’s you turn to write the code for constructors,
// operators and friend functions …`
//
int getGregByAnimal(string animal){
  return (animal_pos(animal)-1+2008);
}
string getAnimalByYear(int greg)
{
  return animal(((greg-1900) % 12) +1);
}
ChineseYear::ChineseYear()
{
  _animal="Rooster";
  _greg=2017;
}
ChineseYear::ChineseYear(string animal)
{
    if(!valid_animal(animal))
    {
      ChineseYear::WrongChineseYear _x = ChineseYear::WrongChineseYear();
      std::cout << _x.what() << '\n';
    }
    else
    {
      _animal=animal;
      _greg=getGregByAnimal(animal);
    }

}
ChineseYear::ChineseYear(int year)
{
  if(year < 1900)
  {
  ChineseYear::WrongGregorianYear _x = ChineseYear::WrongGregorianYear();
  std::cout << _x.what() << '\n';
  }
  else
  {
    _animal=getAnimalByYear(year);
    _greg=year;
  }

}

//friend function
ostream& operator<<(std::ostream &os,const ChineseYear &cy)
{
  os<< cy._animal << " " << cy._greg << "-" << cy._greg+1 ;
  return os;
}

ChineseYear operator+(int a,ChineseYear &cy)
{
  cy.setGreg(a+cy._greg);
  cy.setAnimal(getAnimalByYear(cy._greg));
  return cy;
}
ChineseYear operator+(ChineseYear &cy,int a)
{
  cy.setGreg(a+cy._greg);
  cy.setAnimal(getAnimalByYear(cy._greg));
  return cy;
}
ChineseYear operator+=(ChineseYear &cy,int a)
{
  cy.setGreg(a+cy._greg);
  cy.setAnimal(getAnimalByYear(cy._greg));
  return cy;
}
