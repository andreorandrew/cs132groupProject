/*
    Main File
    Homework 15 Group Project 
    Submission 5/10/2017
    Team members: 
        Theo Siswadi
        Jia Na (Vera)
        Anh Tran (Andrew)
*/

//header files
#include <iostream>
#include <string>
#include "Character.h"
#include "HeroCharacter.h"

using namespace std;

//main func. MAIN

const int SIZE = 5;
int displayMainMenu(int, int);
int displayCharHeroSelection();

int main()
{
    
    //define variables
    int choice;
    Character characters[SIZE];         //create a character array
    HeroCharacter hCharacters[SIZE];    // create a hero characters array
    int remainingChar = SIZE;
    int remainingHChar = SIZE;
    
    do //do while loop for menu
    {
        choice = displayMainMenu(remainingChar, remainingHChar);     //call a function to prompt user input
        
        //user has 4 choices
        if (choice == 0)                //quits program
        {
            cout << "OK, bye..." << endl;
            break;
        }
        else if (choice == 1)           // customize character
        {
            if (displayCharHeroSelection() == 1)
            {
                Character newChar;
                string input;
                int choice;
                
                cout << "Input Name: ";
                cin >> input;
                newChar.setName(input);
                
                cout << "Input Occupation: ";
                cin >> input;
                newChar.setOccupation(input);
                
                try
                {
                    cout << "Input Height: ";
                    cin >> choice;
                    newChar.setHeight(choice);
                    
                    cout << "Input Weight: ";
                    cin >> choice;
                    newChar.setWeight(choice);
                }
                catch (Character::InvalidHeight h)
                {
                    cout << "Height " << h.getBadHeight() << " cannot be negative." << endl;                }
                
                remainingChar--;
            }
            else
            {
                
            }
            
            cout << "Coming soon..." << endl;
        }
        else if (choice == 2)           // randomize character
        {
            if (displayCharHeroSelection() == 1)
            {
                Character newChar;

                characters[SIZE - remainingChar] = newChar; //assign a random character to the next element

                remainingChar--;
            }
            else
            {
                HeroCharacter newHero;
                
                hCharacters[SIZE - remainingHChar] = newHero;
                
                remainingHChar--;
            }
            //display feedback
            cout << "Done! Finish randomization :)" << endl; 
        }
        else if (choice == 3)           //display characters
        {
            if (remainingChar == SIZE && remainingHChar == SIZE)
            {
                cout << "No Characters Created." << endl;
            }
            else
            {
                if (displayCharHeroSelection() == 1)
                {
                    for (int i = 0; i < SIZE - remainingChar; i++)              //loop to display all characters
                    {
                        characters[i].displayInfo();      //call function that displays a character
                    }
                }
                else
                {
                    for (int i = 0; i < SIZE - remainingHChar; i++)              //loop to display all characters
                    {
                        hCharacters[i].displayInfo();      //call function that displays a character
                    }
                }
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


/*------------------MENUS------------------*/
// display the main menu
int displayMainMenu(int num1, int num2)
{
    int choice = 0;
    
    //prompts user input
    cout << "----------------------------------------" << endl;
    
    cout << "Main Menu: " << endl
    << "-----Remaining Characters: " << num1 << "-----" << endl
    << "-------Remaining Heroes: " << num2 << "-------" << endl
    << "1. Create your own Character." << endl
    << "2. Randomize a Character." << endl
    << "3. Display Character." << endl
    << "0. Quit." << endl;
    
    cout << ">> ";
    cin >> choice;
    
    cout << "----------------------------------------" << endl;
    
    return choice;
}

int displayCharHeroSelection()
{
    int choice;
    
    cout << "1. Normal Character." << endl;
    cout << "2. Hero Character." << endl;
    
    cout << ">> ";
    cin >> choice;
    
    while (choice != 1 && choice != 2)
    {
        cout << "Invalid Input - Try Again." << endl;
        cout << ">> ";
        
        cin >> choice;        
    }
    
    return choice;
}