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
    void setName();
    
    /*-----GETTERS-----*/
};

#endif /* CHARACTER_H */

