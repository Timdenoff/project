Project Description: "Snake Game"

1. General Information
The project is a classic "Snake" game written in C++. In this game, the player controls a snake that moves around a game field, collecting fruits and avoiding collisions with its own tail. The goal is to score as many points as possible by eating fruits and increasing the length of the snake.

2. Features
- Snake Control: The player controls the movement of the snake using the w (up), a (left), s (down), d (right) keys.
- Collecting Fruits: Each time the snake's head collides with a fruit, the player earns 10 points, and the snake's length increases.
- Game Field Update: The game displays the current state of the game field, including the position of the snake, the fruit, and the boundaries.
- Exit Game: The player can end the game at any time by pressing the x key.
- Infinite Game Field: The snake can pass through the edges of the screen and reappear on the opposite side, preventing boundary collisions.

 3. Main Components
- Variables and Constants:
  - gameOver: A boolean variable indicating the game's state (ongoing or finished).
  - width, height: Dimensions of the game field.
  - x, y: Current coordinates of the snake's head.
  - fruitX, fruitY: Coordinates of the fruit.
  - score: The player's current score.
  - tailX, tailY: Arrays storing the coordinates of the snake's tail segments.
  - nTail: Length of the snake's tail.
  - dir: The snake's direction of movement.

- Functions:
  - Setup(): Initializes the variables to start the game.
  - Draw(): Displays the game field in the console.
  - Input(): Handles keyboard input for controlling the snake.
  - Logic(): Updates the game state, including moving the snake, checking for collisions, and collecting fruits.

 4. Technical Details
- Programming Language: C++
- Execution Environment: Console interface
- Compilation and Execution: Using a C++ compiler (e.g., g++)

 5. Instructions for Running the Game
1. Compilation:
   - Open a terminal or command prompt.
   - Navigate to the directory containing the source code file (e.g., snake_game.cpp).
   - Run the compilation command:
     sh
     g++ -o snake_game snake_game.cpp
     
2. Execution:
   - Run the compiled file:
     sh
     ./snake_game
     

 6. Example Gameplay
- After launching the program, the game field will appear on the screen, bordered by  characters.
- The player controls the snake, aiming to collect fruits (represented by F) while avoiding collisions with its tail.
- Each eaten fruit increases the snake's length and adds 10 points to the total score.
- The game continues until the player ends it manually (by pressing x) or the snake collides with its tail.

This project provides a basic but fully functional implementation of the "Snake" game, which can be enhanced and expanded as desired.
