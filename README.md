# Car Racing Game with User Management
This project is a simple console-based car racing game implemented in C++ with user registration, login functionality, and high score management. The game allows users to select different cars with varying speeds and avoid collisions with randomly moving obstacles.

Features
User Registration and Login: Users can register with a unique username and password. Existing users can login to access their high scores and play the game.

High Score Tracking: Each user has a high score stored in users.txt, which is updated if a new high score is achieved during gameplay.

Gameplay: Players control a car using 'A' and 'D' keys to move left and right, respectively. They must avoid collisions with moving obstacles to score points.

Multiple Car Options: Players can choose from three cars with different speeds, adding variety to the gameplay experience.

File System Usage: User data (username, password, high score) is stored and loaded from users.txt. This file acts as a persistent database for user information across sessions.

Classes and Components
UserManager: Manages user registration, login, and high score updates using file I/O operations.

Car Classes: Three car classes (car1, car2, car3) with different designs and speeds inherited from a base car class.

Game Class: Handles the game mechanics including obstacle generation, collision detection, score updates, and interface rendering.

Control Class: Manages user input using _kbhit() and _getch() for responsive gameplay.

Installation and Execution
Clone Repository: Clone this repository to your local machine using git clone (https://github.com/GCell-droid/2D-Car-Racing-Game).

Build the Project: Compile the source files using a C++ compiler that supports C++11 standards. For example, g++ main.cpp -o game.exe on Windows or g++ main.cpp -o game on Unix-like systems.

Run the Game: Execute the compiled binary (game.exe or game) to launch the game. Follow the on-screen instructions to register, login, and play.

## How to Play
Navigation: Use 'A' key to move left and 'D' key to move right.

Objective: Avoid collisions with oncoming obstacles (represented by **) to score points.

Scoring: Each successful evasion increments the score displayed on-screen.

Contributors:
Nitesh Parihar: C++ Developer(Created Car menu, classes, difficulty level mechanics)
