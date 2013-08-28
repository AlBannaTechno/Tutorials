/*
 * Around the World board game exercise
 * Author: Nick Donais
 * Email: slxecas@gmail.com
 * Date: August 27, 2013
 */
#include <QString>
#include <QTextStream>

#include <cstdlib>
#include <ctime>

/* qt variables */
QTextStream cout(stdout);
QTextStream cin(stdin);

/* board struct */
struct game_board {
    int board_size;
    int board_goal;
    int board_pit;

    int pos_player;
    int pos_comp;
};

/* game settings struct */
struct game_settings {
    int dice_type;
    int dice_num;
    bool automatic;
};

/* function prototypes */
void display_menu(int wins, int losses, QString &input);
void display_options(game_board &board, game_settings &options);
int getOptionsInput();
void player_turn(game_board &board, game_settings options);
void computer_turn(game_board &board, game_settings options);
int roll_dice(int dice);
bool check_end_conditions(game_board board, int &wins, int &losses);

int main() {
    std::srand(std::time(0));

    /* game variables */
    game_board board = {12, 0, 0, 0, 0};
    game_settings options = {6, 2, false};
    int wins = 0, losses = 0;
    QString input;

    /* display game title and rules */
    cout << "=== Around the World Board Game ===\n\n"
         << "Welcome to the C++/Qt cli board game! The objective is to find the treasure\n"
         << "before you fall in the pit! But don't forget the computer will be trying to\n"
         << "find it at the same time! For added fun, you can also specify not only the\n"
         << "size of the board, but also which dice and how many you roll.\n";

    /* game loop */
    while (true) {
        display_menu(wins, losses, input);
        if (input[0] == 'o') {
            display_options(board, options);
            continue;
        }
        else if (input[0] == 'q')
            break;

        /* set initial values */
        while (board.board_goal == board.board_pit) {
            board.board_goal = std::rand() % board.board_size + 2;
            board.board_pit = std::rand() % board.board_size + 2;
        }
        cout << endl;

        /* play loop */
        while (true) {
            player_turn(board, options);

            if (check_end_conditions(board, wins, losses))
                break;
            if (!options.automatic) {
                cout << "Press <enter> to continue." << flush;
                cin.readLine();
            }

            computer_turn(board, options);

            if (check_end_conditions(board, wins, losses))
                break;
            if (!options.automatic) {
                cout << "Press <enter> to continue." << flush;
                cin.readLine();
            }
        }

        board.board_goal = 0;
        board.board_pit = 0;
        board.pos_player = 0;
        board.pos_comp = 0;
    }

    return EXIT_SUCCESS;
}

void display_menu(int wins, int losses, QString &input) {
    while (true) {
        if (wins == 0 && losses == 0)
            cout << "\nMenu: (P)lay, (O)ptions, (Q)uit\n"
                 << "> " << flush;
        else
            cout << "\nCurrent stats - Wins: " << wins << "  Losses: " << losses << endl
                 << "Menu: (P)lay Again, (O)ptions, (Q)uit\n"
                 << "> " << flush;

        input = cin.readLine().toLower();

        if (input[0] == 'p' || input[0] == 'o' || input[0] == 'q')
            break;

        cout << "Error! Unknown selection entered.\n";
    }
}

void display_options(game_board &board, game_settings &options) {
    cout << "\n=== Game Options ===\n"
         << "How big should the board be? (Must be positive, current: " << board.board_size
         << ")\n";
    board.board_size = getOptionsInput();

    cout << "How many sides should the dice have? (Must be positive, current: " << options.dice_type
         << ")\n";
    options.dice_type = getOptionsInput();

    cout << "How many dice should be rolled? (Must be positive, current: " << options.dice_num
         << ")\n";
    options.dice_num = getOptionsInput();

    cout << "Turn on automatic play? (y/n, current: " << (options.automatic ? "y" : "n") << ")\n";
    QString input = (options.automatic ? "y" : "n");
    cout << "> " << flush;
    input = cin.readLine().toLower();
    if (input[0] == 'y')
        options.automatic = true;
    else if (input[0] == 'n')
        options.automatic = false;

    cout << "\nNew settings:\n"
         << "Game will be played with a board size of " << board.board_size << ",\n"
         << "rolling " << options.dice_num << "d" << options.dice_type
         << " and automatic play is " << (options.automatic ? "on" : "off") << endl;
}

int getOptionsInput() {
    int input = 0;

    while (input <= 0) {
        cout << "> " << flush;
        input = cin.readLine().toInt();
        if (input <= 0)
            cout << "Number must be positive!\n";
    }

    return input;
}

void player_turn(game_board &board, game_settings options) {
    int move = 0;
    int roll = 0;
    QString msg = "\nYou rolled: ";

    for (int i = 0; i < options.dice_num; ++i) {
        roll = roll_dice(options.dice_type);
        move += roll;
        msg += QString("%1 ").arg(roll);
    }

    for (int i = 0; i < move; ++i) {
        ++board.pos_player;
        if (board.pos_player == board.board_size)
            board.pos_player = 0;
    }

    msg += QString("\nYou move %1 space(s) to position %2").arg(move).arg(board.pos_player);
    cout << msg << endl;
}

void computer_turn(game_board &board, game_settings options) {
    int move = 0;
    int roll = 0;
    QString msg = "\nComputer rolled: ";

    for (int i = 0; i < options.dice_num; ++i) {
        roll = roll_dice(options.dice_type);
        move += roll;
        msg += QString("%1 ").arg(roll);
    }

    for (int i = 0; i < move; ++i) {
        ++board.pos_comp;
        if (board.pos_comp == board.board_size)
            board.pos_comp = 0;
    }

    msg += QString("\nComputer moves %1 space(s) to position %2").arg(move).arg(board.pos_comp);
    cout << msg << endl;
}

int roll_dice(int dice) {
    return std::rand() % dice + 1;
}

bool check_end_conditions(game_board board, int &wins, int &losses) {
    if (board.pos_player == board.board_goal) {
        cout << "You've found the hidden treasure! Congratulations! You win!\n";
        ++wins;
        return true;
    }
    else if (board.pos_player == board.board_pit) {
        cout << "You fell down the pit! You lose the game!\n";
        ++losses;
        return true;
    }
    else if (board.pos_comp == board.board_goal) {
        cout << "The computer found the hidden treasure! You lose the game!\n";
        ++losses;
        return true;
    }
    else if (board.pos_comp == board.board_pit) {
        cout << "The computer fell down the pit! Congratulations! You win!\n";
        ++wins;
        return true;
    }

    return false;
}
