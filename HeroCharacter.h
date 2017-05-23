/*
    Hero File
    Homework 16 Group Project 
    Submission 5/17/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Anh Tran (Andrew)
*/

#ifndef HEROCHARACTER_H
#define HEROCHARACTER_H
#include "Character.h"

#include<iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
string WEAPONS[] = { "Sword", "Axe", "Laser Beam", "Lightning Bolt" };

template <class T>
class HeroCharacter : public Character
{
private:
    string Weapon;
    T Followers;

public:
    /*-----CONSTRUCTORS-----*/
    HeroCharacter();
    HeroCharacter (string, string, string, int, int, int, int, int, int, int,
                   string, T);
    
    HeroCharacter (const HeroCharacter&);
    

    /*-----SETTERS-----*/
    void setWeapon (string);
    void setFollowers (int);

    /*-----GETTERS-----*/
    string getWeapon();
    T getFollowers();

    /*-----FUNCTIONS-----*/
    void displayInfo();

    //dynamic binding
    void shout();
    
    // static binding
	void cry();
};

template <class T>
HeroCharacter<T>::HeroCharacter() : Character()
{
	// Get the system time.
	unsigned seed = time(0);
	srand(seed);
	//customized random number
	int randomSelector;
	//for all character's characteristics, a random number within a customized range
	//is chosen. An element from the respective array will be randomly chosen and set
	//to the Character (assigned to Character's respective field)

	setHair("Bald");
	setOccupation("Hero");

	randomSelector = rand() % (sizeof(WEAPONS) / sizeof(WEAPONS[0]));
	setWeapon(WEAPONS[randomSelector]);

	randomSelector = (rand() % 1000) + 1;
	setFollowers(randomSelector);
}

/*-----SETTERS-----*/
template <class T>
void HeroCharacter<T>::setWeapon(string weapon)
{
	Weapon = weapon;
}

template <class T>
void HeroCharacter<T>::setFollowers(int follow)
{
	Followers = follow;
}

/*-----GETTERS-----*/
template <class T>
string HeroCharacter<T>::getWeapon()
{
	return Weapon;
}

template <class T>
T HeroCharacter<T>::getFollowers()
{
	return Followers;
}

/*-----FUNCTIONS-----*/
template <class T>
void HeroCharacter<T>::displayInfo()
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

template <class T>
void HeroCharacter<T>::shout()
{
	cout << "YOWZA IM A HERO" << endl;
}

template <class T>
void HeroCharacter<T>::cry()
{
	cout << "HEROES!" << endl;
}

#endif /* HEROCHARACTER_H */

