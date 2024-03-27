// DISCLAIMER: I DO NOT SUPPORT PEOPLE PLAGIARIZING MY CODE. I DO NOT TAKE RESPONSIBILITY FOR THE UNLAWFUL ACTIONS OF OTHERS.

/**
 * @date 11/2/2023
 */

#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>
#include "linkedlist.h"

char get_choice(char *str);
void flush();
char is_num(char *stringArray);
int get_int(char *str);

int main()
{
    do
    {
        char choice;
    // checks for initial input, loops back if invalid input
    main:
        while (1)
        {
            choice = get_choice("------------\nEnter a character. Only the first character will be conisdered.\nR: Read\nW: Write\nQ: Quit\n------------\n");
            switch (choice)
            {
            case 'R':
            case 'r':
                printf("------------\nChoice: Read\n");
                goto read_handler;
            case 'W':
            case 'w':
                printf("------------\nChoice: Write\n");
                goto write_handler;
            case 'Q':
            case 'q':
                printf("------------\nChoice: Quit :(\n");
                goto end_prog;
            default:
                printf("------------\nInvalid character entered.\n");
            }
        }
    // traverse, view node
    read_handler:
        while (1)
        {
            choice = get_choice("------------\nEnter a character. Only the first character will be conisdered.\nT: Traverse Linked List\nV: View Node\nB: Back\nQ: Quit\n------------\n");
            switch (choice)
            {
            case 'T':
            case 't':
                printf("------------\nChoice: Traverse Linked List\n");
                traverse(head);
                goto main;
            case 'V':
            case 'v':
                printf("------------\nChoice: View Node\n");
                view(head, get_int("------------\nEnter pos (starting at 0).\n------------\n"));
                goto main;
            case 'B':
            case 'b':
                printf("------------\nChoice: Back\n");
                goto main;
            case 'Q':
            case 'q':
                printf("------------\nChoice: Quit :(\n");
                goto end_prog;
            default:
                printf("------------\nInvalid character entered.\n");
            }
        }
    // append, add at, remove at, remove val
    write_handler:
        while (1)
        {
            choice = get_choice("------------\nEnter a character. Only the first character will be conisdered.\nA: Append to Linked List\nI: "
                                "Insert Node at Pos\nR: Remove Node at Pos\nD: Delete Node by Value\nB: Back\nQ: Quit\n------------\n");
            switch (choice)
            {
            case 'A':
            case 'a':
                printf("------------\nChoice: Append to Linked List\n");
                append(&head, get_int("------------\nEnter value to append.\n------------\n"));
                goto main;
            case 'I':
            case 'i':
                printf("------------\nChoice: Insert Node at Pos\n");
                add(&head, get_int("------------\nEnter value to add.\n------------\n"), get_int("------------\nEnter pos (starting at 0).\n------------\n"));
                goto main;
            case 'R':
            case 'r':
                printf("------------\nChoice: Remove Node at Pos\n");
                delete (&head, get_int("------------\nEnter pos (starting at 0).\n------------\n"));
                goto main;
            case 'D':
            case 'd':
                printf("------------\nChoice: Delete Node by Value\n");
                delete_value(&head, get_int("------------\nEnter value to remove.\n------------\n"));
                goto main;
            case 'B':
            case 'b':
                printf("------------\nChoice: Back\n");
                goto main;
            case 'Q':
            case 'q':
                printf("------------\nChoice: Quit :(\n");
                goto end_prog;
            default:
                printf("Invalid character entered.\n");
            }
        }
    } while (1); // end main loop
end_prog:
    printf("------------\n");
    return 0;
}

char get_choice(char *str)
{

    char c = ' ';
    printf("%s", str);
    scanf("%c", &c);
    flush(); // flushes stdin buffer
    return c;
}

void flush()
{
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
}

char is_num(char *stringArray)
{
    for (int i = 0; stringArray[i] != '\0'; i++)
    {
        if (isdigit(stringArray[i]) == 0)
            return 0;
    }

    return 1;
}

int get_int(char *str)
{
    char valid_int = 0;
    char choice_str[100]; // I'm not creating a dynamic, allocatable string for this
    do
    {
        printf("%s", str);
        scanf("%99s", &choice_str);
        flush(); // flushes stdin buffer

        if (is_num(choice_str))
        {
            valid_int = 1;
        }
        else
        {
            printf("------------\nInput is not a integer.\n");
        }
    } while (!valid_int);
    return atoi(choice_str);
}
