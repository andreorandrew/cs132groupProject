//
//  Character.cpp
//  
//
//  Created by Jia Na on 4/23/17.
//
//

#include "Character.h"
#include <string>

//ocnstant arrays for randomize character
string NAME[] = {"Andrew", "Theo", "Hailey", "Vera"};
string GENDER[] = {"female", "male"};
string RACE[] = {"human", "not human"};
string OCCUPATION[] = {"fighter", "wizard", "cleric"};
string TASKAB[] = {"Cooking", "Cleaning", "Dying"};
string HAIR[] = {"short black", "long white", "short gold"};
string EYECOLOR[] = {"black", "blue", "brown", "green"};

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
    
    randomSelector = rand() % sizeof(hairA)/sizeof(hairA[0]);
    setHair(HAIR[randomSelector]);
    
    randomSelector = rand() % sizeof(eyeColorA)/sizeof(eyeColorA[0]);
    setEyeColor(EYECOLOR[randomSelector]);
    
}


void Character :: setName(string);
void Character :: setGender(string);
void Character :: setRace(string);
void Character :: setOccupation(string);
void Character :: setTaSkAb(string);
void Character :: setHeight(int);
void Character :: setWeight(int);
void Character :: setHair (string);
void Character :: setEyeColor(string);

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
    return TASKAB;
}
int Character :: getHeight() {
    return Height;
}
int Character :: getWeight() {
    return weight;
}
string Character :: getHair() {
    return Hair;
}
string Character :: getEyeColor() {
    return EyeColor;
}
