#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70

using namespace std;

class User
{
public:
    string username;
    string password;
    int highScore;

    User(const string &uname, const string &pwd) : username(uname), password(pwd), highScore(0) {}

    void updateHighScore(int score)
    {
        if (score > highScore)
        {
            highScore = score;
            string n = username;
            cout << "     \t\tuser: " << n << endl;
            string m;
            fstream file("users.txt", ios::in | ios::out);
            while (file >> m)
            {
                if (m == n)
                {
                    break;
                }
            }
            file.seekp(file.tellg());
            file << " " << password << " " << highScore;
            file.close();
        }
    }
};

class UserManager
{
private:
    vector<User> users;
    string userFile = "users.txt"; // File to store user data

public:
    UserManager()
    {
        loadUsers();
    }

    void loadUsers()
    {
        ifstream file(userFile);
        if (file.is_open())
        {
            while (!file.eof())
            {
                string username, password;
                int highScore;
                file >> username >> password >> highScore;
                if (!username.empty() && !password.empty())
                {
                    users.push_back(User(username, password));
                    users.back().updateHighScore(highScore);
                }
            }
            file.close();
        }
    }

    void saveUsers()
    {
        ofstream file(userFile);
        if (file.is_open())
        {
            for (const auto &user : users)
            {
                file << user.username << " " << user.password << " " << user.highScore << endl;
            }
            file.close();
        }
    }

    bool isUsernameTaken(const string &username)
    {
        for (const auto &user : users)
        {
            if (user.username == username)
            {
                return true;
            }
        }
        return false;
    }

    bool registerUser(const string &username, const string &password)
    {
        if (!isUsernameTaken(username))
        {
            users.push_back(User(username, password));
            saveUsers();
            return true;
        }
        return false;
    }

    bool loginUser(const string &username, const string &password, User &currentUser)
    {
        for (auto &user : users)
        {
            if (user.username == username && user.password == password)
            {
                currentUser = user;
                return true;
            }
        }
        return false;
    }
};
class car
{
public:
    char carMatrix[4][4];
    int speed;

    void gotoxy(HANDLE console, int x, int y)
    {
        COORD cursorPosition;
        cursorPosition.X = x;
        cursorPosition.Y = y;
        SetConsoleCursorPosition(console, cursorPosition);
    }

    void draw(HANDLE console, int carPos)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(console, j + carPos, i + 22);
                cout << carMatrix[i][j];
            }
        }
    }
    void erase(HANDLE console, int carPos)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                gotoxy(console, j + carPos, i + 22);
                cout << " ";
            }
        }
    }
};
class car1 : public car
{
public:
    car1()
    {
        speed = 50;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                carMatrix[i][j] = (i % 2 == 0 && j % 2 == 1) ? '±' : ' ';
            }
        }
    }
};
class car2 : public car
{
public:
    car2()
    {
        speed = 30;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                carMatrix[i][j] = (i % 2 == 0 && j % 2 == 1) ? 'O' : ' ';
            }
        }
    }
};
class car3 : public car
{
public:
    car3()
    {
        speed = 20;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                carMatrix[i][j] = (i % 2 == 0 && j % 2 == 1) ? 'C' : ' ';
            }
        }
    }
};

class Control
{
public:
    static char getInput()
    {
        if (_kbhit())
        {
            return _getch();
        }
        return '\0';
    }
};

class Track
{
public:
    void gotoxy(HANDLE console, int x, int y)
    {
        COORD cursorPosition;
        cursorPosition.X = x;
        cursorPosition.Y = y;
        SetConsoleCursorPosition(console, cursorPosition);
    }

    static void drawBorder(HANDLE console)
    {
        Track track;
        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            for (int j = 0; j < 14; j++)
            {
                track.gotoxy(console, 0 + j, i);
                cout << "±";
                track.gotoxy(console, WIN_WIDTH - j, i);
                cout << "±";
            }
        }

        for (int i = 0; i < SCREEN_HEIGHT; i++)
        {
            track.gotoxy(console, SCREEN_WIDTH, i);
            cout << "±";
        }
    }
};

