/* 
 * File:   HeroCharacter.h
 * Author: Anh (Andrew) Tran
 *
 * Created on May 9, 2017
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
    
    ~HeroCharacter();

    /*-----SETTERS-----*/
    void setWeapon (string);
    void setFollowers (int);

    /*-----GETTERS-----*/
    string getWeapon();
    int getFollowers();

    /*-----FUNCTIONS-----*/
    void displayInfo();

	//dynamic
	void shout();
};



#endif /* HEROCHARACTER_H */

