/*
    Homework 11-4 
    1st Submission 4/16/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Yuxin Wang (Hailey)
        Anh Tran (Andrew)
*/

//header files
#include <iostream>
#include <string>
#include "Character.h"
using namespace std;

//main func. MAIN
int main()
{
    int choice;
    Character characters[SIZE];         //create a character array
    
    do//do while loop for menu
    {
        choice = displayMainMenu();     //call a function to prompt user input
        
        //user has 4 choices
        if (choice == 0)                //quits program
        {
            cout << "OK, bye..." << endl;
            break;
        } 
        else if (choice == 1)           // customize character
        {
            cout << "Coming soon..." << endl; 
        }
        else if (choice == 2)           // randomize character
        {
            //randomize a character
            cout << "Creating random Characters..." << endl;
        }
        else if (choice == 3)           //display characters
        {
            for (int i = 0; i < SIZE; i++)              //loop to display all characters
            {
                displayCharacters (characters[i]);      //call function that displays a character
            }
        }
        else //input validation
        {
            cout << "Invalid Input." << endl; 
        }
        
    } while (choice != 0);
    
    cin.get();
    return 0;
}

// displays the entire character array
void displayCharacters (Character character)
{
    if (character.getName() == "" && character.getGender() == "")
    {
        cout << "Character Doesn't Exist." << endl << endl;
    }
    else
    {
        cout << "Name: " << character.getName() << endl
            << "Gender: " << character.getGender() << endl
            << "Race: " << character.getRace() << endl
            << "Occupation: " << character.getOccupation() << endl
            << "Talents, Ailities, or Skills: " << character.getTaSkAb() << endl
            << "Hair: " << character.getHair() << endl
            << "Eyes Color: " << character.getEyeColor() << endl
            << "Weigth: " << character.getWeight() << " kg" << endl
            << "Height: " << character.getHeight() << " cm" << endl << endl;
    }
}

// display the main menu
int displayMainMenu()
{
    int choice = 0;
    
    //prompts user input
    cout << "----------------------------------------" << endl;
    
    cout << "Main Menu: " << endl
        << "1. Create your own Character." << endl
        << "2. Randomize a Character." << endl
        << "3. Display Character." << endl
        << "0. Quit." << endl;
        
    cout << ">> ";
    cin >> choice;
    
    cout << "----------------------------------------" << endl;

    return choice;
}