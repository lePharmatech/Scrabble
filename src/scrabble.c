#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// score de chaque mots
int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// fonction qui assurera l'attribution des points et calculera le score
int calculeScore(string nom);
int main(void)
{
    // obtenir les entrées de l'utilisateur
    string nom_1 = get_string("player 1: ");
    string nom_2 = get_string("player 2: ");

    // score des deux joueurs
    int score_1 = calculeScore(nom_1);
    int score_2 = calculeScore(nom_2);

    // affiche du resultat du match
    if (score_1 > score_2)
    {
        printf("player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// la logique de la fonction calculeScore
int calculeScore(string nom)
{
    int score = 0;
    for (int i = 0, n = strlen(nom); i < n; i++)
    {
        if (isupper(nom[i]))
        {
            score += points[nom[i] - 'A'];
        }
        if (islower(nom[i]))
        {
            score += points[nom[i] - 'a'];
        }
    }
    return score;
}
