#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>




int a,z,b;
char game_started(char SECRET_WORD[])
{
    printf("Game Started...\n\n");
    printf("Loading word list from file...\n    %d words loaded...\n\nI'm thinking a word that is %d letter long.\n\n\n\n\n\n\n\n\n", 55900, strlen(SECRET_WORD));


    return '1';
}







int ALPHABET (char letter)
{
    if (letter >= 'a' && letter <= 'z')
        return 1;
    else
        return 0;
}









int GUESSED_BEFORE(char letter, char LETTERS_GUESSED[])
{
    for (a = 0; a < strlen(LETTERS_GUESSED); a++)
    {
        if (letter == LETTERS_GUESSED[a])
            return 1;
    }
    return 0;
}







int EXIST_IN_SECRETWORD(char letter, char SECRET_WORD[])
{
    for(a = 0; a < strlen(SECRET_WORD); a++)
    {
        if (letter == SECRET_WORD[a])
        return 1;
    }
    return 0;
}







int IS_VOWEL(char letter)
{
    if (letter == 'a' ||letter == 'e' ||letter == 'i' ||letter == 'o' ||letter == 'u')
        return 1;
    else
        return 0;
}




void letters_available(char LETTERS_GUESSED[])
{
    char available_letters[] = "abcdefghijklmnopqrstuvwxyz";

    int count;
    for ( a = 0; a < 26; a++)
    {
        count = 1;
        for( b = 0; b < 20; b++)
        {
            if (available_letters[a] == LETTERS_GUESSED[b])
            {
                count = 0;
                break;
            }
        }
        if (count == 1)
            printf("%c  ", available_letters[a]);
    }

}




int main()
{

    int GAME_FINISHED = 0;

    char SECRET_WORD[] = "apple";
    game_started(SECRET_WORD);

    for( a = 0; a < strlen(SECRET_WORD); a++)
    {
        SECRET_WORD[a] = tolower(SECRET_WORD[a]);
    }


    char DISPLAY[strlen(SECRET_WORD)];
    for( a = 0; a < strlen(SECRET_WORD); a++)
    {
        DISPLAY[a] = '_';
    }


    int LIVES = 6, WARNINGS_LEFT = 3, SCORE = 0;
    char GUESSED_LETTERS[26] = "--------------------";
    int GUESSED_COUNT = 0;
    char letter;

    GAME_IS_ON :

    printf("Lives = %d                                  Warnings Left = %d                                  Score = %d\n\n\n\n\n\n", LIVES, WARNINGS_LEFT, SCORE);
    for( a = 0; a < strlen(SECRET_WORD); a++)
    {
        printf("%c ", DISPLAY[a]);
    }

    printf("\n\nAVAILABLE LETTERS :\n");
    letters_available(GUESSED_LETTERS);

    printf("\n\n\n\n\nGuess the letter...\n");

    fflush(stdin);
    scanf("%c", &letter);
    letter = tolower(letter);
    fflush(stdin);
    system("cls");

    if (!ALPHABET(letter))
    {
        if(WARNINGS_LEFT >= 1)
        {
            WARNINGS_LEFT--;
            printf("Warning! The character you entered is invalid!\nYou have %d warnings left...\n\n", WARNINGS_LEFT);
        }
        else
        {
            LIVES--;
            printf("Due to no warnings left, your lives is reduced...\n\nYou have %d lives left\n\n", LIVES);
        }
    }
    else
    {
        if (GUESSED_BEFORE(letter, GUESSED_LETTERS))
        {
            if(WARNINGS_LEFT >= 1)
            {
                WARNINGS_LEFT--;
                printf("Warning! The character you entered is invalid!\nYou have %d warnings left...\n\n", WARNINGS_LEFT);
            }
            else
            {
                LIVES--;
                printf("Due to no warnings left, your lives is reduced...\n\nYou have %d lives left\n\n", LIVES);
            }
        }
        else
        {
            GUESSED_LETTERS[GUESSED_COUNT] = letter;
            GUESSED_COUNT++;

            if (EXIST_IN_SECRETWORD(letter, SECRET_WORD))
            {
                printf("RIGHT GUESS...\n\n");
                for ( a = 0; a < strlen(SECRET_WORD); a++)
                {
                    if (letter == SECRET_WORD[a])
                        DISPLAY[a] = letter;
                }

                if(IS_VOWEL(letter))
                    SCORE += 30;
                else
                    SCORE += 20;
            }
            else
            {
                printf("WRONG GUESS...\n\n");

                if(IS_VOWEL(letter))
                {
                    LIVES -= 2;
                    SCORE += 10;
                }
                else
                {
                    LIVES --;
                    SCORE -= 5;
                }



            }
        }
    }
    if (SCORE < 0)
        SCORE = 0;

    if (LIVES <= 0)
    {
        system("cls");
        GAME_FINISHED = 1;
        printf("Game over...\nYou have no lives left...\n\nThe word was ");
        puts(SECRET_WORD);
        printf("\n\n");
        printf("You Scored %d.\n\n\n", SCORE);

    }


    if (strcmp(SECRET_WORD,DISPLAY) == 0)
    {
        system("cls");
        GAME_FINISHED = 1;
        printf("Congracts...\nYou revealed all the letters...\n\nThe word is ");
        puts(SECRET_WORD);
        printf("\n\n");
        printf("You Scored %d.\n\n\n", SCORE);
    }



    if (!GAME_FINISHED)
        goto GAME_IS_ON;

}
