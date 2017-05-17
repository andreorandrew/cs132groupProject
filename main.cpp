/*
    Main File
    Homework 16 Group Project 
    Submission 5/17/2017
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
    HeroCharacter<int> hCharacters[SIZE];    // create a hero characters array
    int remainingChar = SIZE;
    int remainingHChar = SIZE;
    
    do//do while loop for menu
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
                bool tryAgain = true;

                //user input for Character characteristics
                cout << "Input Name: ";
                cin >> input;
                newChar.setName(input);

                cout << "Input Gender: ";
                cin >> input;
                newChar.setGender(input);

                cout << "Input Race: ";
                cin >> input;
                newChar.setRace(input);

                cout << "Input Occupation: ";
                cin >> input;
                newChar.setOccupation(input);

                cout << "Input Talent, Skill, or Ability: ";
                cin >> input;
                newChar.setTaSkAb(input);

                newChar.setLevel(1);

                cout << "Input Hair Qualities: ";
                cin >> input;
                newChar.setHair(input);

                cout << "Input Eye Color: ";
                cin >> input;
                newChar.setEyeColor(input);

                cout << "Input Kingdom Conquered: ";
                cin >> input;
                newChar.setKingdomConquered(input);


                //user input with possibility of throwing an exception
                try
                {
                    cout << "Input Height: ";
                    cin >> choice;
                    newChar.setHeight(choice);

                    cout << "Input Weight: ";
                    cin >> choice;
                    newChar.setWeight(choice);

                    characters[SIZE - remainingChar] = newChar;
                    remainingChar--;
                }
                catch (Character::InvalidHeight h)
                {
                                cout << "Height " << h.getBadHeight() << " cannot be negative." << endl;
                }
                catch (Character::InvalidWeight w)
                {
                    cout << "Weight " << w.getBadWeight() << " cannot be negative." << endl;
                }
            }
            else
            {
                HeroCharacter<int> newHero;

                string input;
                int choice;

                //User input for Hero's characteristics
                cout << "Input Name: ";
                cin >> input;
                newHero.setName(input);

                cout << "Input Gender: ";
                cin >> input;
                newHero.setGender(input);

                cout << "Input Race: ";
                cin >> input;
                newHero.setRace(input);

                cout << "Input Occupation: ";
                cin >> input;
                newHero.setOccupation(input);

                cout << "Input Task or Ability: ";
                cin >> input;
                newHero.setTaSkAb(input);

                cout << "Input Level: ";
                cin >> choice;
                newHero.setLevel(choice);

                cout << "Input Hair: ";
                cin >> input;
                newHero.setHair(input);

                cout << "Input Eye Color: ";
                cin >> input;
                newHero.setEyeColor(input);

                cout << "Input Kingdom Conquered: ";
                cin >> input;
                newHero.setKingdomConquered(input);

                cout << "Input Hero's Weapon: ";
                cin >> input;
                newHero.setWeapon(input);

                cout << "Input Hero's Followers: ";
                cin >> choice;
                newHero.setFollowers(choice);

                //user input with possibility of throwing an exception
                try
                {
                    cout << "Input Height: ";
                    cin >> choice;
                    newHero.setHeight(choice);

                    cout << "Input Weight: ";
                    cin >> choice;
                    newHero.setWeight(choice);

                    hCharacters[SIZE - remainingHChar] = newHero;
                    remainingHChar--;
                }
                catch (Character::InvalidHeight h)
                {
                            cout << "Height " << h.getBadHeight() << " cannot be negative." << endl;
                }
                catch (Character::InvalidWeight w)
                {
                            cout << "Weight " << w.getBadWeight() << " cannot be negative." << endl;
                }
            }
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
                HeroCharacter<int> newHero;
                
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
