# pic10c_project
For final project

After walting many Qt game tutorials and former c++ projects on Youtube, I decided to create a game, where players need to collect treasures without being caught by soldiers.



Game Design
When we run the codes, we would see many rectangular shapes:
1. a square in the middle
    - player
    - It responds to direction keys, and can never move out of the console
    - It's initially set at the center of the gameboard
    - when it collides with a treasure, it collects it and the count increments
    - when it collides with a soldier, no matter which type, it's sent back to its initial position
    - when all treasures are collected, something happens? (this part is not finished)

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
1. RAII/memory
    - try catch is used in constructor
    - destructors are not needed, as all pointers are created on stack, and the momory will be managed when "game" is deleted.
 2. generic algorithm used with lambda function
    - tried in main, but as QGraphicScene cannot be captured in lambda function, we can't really use this in our program.
3. templates
    - trying to do a template class
    - It's working!
    - It doen't save time for compiler as from wrting codes to produce three classes seperately, but it makes the codes shorter!
4. functors & function pointers
    - It hasn't been employed. There is no need of comparison.
5. polymorohism
    - It's not really involved
    - the player, soldier1, soldier2 and treasure classes are all developed from the QGraphicRecItem class, but evrything about polymorphism and inheritance is much done in the base class, not in the advanced ones.
    - we used class functions from QGraphicRecItem class, but that's it.
    - the soldier1 and soldier2 classes do look similar, but there is rather no need of having soldier2 inherited from soldier1 class. Soldier1 class has no private variables nor even other functions - there is probably nothing to inherit.


Codes that I tried but failed to work:
1. treasure_collected
    - Problem:I could return the number of treasure, but not to show the text to the scene when the number is updated......
2. timer
    - Problem: could set up a nice timer, but the timer needs to be working during the time the program is excecuted, which was the line "a.exec". However,  I can't make the timer start in main, get everything played, and then respond to it. If I put the timer before the line a.exec, it takes 10 seconds to start the game; if I put it after a.exec, the timer starts when I close the window.
    - Possible solutions
        1. add another layer of .h and .cpp files where timer controls the excecution of gameboard.cpp
        2. use some Qt functions instead. (I tried QTimer but failed to make it working)
        


        
    








