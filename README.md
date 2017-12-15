# pic10c_project
For final project


I WILL FINISH EVRYTHING BY FRADAY 5PM! IT'S STILL AN ONGOING PROJECT. 

After walting many Qt game tutorials and former c++ projects on Youtube, I decided to create a game, where players need to collect treasures without being caught by soldiers.



Game Design
When we run the codes, we would see many rectangular shapes:
1. a square in the middle
    - player
    - It responds to direction keys, and can never move out of the console
    - It's initially set at the center of the gameboard
    - when it collides with a treasure, it collects it and the count increments  (this part not finished)
    - when it collides with a soldier, no matter which type, it's sent back to its initial position
    - when all treasures are collected, something happens? (this part not finished)

2. a 25*15 rectangle
    - soldier1
    - there are 3 soldier1
    - It's set at a random position
    - soldier2 keeps moving upwards after being generated and returns from the bottom of the scene after it leaves from the top of the scene

3. a 10*10 rectangle
    - treasure
    - there are 5 treasures
    - their positions are also set randomly
    - to finish the game, the user has to collect all treasures
    
    
Codes involved
1. game.h & game.cpp
    - while the .h file contain the declarations and the .cpp files contain all definitions, these two docments provide the all the classes we have including
        * player
        * soldier1
        * soldier2
        * treasure
        * treasure collected (showing the count of treasures counted)
        * Army1 (managing the group of soldier1s we have)
2. gameboard.h & gameboard.cpp
    - this is the place where main chunk of codes, the application of all the classes are written
3. main.cpp
    - it simply calls a construction of a gameboard
4. the .pro files
    - for compilation

Knowledge relevent from pic10c class
1. RAII/memory //not yet adjusted
    - try catch is used in constructor
    - delete called in member function which is problematic
    - destructors undone --> not sure what to do
 2. generic algorithm used with lambda function
    - tried in main
3. templates
    - trying to do a template class
4. functors & function pointers
    - It haven't been employed. There is no need of comparison.
5. polymorohism
    - It's not really involved
    - the player, soldier1, soldier2 and treasure classes are all developed from the QGraphicRecItem class, but evrything about polymorphism and inheritance is much done in the base class, not in the advanced ones.
    - we used class functions from QGraphicRecItem class, but that's it.
    - the soldier1 and soldier2 classes do look similar, but there is rather no need of having soldier2 inherited from soldier1 class. Soldier1 class has no private variables nor even other functions - there is probably nothing to inherit.



12/14 Things left:
1. adjust for foreach and lambda
2. try using template
3. show treasure collected
4. add a proper ending to this game
5. see how memory management works for Qt game design







