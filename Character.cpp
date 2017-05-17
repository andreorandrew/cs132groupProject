/*
    Character File
    Homework 16 Group Project 
    Submission 5/17/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Anh Tran (Andrew)
*/

//header files
#include "Character.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//constant arrays for randomize character options
string NAME[] = { "Andrew", "Theo", "Hailey", "Vera" };
string GENDER[] = { "female", "male" };
string RACE[] = { "human", "not human" };
string OCCUPATION[] = { "fighter", "wizard", "cleric" };
string TASKAB[] = { "Cooking", "Cleaning", "Dying" };
string HAIR[] = { "short black", "long white", "short gold" };
string EYECOLOR[] = { "black", "blue", "brown", "green" };
string KINGDOM[] = { "Goat Town", "Sheep Village", "Westeros", "Narnia" };

Character::Character()
{
	// Get the system time.
	unsigned seed = time(0);
	srand(seed);
	//customized random number
	int randomSelector;
	//for all character's characteristics, a random number within a customized range
	//is chosen. An element from the respective array will be randomly chosen and set
	//to the Character (assigned to Character's respective field)
	randomSelector = rand() % (sizeof(NAME) / sizeof(NAME[0]));
	setName(NAME[randomSelector]);

	randomSelector = rand() % (sizeof(GENDER) / sizeof(GENDER[0]));
	setGender(GENDER[randomSelector]);

	randomSelector = rand() % (sizeof(RACE) / sizeof(RACE[0]));
	setRace(RACE[randomSelector]);

	randomSelector = rand() % (sizeof(OCCUPATION) / sizeof(OCCUPATION[0]));
	setOccupation(OCCUPATION[randomSelector]);

	randomSelector = rand() % (sizeof(TASKAB) / sizeof(TASKAB[0]));
	setTaSkAb(TASKAB[randomSelector]);

	setLevel(rand() % 10);
	setHeight((rand() % 200) + 100);
	setWeight((rand() % 100) + 50);


	randomSelector = rand() % (sizeof(HAIR) / sizeof(HAIR[0]));
	setHair(HAIR[randomSelector]);

	randomSelector = rand() % (sizeof(EYECOLOR) / sizeof(EYECOLOR[0]));

	setEyeColor(EYECOLOR[randomSelector]);

	Conquered = new string;
	randomSelector = rand() % (sizeof(KINGDOM) / sizeof(KINGDOM[0]));
	setKingdomConquered(KINGDOM[randomSelector]);
}

Character::Character(string name, string occupation, string talent, int height,
	int weight, int gChoice, int rChoice, int hChoice, int eChoice,
	int kChoice)
{
	setName(name);
	setGender(GENDER[gChoice - 1]);
	setRace(RACE[rChoice - 1]);
	setOccupation(occupation);
	setTaSkAb(talent);
	setLevel(0);
	setHeight(height);
	setWeight(weight);
	setHair(HAIR[hChoice - 1]);
	setEyeColor(EYECOLOR[eChoice - 1]);

	Conquered = new string;
	setKingdomConquered(KINGDOM[kChoice - 1]);
}

// copy constructor
Character::Character(const Character &o)
{
	setName(o.Name);
	setGender(o.Gender);
	setRace(o.Race);
	setRace(o.Race);
	setOccupation(o.Occupation);
	setTaSkAb(o.TaSkAb);
	setLevel(o.level);
	setHeight(o.Height);
	setWeight(o.Weight);
	setHair(o.Hair);
	setEyeColor(o.EyeColor);
	Conquered = new string;
	setKingdomConquered(*(o.Conquered));
}

/*-----SETTERS-----*/
void Character::setName(string name)
{
	Name = name;
}

void Character::setGender(string gender)
{
	Gender = gender;
}

void Character::setRace(string race)
{
	Race = race;
}

void Character::setOccupation(string occ)
{
	Occupation = occ;
}

void Character::setTaSkAb(string taskab)
{
	TaSkAb = taskab;
}

void Character::setLevel(int n)
{
	level = n;
}
void Character::setHeight(int height)
{
	if (height <= 0) throw InvalidHeight(height);
	else Height = height;
}

void Character::setWeight(int weight)
{
	if (weight <= 0) throw InvalidWeight(weight);
	else Weight = weight;
}

void Character::setHair(string hair)
{
	Hair = hair;
}

void Character::setEyeColor(string eye)
{
	EyeColor = eye;
}

void Character::setKingdomConquered(string king)
{
	*Conquered = king;
}

/*-----GETTERS-----*/
string Character::getName() {
	return Name;
}
string Character::getGender() {
	return Gender;
}
string Character::getRace() {
	return Race;
}
string Character::getOccupation()
{
	return Occupation;
}
string Character::getTaSkAb()
{
	return TaSkAb;
}
int Character::getLevel()
{
	return level;
}
int Character::getHeight() {
	return Height;
}
int Character::getWeight() {
	return Weight;
}
string Character::getHair() {
	return Hair;
}
string Character::getEyeColor() {
	return EyeColor;
}

string Character::getKingdomConquered()//theo edit
{
	return *Conquered;
}

//member function that displays all the Character's characteristics
void Character::displayInfo()
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
			<< "Kingdom Conquered: " << getKingdomConquered() << endl << endl;

	}
}

/*-----Overload Operators-----*/
// set a character equal to another character through memberwise assignment
void Character::operator=(const Character& o)
{
	//delete[] Conquered;
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
	Conquered = new string;
	setKingdomConquered(*(o.Conquered));
}

// add the heights of the characters
Character Character::operator+(const Character& right)
{
	Character temp;
	temp.Height = Height + right.Height;
	return temp;
}

// get the difference in height of the characters
// if it becomes negative then sets the height to 1
Character Character::operator-(const Character& right)
{
	Character temp;
	temp.Height = Height - right.Height;
	if (temp.Height < 0)
	{
		temp.Height = 1;
	}
	return temp;
}

// ++ overloader
// increment the character's level by 1
// prefix
Character Character :: operator++() {
	level++;
	return *this;
}

// postfix
Character Character :: operator++(int) {
	Character temp = *this;
	level++;
	return temp;
}

void Character::shout()
{
	cout << "YOWZEE I'M A CHARACTER" << endl;
}

void Character::cry()
{
    cout << "CHARACTERS!" << endl;
}

void Character::shout2()
{
    cry();
    cout << " WE RULE!" << endl;
}
