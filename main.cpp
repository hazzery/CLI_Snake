#include "include/Game.h"
#include "src/Game.cpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <string>
using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::cout;
using std::endl;

std::fstream HighScoreFile;

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
            cout << endl
                << "Please select a difficulty" << endl
                << "Enter 'e' for easy, 'n' for normal, or 'h' for hard" << endl
                << "Alternatively, enter 's' to see high scores" << endl
                << "Then press enter to confirm" << endl;
            
            char difficultyInput;
            cin >> difficultyInput;
            
            std::string line;
            
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
                
                case 's':
                    HighScoreFile.open("HighScores.txt", std::ios::in);
                    while (getline (HighScoreFile, line))
                        cout << line << endl;
                    break;
                    
                default:
                    cout << "Please enter either 'e', 'n', or 'h'" << endl << endl;
                    break;
            }
            //Clear console
        }
        
        //Game Loop/////////////////////////////////////////////////////////////////////////////////////////////////
    
        cout << "Use 'w' to move the snake up" << endl
            << "'a' to move the snake left" << endl
            << "'s' to move the snake down" << endl
            << "and 'd' to move the sbake down" << endl;
        
        CLI_Snake<21, 11> game(difficulty);
        
        int score = game.Game();
        
        cout << "Please enter name for highscore list" << endl;
        std::string name;
        cin >> name;
        
        HighScoreFile.open("HighScores.txt", std::ios::out | std::ios::app);
        
        if (!HighScoreFile.is_open())
            cout << "failed to open " << endl;
        else
            HighScoreFile << name << ": " << score << endl;
        
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
