/*
    Hero File
    Homework 17 Group Project
    Submission 5/24/2017
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
    
    
    /*-----Overload Operators-----*/
    void operator=(const HeroCharacter&);
    HeroCharacter<T> operator+(const HeroCharacter&);
    HeroCharacter<T> operator-(const HeroCharacter&);
    //prefix
    HeroCharacter<T> operator++();
    //postfix
    HeroCharacter<T> operator++(int);
    bool operator!= (const HeroCharacter&);
    friend ostream& operator<< (ostream& strm, HeroCharacter& obj);
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


/*----Overloaded Operators----*/
template <class T>
void HeroCharacter<T>::operator=(const HeroCharacter & o)
{
    setName(o.Name);
    setGender(o.Gender);
    setRace(o.Race);
    setRace(o.Race);
    setOccupation(o.Occupation);
    setTaSkAb(o.TaSkAb);
    setHeight(o.Height);
    setWeight(o.Weight);
    setHair(o.Hair);
    setEyeColor(o.EyeColor);
    setKingdomConquered(*(o.Conquered));
    setWeapon(o.Weapon);
    setFollowers(o.Followers);
}


template <class T>
//add the follower of the other herocharacter
HeroCharacter<T> HeroCharacter<T>::operator+(const HeroCharacter & o)
{
    HeroCharacter temp;
    temp.Followers = getFollowers() + o.Followers;
    return temp;
}

template <class T>
//subtract the follower of the other herocharacter
HeroCharacter<T> HeroCharacter<T>::operator-(const HeroCharacter & o)
{
    HeroCharacter temp;
    temp.Followers = getFollowers() - o.Followers;
    if(temp.Followers < 0)
        temp.Followers = 0;
    return temp;
}

//prefix
//increase the follower of the herocharacter by 10
template <class T>
HeroCharacter<T> HeroCharacter<T>::operator++()
{
    Followers += 10;
    return *this;
}

//postfix

template <class T>
HeroCharacter<T> HeroCharacter<T>::operator++(int)
{
    HeroCharacter temp = * this;
    Followers -= 10;
    return temp;
}

//not equal operator
template <class T>
bool HeroCharacter<T>::operator!=(const HeroCharacter & o)
{
    if (this->Height != o.Height)
    {
        return true;
    }
    if (this->Weight != o.Weight)
    {
        return true;
    }
    if (this->Followers != o.Followers)
    {
        return true;
    }
    return false;
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
ostream &operator<< (ostream& strm, HeroCharacter<T>& obj)
{
    if (obj.getName() == "" && obj.getGender() == "")
    {
        strm << "Character Doesn't Exist." << endl << endl;
    }
    else
    {
        strm << "MY NAME IS " << obj.getName() << " ";
        obj.shout();
        obj.shout2();
        strm << "Name: " << obj.getName() << endl
        << "Gender: " << obj.getGender() << endl
        << "Race: " << obj.getRace() << endl
        << "Occupation: " << obj.getOccupation() << endl
        << "Talents, Abilities, or Skills: " << obj.getTaSkAb() << endl
        << "Level: " << obj.getLevel() << endl
        << "Hair: " << obj.getHair() << endl
        << "Eyes Color: " << obj.getEyeColor() << endl
        << "Weight: " << obj.getWeight() << " kg" << endl
        << "Height: " << obj.getWeight() << " cm" << endl
        << "Kingdom Conquered: " << obj.getKingdomConquered() << endl
        << "Weapon: " << obj.getWeapon() << endl
        << "Number of followers: " << obj.getFollowers() << endl << endl;
    }
    return strm;
}

template <class T>
void HeroCharacter<T>::shout()
{
	cout << "YOWZA I M A HERO" << endl;
}

template <class T>
void HeroCharacter<T>::cry()
{
	cout << "HEROES!" << endl;
}

#endif /* HEROCHARACTER_H */

