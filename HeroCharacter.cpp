/*
    Hero File
    Homework 15 Group Project 
    Submission 5/10/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Anh Tran (Andrew)
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
        shout2();
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

void HeroCharacter::cry()
{
    cout << "HEROES!" << endl;
}