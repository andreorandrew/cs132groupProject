/* 
 * File:   HeroCharacter.cpp
 * Author: Anh (Andrew) Tran
 * 
 * Created on May 9, 2017
 */

#include "HeroCharacter.h"
#include "Character.h"
#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string WEAPONS[] = {"Sword", "Axe", "Laser Beam", "Lightning Bolt"};

/*-----CONSTRUCTORS-----*/
HeroCharacter::HeroCharacter() : Character ()
{
    // Get the system time.
    unsigned seed = time(0);
    srand(seed);
    //customized random number
    int randomSelector;
    //for all character's characteristics, a random number within a customized range
    //is chosen. An element from the respective array will be randomly chosen and set
    //to the Character (assigned to Character's respective field)
    
    setHair ("Bald");
    setOccupation ("Hero");
    
    randomSelector = rand() % (sizeof(WEAPONS) / sizeof(WEAPONS[0]));
    setWeapon (WEAPONS[randomSelector]);
    
    randomSelector = (rand() % 1000) + 1;
    setFollowers (randomSelector);
}

/*-----SETTERS-----*/
void HeroCharacter::setWeapon (string weapon)
{
    Weapon = weapon;
}

void HeroCharacter::setFollowers (int follow)
{
    Followers = follow;
}

/*-----GETTERS-----*/
string HeroCharacter::getWeapon()
{
    return Weapon;
}

int HeroCharacter::getFollowers()
{
    return Followers;
}

/*-----FUNCTIONS-----*/
void HeroCharacter::displayInfo()
{
    if (getName() == "" && getGender() == "")
    {
        cout << "Character Doesn't Exist." << endl << endl;
    }
    else
    {
        cout << "MY NAME IS " << getName() << " ";
        shout();
        cout << "Name: " << getName() << endl
        << "Gender: " << getGender() << endl
        << "Race: " << getRace() << endl
        << "Occupation: " << getOccupation() << endl
        << "Talents, Abiliities, or Skills: " << getTaSkAb() << endl
        << "Level: " << getLevel() << endl
        << "Hair: " << getHair() << endl
        << "Eyes Color: " << getEyeColor() << endl
        << "Weight: " << getWeight() << " kg" << endl
        << "Height: " << getHeight() << " cm" << endl
        << "Kingdom Conquered: " << getKingdomConquered() << endl
        << "Weapon: " << getWeapon() << endl
        << "Number of followers: " << getFollowers() << endl << endl;
        
    }
}

void HeroCharacter::shout()
{
	cout << "YOWZA IM A HERO" << endl;
}
