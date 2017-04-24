/*
    Header File
    Homework 13 Group Project 
    1st Submission 4/23/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Anh Tran (Andrew)
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

//class declaration
class Character
{
 //fields
private:
    string Name;
    string Gender;
    string Race;
    string Occupation;
    string TaSkAb;
    int Height;
    int Weight;
    string Hair;
    string EyeColor;
public:
    /*-----CONSTRUCTORS-----*/
    Character();//default constructor
    
    //destructor
    ~Character() 
    {
        cout << "In destructor now." << endl;
    }
    /*-----SETTERS-----*/
    void setName(string);
    void setGender(string);
    void setRace(string);
    void setOccupation(string);
    void setTaSkAb(string);
    void setHeight(int);
    void setWeight(int);
    void setHair (string);
    void setEyeColor(string);
    
    
    /*-----GETTERS-----*/
    string getName();
    string getGender();
    string getRace();
    string getOccupation();
    string getTaSkAb();
    int getHeight();
    int getWeight();
    string getHair();
    string getEyeColor();
    
    /*-----PRINTER-----*/
    void displayInfo();
    
};

#endif /* CHARACTER_H */

