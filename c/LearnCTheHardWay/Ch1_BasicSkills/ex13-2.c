#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    char letter = 0;

    for (i = 1; i < argc; ++i) {
        for (j = 0; argv[i][j] != '\0'; ++j) {
            letter = argv[i][j];

            if (letter > 64 && letter < 91) {
                letter += 32;
            }

            switch (letter) {
                case 'a':
                    printf("%d: 'a'\n", j);
                    break;

                case 'e':
                    printf("%d: 'e'\n", j);
                    break;

                case 'i':
                    printf("%d: 'i'\n", j);
                    break;

                case 'o':
                    printf("%d: 'o'\n", j);
                    break;

                case 'u':
                    printf("%d: 'u'\n", j);
                    break;

                case 'y':
                    if (j > 2) {
                        // it's only sometimes y
                        printf("%d: 'y'\n", j);
                    }
                    else {
                        printf("%d: %c is not a vowel\n", j, letter);
                    }
                    break;

                default:
                    printf("%d: %c is not a vowel\n", j, letter);
            }
        }
        printf("\n");
    }

    return 0;
}
