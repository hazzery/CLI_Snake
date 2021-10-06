#include "include/Game.h"
#include "src/Game.cpp"
#include <iostream>
#include <chrono>
#include <thread>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::cout;
using std::endl;

int main()
{
    cout << "       Hello!" << endl << "Welcome to CLI_Snake" << endl << endl << " Please press enter" << endl;
    cin.get();
    //Clear console
    
    while (true) {
        Difficulty difficulty = Null;
        
        //Difficulty Selection//////////////////////////////////////////////////////////////////////////////////////
        while (difficulty == Null)
        {
            cout << endl << "Please select a difficulty" << endl << "Enter 'e' for easy, 'n' for normal, or 'h' for hard" << endl << "Then press enter to confirm" << endl;
            
            char difficultyInput;
            cin >> difficultyInput;
            
            switch (difficultyInput)
            {
                case 'e':
                    difficulty = Easy;
                    break;
                
                case 'n':
                    difficulty = Normal;
                    break;
                    
                case 'h':
                    difficulty = Hard;
                    break;
                    
                default:
                    cout << "Please enter either 'e', 'n', or 'h'" << endl << endl;
                    break;
            }
            //Clear console
        }
        
        //Game Loop/////////////////////////////////////////////////////////////////////////////////////////////////
    
        CLI_Snake<21, 11> game(difficulty);
        
        int score = game.Game();
        
        cout << "Your score was: " << score << endl;
        
        cout << "Press enter to play again" << endl;
        cin.get();
        
        //Clear console

    }
}

/*
 (probably bad) Idea for multi threading
 
 the main thread focuses plays the whole game without any visual output.
 It never ever reads or writes to the board class.
 
 Drawing on the board is entirely handled by a sperate thread,
 which is constantly checking the Coords values from the main thread,
 updating the symbols onto the board accordingly.
 */
