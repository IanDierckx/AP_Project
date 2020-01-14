#ifndef AP_PROJECT_SFML_GAME_H
#define AP_PROJECT_SFML_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Level.h"



using namespace std;


namespace GameSFML{

    /// The SFML version of the Game class.
    /**
     *  This class represents the game
    */
//    class Game : public GameLogic::Game
    class Game{
        private:
            shared_ptr<sf::RenderWindow> window;
            shared_ptr<Level> currentLevel;
        public:
            /// Constructor of the class
            /**
             * The constructor initializes the SFML window and initializes the first level of the game.
             * The Transformation singleton class gets the correct screen sizes (minus the borders of the screen)
             * @param title Gives the title of the window
             */
            explicit Game(const string& title = "Space Invaders");

            /// Initialize a new level in the game
            /**
             * Function initializes a new level by calling the Level Parser
             * @param levelFile the name of the json file of the new level
             */
            void initializeLevel(const string &levelFile); //override;

            /// Function to run the actual game
            /**
             * Starts by getting the instance of the stopwatch class, which if this is the first time starts the clock
             * Game runs in a while loop with the condition of if the game window is still open
             * Inside the loop it checks for events and draws the game accordingly.
             */
            void run(); // override;
    };
}

#endif //AP_PROJECT_SFML_GAME_H
