/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: Andrew
 *
 * Created on April 23, 2017, 2:50 PM
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character 
{
private:
    string Name;
    string Gender;
    string Race;
    string TaSkAb;
    int Height;
    int Weight;
    string Hair;
    string EyeColor;
public:
    /*-----CONSTRUCTORS-----*/
    Character();
    
    /*-----SETTERS-----*/
    void setName(string);
    void setGender(string);
    void setRace(string);
    void setTaSkAb(string);
    void setHeight(int);
    void setWeight(int);
    void setHair (string);
    void setEyeColor(string);
    
    
    /*-----GETTERS-----*/
    string getName();
    string getGender();
    string getRace();
    string getTaSkAb();
    int getHeight();
    int getWeight();
    string getHair();
    string getEyecolor();
};

#endif /* CHARACTER_H */