class MainMenu
{
public:
    static char displayMenu()
    {
        system("cls");
        cout << endl;
        cout << "\t\t--------------------------" << endl;
        cout << "\t\t-------- Main Menu -------" << endl;
        cout << "\t\t--------------------------" << endl
             << endl;
        cout << "\t\t1. Start Game" << endl;
        cout << "\t\t2. Instructions" << endl;
        cout << "\t\t3. Register" << endl;
        cout << "\t\t4. Login" << endl;
        cout << "\t\t5. Quit" << endl;
        cout << "\t\tSelect option: ";
        return _getche();
    }
};
class carselect
{
public:
    static car *displayCarMenu()
    {
        system("cls");
        cout << endl;
        cout << "\t\t--------------------------" << endl;
        cout << "\t\t-------- Select Car -------" << endl;
        cout << "\t\t--------------------------" << endl
             << endl;
        cout << "\t\t1. Car 1 : Easy" << endl;
        cout << "\t\t2. Car 2 : Normal" << endl;
        cout << "\t\t3. Car 3 : Hard" << endl;

        int carchoice;
        cout << "\t\tSelect car: ";
        cin >> carchoice;

        switch (carchoice)
        {
        case 1:
            return new car1;
        case 2:
            return new car2;
        case 3:
            return new car3;
        default:
            return new car1;
        }
    }
};

class Game
{
private:
    car *selectedcar = carselect::displayCarMenu();

    int carPos;
    int score;
    int enemyY[3];
    int enemyX[3];
    int enemyFlag[3];

public:
    Game() : carPos(WIN_WIDTH / 2), score(0) {}

    void initialize()
    {
        srand((unsigned)time(NULL));
        for (int i = 0; i < 3; i++)
        {
            enemyFlag[i] = false;
        }
    }

    void gotoxy(HANDLE console, int x, int y)
    {
        COORD cursorPosition;
        cursorPosition.X = x;
        cursorPosition.Y = y;
        SetConsoleCursorPosition(console, cursorPosition);
    }

    void genEnemy(int ind)
    {
        enemyX[ind] = 17 + rand() % (33);
        enemyY[ind] = 1;
    }

    void drawEnemy(HANDLE console, int ind)
    {
        if (enemyFlag[ind])
        {
            gotoxy(console, enemyX[ind], enemyY[ind]);
            cout << "**";
            gotoxy(console, enemyX[ind], enemyY[ind] + 1);
            cout << " ** ";
            gotoxy(console, enemyX[ind], enemyY[ind] + 2);
            cout << "**";
            gotoxy(console, enemyX[ind], enemyY[ind] + 3);
            cout << " ** ";
        }
    }

    void eraseEnemy(HANDLE console, int ind)
    {
        if (enemyFlag[ind])
        {
            gotoxy(console, enemyX[ind], enemyY[ind]);
            cout << "    ";
            gotoxy(console, enemyX[ind], enemyY[ind] + 1);
            cout << "    ";
            gotoxy(console, enemyX[ind], enemyY[ind] + 2);
            cout << "    ";
            gotoxy(console, enemyX[ind], enemyY[ind] + 3);
            cout << "    ";
        }
    }

    void resetEnemy(int ind)
    {
        eraseEnemy(GetStdHandle(STD_OUTPUT_HANDLE), ind);
        genEnemy(ind);
    }

