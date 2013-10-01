#include <QtCore/QString>
#include <QtCore/QTextStream>

#include <cstdlib>
#include <ctime>

int roll(int dice);

int main() {
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    std::srand(std::time(0));

    bool quit = false, playing = true;
    int turn;
    int player_dice[] = {0, 0, 0, 0};
    int total[] = {0, 0};
    QString choice;

    cout << "=== Dice Game ===\n"
         << "Welcome to the roll 7-11 dice game! Here are the basic rules:\n"
         << "- You roll 2 d6 dice each turn\n"
         << "- You win if you roll the combined total of 7 or 11 on your first turn\n"
         << "- You lose if you roll the combined total of 2 on your first turn\n"
         << "- After the first turn, you will have to roll the same amount you\n"
         << "  rolled the first time to win\n"
         << "- After the first turn, you will lose if you roll the combined total\n"
         << "  of 7 or 11\n\n"
         << "That's it! Pretty simple huh?\n";

    cout << "Please enter an option: (P)lay or (Q)uit> " << flush;
    choice = cin.readLine();
    if (choice[0].toLower() == 'q')
        quit = true;

    while (!quit) {
        turn = 1;
        player_dice[0] = roll(6);
        player_dice[1] = roll(6);
        total[0] = player_dice[0] + player_dice[1];
        cout << "\n\nYour first roll: " << player_dice[0] << " + " << player_dice[1]
             << " = " << total[0] << endl;

        if (total[0] == 7 || total[0] == 11) {
            cout << "You won on the first roll! Lucky bastard!\n";
            playing = false;
        }
        else if (total[0] == 2) {
            cout << "Too bad! You lose on the first roll!\n";
            playing = false;
        }
        else {
            cout << "Press <enter> to roll again." << flush;
            cin.readLine();
            playing = true;
        }

        while (playing) {
            ++turn;
            player_dice[2] = roll(6);
            player_dice[3] = roll(6);
            total[1] = player_dice[2] + player_dice[3];
            cout << "New roll: " << player_dice[2] << " + " << player_dice[3] << " = " << total[1]
                 << endl;

            if (total[1] == total[0]) {
                cout << "You win! It only took you " << turn << " turns!\n";
                playing = false;
            }
            else if (total[1] == 7 || total[1] == 11) {
                cout << "You lose! You only survived " << turn << " turns.\n";
                playing = false;
            }
            else {
                cout << "You still haven't rolled " << total[0] << "!\n"
                     << "Press <enter> to roll again." << flush;
                cin.readLine();
            }
        }

        cout << "Please enter an option: (R)eplay or (Q)uit> " << flush;
        choice = cin.readLine();
        if (choice[0].toLower() == 'q')
            quit = true;
    }
}

int roll(int dice) {
    return std::rand() % dice + 1;
}
