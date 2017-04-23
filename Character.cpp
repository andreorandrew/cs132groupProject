//
//  Character.cpp
//  
//
//  Created by Jia Na on 4/23/17.
//
//

#include "Character.h"
#include <string>

//constant arrays for randomize character
const string NAME[] = {"Andrew", "Theo", "Hailey", "Vera"};
const string GENDER[] = {"female", "male"};
const string RACE[] = {"human", "not human"};
const string OCCUPATION[] = {"fighter", "wizard", "cleric"};
const string TASKAB[] = {"Cooking", "Cleaning", "Dying"};
const string HAIR[] = {"short black", "long white", "short gold"};
const string EYECOLOR[] = {"black", "blue", "brown", "green"};

Character :: Character () {
    
    int randomSelector;
    
    randomSelector = rand() % sizeof(NAME) / sizeof(NAME[0]);
    setName(NAME[randomSelector]);
    
    randomSelector = rand() % sizeof(GENDER) / sizeof(GENDER[0]);
    setGender(GENDER[randomSelector]);
    
    randomSelector = rand() % sizeof(RACE) / sizeof(RACE[0]);
    setRace(RACE[randomSelector]);
    
    randomSelector = rand() % sizeof(OCCUPATION) / sizeof(OCCUPATION[0]);
    setOccupation(OCCUPATION[randomSelector]);
    
    randomSelector = rand() % sizeof(TASKAB) / sizeof(TASKAB[0]);
    setTaSkAb(TASKAB[randomSelector]);
    
    setHeight(rand() & 200 + 100);
    setWeight(rand() & 200 + 50);
    
    randomSelector = rand() % sizeof(HAIR)/sizeof(HAIR[0]);
    setHair(HAIR[randomSelector]);
    
    randomSelector = rand() % sizeof(EYECOLOR)/sizeof(EYECOLOR[0]);
    setEyeColor(EYECOLOR[randomSelector]);
    
}

/*-----SETTERS-----*/
void Character :: setName(string name)
{
    Name = name;
}

void Character :: setGender(string gender)
{
    Gender = gender;
}

void Character :: setRace(string race)
{
    Race = race;
}

void Character :: setOccupation(string occ)
{
    Occupation = occ;
}

void Character :: setTaSkAb(string taskab)
{
    TaSkAb = taskab;
}

void Character :: setHeight(int height)
{
    Height = height;
}

void Character :: setWeight(int weight)
{
    Weight = weight;
}

void Character :: setHair (string hair)
{
    Hair = hair;
}

void Character :: setEyeColor(string eye)
{
    EyeColor = eye;
}

/*-----GETTERS-----*/
string Character :: getName() {
    return Name;
}
string Character :: getGender() {
    return Gender;
}
string Character :: getRace() {
    return Race;
}
string Character :: getTaSkAb() {
    return TaSkAb;
}
int Character :: getHeight() {
    return Height;
}
int Character :: getWeight() {
    return Weight;
}
string Character :: getHair() {
    return Hair;
}
string Character :: getEyeColor() {
    return EyeColor;
}
