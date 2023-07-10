#include <iostream>
#include <conio.h> // for getch()

// Size of the game board
const int WIDTH = 20;
const int HEIGHT = 10;

// Game objects
const char EMPTY = ' ';
const char WALL = '#';
const char FOOD = 'o';
const char PACMAN = 'X';

// Initial position of Pac-Man
int pacmanX = WIDTH / 2;
int pacmanY = HEIGHT / 2;

// Game board
char board[HEIGHT][WIDTH] = {
    "###################",
    "#                 #",
    "# o o o o o o o o #",
    "#                 #",
    "# o o o o o o o o #",
    "#                 #",
    "# o o o o o o o o #",
    "#                 #",
    "# o o o o o o o o #",
    "###################"
};

// Function to draw the game board
void drawBoard()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

// Function to handle keyboard input and update Pac-Man's position
void handleInput()
{
    char input = _getch();
    switch (input)
    {
    case 'w':
    case 'W':
    case '8':
        if (pacmanY > 0 && board[pacmanY - 1][pacmanX] != WALL)
        {
            board[pacmanY][pacmanX] = EMPTY;
            --pacmanY;
        }
        break;
    case 's':
    case 'S':
    case '2':
        if (pacmanY < HEIGHT - 1 && board[pacmanY + 1][pacmanX] != WALL)
        {
            board[pacmanY][pacmanX] = EMPTY;
            ++pacmanY;
        }
        break;
    case 'a':
    case 'A':
    case '4':
        if (pacmanX > 0 && board[pacmanY][pacmanX - 1] != WALL)
        {
            board[pacmanY][pacmanX] = EMPTY;
            --pacmanX;
        }
        break;
    case 'd':
    case 'D':
    case '6':
        if (pacmanX < WIDTH - 1 && board[pacmanY][pacmanX + 1] != WALL)
        {
            board[pacmanY][pacmanX] = EMPTY;
            ++pacmanX;
        }
        break;
    case 'q':
    case 'Q':
    case 27: // ASCII code for ESC key
        exit(0);
        break;
    }
}

// Function to update the game state
void updateGame()
{
    // Check if Pac-Man ate food
    if (board[pacmanY][pacmanX] == FOOD)
    {
        // Remove food from the board
        board[pacmanY][pacmanX] = EMPTY;
    }
}

int main()
{
    while (true)
    {
        // Clear the console
        system("cls");

        // Draw the game board
        drawBoard();

        // Handle keyboard input
        handleInput();

        // Update the game state
        updateGame();
    }

    return 0;
}
