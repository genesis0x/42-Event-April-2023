#include <stdio.h>
#include <string.h>

int get_card_value(char c) 
{
    switch(c) {
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return c - '0';
        case 'T':
        case 'J':
        case 'Q':
        case 'K':
            return 10;
        case 'A':
            return 11;
        default:
            return 0;
    }
}

int calculate_hand_value(char* hand) 
{
    int value = 0;
    int num_aces = 0;

    for (int i = 0; i < strlen(hand); i++) 
    {
        int card_value = get_card_value(hand[i]);
        value += card_value;
        if (card_value == 11)
            num_aces++;
    }

    while (value > 21 && num_aces > 0) 
    {
        value -= 10;
        num_aces--;
    }

    return (value);
}

int main(int ac, char** av) 
{
    if (ac != 2) 
    {
        printf("Usage: %s <hand>\n", av[0]);
        return (1);
    }
    int hand_value = calculate_hand_value(av[1]);
    if (hand_value == 21 && strlen(av[1]) == 2)
        printf("Blackjack!\n");
    else
        printf("%d\n", hand_value);
    return (0);
}