    int collision()
    {
        for (int i = 0; i < 3; i++)
        {
            if (enemyY[i] <= 22 && enemyY[i] + 4 >= 22)
            {
                if (enemyX[i] <= carPos + 3 && enemyX[i] + 4 >= carPos)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    void gameover(User &currentUser)
    {
        system("cls");
        cout << endl;
        cout << "\t\t--------------------------" << endl;
        cout << "\t\t-------- Game Over -------" << endl;
        cout << "\t\t--------------------------" << endl
             << endl;
        cout << "\t\tYour Score: " << score << endl;
        cout << "\t\tYour High Score: " << currentUser.highScore << endl; // Display high score
        if (score > currentUser.highScore)
        {
            currentUser.updateHighScore(score);
            cout << "\t\tNew High Score! Updated in users.txt." << endl;
        }
        cout << "\t\tPress any key to go back to the menu.";
        _getch();
    }

    void updateScore(HANDLE console)
    {
        gotoxy(console, WIN_WIDTH + 7, 5);
        cout << "Score: " << score << endl;
    }

    void play(User &currentUser)
    {
        initialize();

        // Create a new console window
        HWND console = GetConsoleWindow();
        RECT ConsoleRect;
        GetWindowRect(console, &ConsoleRect);
        MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        Track::drawBorder(hConsole);
        updateScore(hConsole);

        for (int i = 0; i < 2; i++)
        {
            genEnemy(i);
            enemyFlag[i] = true;
        }

        gotoxy(hConsole, WIN_WIDTH + 7, 2);
        cout << "Car Game";
        gotoxy(hConsole, WIN_WIDTH + 6, 4);
        cout << "----------";
        gotoxy(hConsole, WIN_WIDTH + 6, 6);
        cout << "----------";
        gotoxy(hConsole, WIN_WIDTH + 7, 12);
        cout << "Control ";
        gotoxy(hConsole, WIN_WIDTH + 7, 13);
        cout << "-------- ";
        gotoxy(hConsole, WIN_WIDTH + 2, 14);
        cout << " A Key - Left";
        gotoxy(hConsole, WIN_WIDTH + 2, 15);
        cout << " D Key - Right";

        gotoxy(hConsole, 18, 5);
        cout << "Press any key to start";
        _getch();
        gotoxy(hConsole, 18, 5);
        cout << "                      ";

        while (1)
        {
            char ch = Control::getInput();

            if (ch == 'a' || ch == 'A')
            {
                if (carPos > 18)
                    carPos -= 4;
            }
            if (ch == 'd' || ch == 'D')
            {
                if (carPos < 50)
                    carPos += 4;
            }
            if (ch == 27)
            {
                break;
            }

            selectedcar->draw(hConsole, carPos);

            for (int i = 0; i < 2; i++)
            {
                drawEnemy(hConsole, i);
            }

            if (collision() == 1)
            {
                gameover(currentUser);
                return;
            }
            Sleep(selectedcar->speed);
            selectedcar->erase(hConsole, carPos);

            for (int i = 0; i < 2; i++)
            {
                eraseEnemy(hConsole, i);
            }

            for (int i = 0; i < 2; i++)
            {
                if (enemyFlag[i])
                {
                    enemyY[i] += 1;
                    if (enemyY[i] > SCREEN_HEIGHT - 4)
                    {
                        resetEnemy(i);
                        score++;
                        updateScore(hConsole);
                    }
                }
            }
        }
    }
};

int main()
{
    UserManager userManager;
    MainMenu mainMenu;
    char choice;

    User currentUser("", "");

    do
    {
        choice = mainMenu.displayMenu();

        switch (choice)
        {
        case '1':
        {
            if (currentUser.username.empty())
            {
                cout << "\n\tPlease login or register to play the game." << endl;
                _getch();
            }
            else
            {
                Game game;
                game.play(currentUser);
            }
            break;
        }
        case '2':
        {
            system("cls");
            cout << "Instructions";
            cout << "\n----------------";
            cout << "\n Avoid Cars by moving left or right. ";
            cout << "\n\n Press 'a' to move left";
            cout << "\n Press 'd' to move right";
            cout << "\n Press 'escape' to exit";
            cout << "\n\nPress any key to go back to the menu";
            _getch();
            break;
        }
        case '3':
        {
            system("cls");
            cout << "Register" << endl;
            cout << "----------------" << endl;
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (userManager.registerUser(username, password))
            {
                cout << "Registration successful!" << endl;
                _getch(); // waiting for some chrachter to exit system layer here
            }
            else
            {
                cout << "Username is already taken. Please choose a different username." << endl;
                _getch();
            }
            break;
        }
        case '4':
        {
            system("cls"); // making new display layer as if we press 4 for login then it will take us on anoter screen
            cout << "Login" << endl;
            cout << "----------------" << endl;
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            if (userManager.loginUser(username, password, currentUser))
            {
                cout << "Login successful!" << endl;
                cout << "Welcome, " << currentUser.username << "!" << endl;
                _getch();
            }
            else
            {
                cout << "Invalid username or password. Please try again." << endl;
                _getch();
            }
            break;
        }
        case '5':
        {
            exit(0);
        }
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (1);
    return 0;
}