/*
    Hero File
    Homework 15 Group Project 
    Submission 5/10/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Anh Tran (Andrew)
*/

#ifndef HEROCHARACTER_H
#define HEROCHARACTER_H
#include "Character.h"

#include <string>

using namespace std;

class HeroCharacter : public Character
{
private:
    string Weapon;
    int Followers;

public:
    /*-----CONSTRUCTORS-----*/
    HeroCharacter();
    HeroCharacter (string, string, string, int, int, int, int, int, int, int,
                   string, int);
    
    HeroCharacter (const HeroCharacter&);
    

    /*-----SETTERS-----*/
    void setWeapon (string);
    void setFollowers (int);

    /*-----GETTERS-----*/
    string getWeapon();
    int getFollowers();

    /*-----FUNCTIONS-----*/
    void displayInfo();

    //dynamic binding
    void shout();
    
    // static binding
    void cry();
};



#endif /* HEROCHARACTER_H */

