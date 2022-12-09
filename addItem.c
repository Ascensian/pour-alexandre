/*
**  Filename : addItem.c
**
**  Made by : Hugo
**
**  Description : Main file to add a Item to the .itBob file
*/

#include "../all_include.h"

void addItem()
{
    Item Item;
    FILE *f = open_file(ITEM_FILE_NAME, "a+");
    check_file(f);

    addCount(f); // ajouter le nombre d'items
    printf("\n****Creation d'un item****\n");

    ask_Item_name(&Item, f);
    ask_Item_hpMax(&Item, f);
    ask_Item_shield(&Item, f);
    ask_Item_dmg(&Item, f);
    ask_Item_ps(&Item, f);
    ask_Item_ss(&Item, f);
    ask_Item_flight(&Item, f);
    
    
    printf("Votre item a bien ete cree");

    free(Item.name);
    free(Item.hpMax);
    free(Item.shield);
    free(Item.dmg);
    free(Item.ps);
    free(Item.ss);
    free(Item.flight);

    close_file(f);
}

void ask_Item_flight(Item *Item, FILE *ptr)
{
    int choice;
    Item->flight = malloc(MAX_SIZE * sizeof(Item->flight));
    do
    {
        printf("Vol ? (OUI = 1 / NON = 0): ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 1);

    switch (choice)
    {
    case False:
        break;
    case True:
        Item->flight = "true";
        fprintf(ptr, "flight=%s\n", Item->flight);
        break;
    default:
        break;
    }
}

void ask_Item_ss(Item *Item, FILE *ptr)
{
    int choice;
    Item->ss = malloc(MAX_SIZE * sizeof(Item->ss));
    do
    {
        printf("Tir spectral ? (OUI = 1 / NON = 0): ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 1);

    switch (choice)
    {
    case False:
        break;
    case True:
        Item->ss = "true";
        fprintf(ptr, "ss=%s\n", Item->ss);
        break;
    default:
        break;
    }
}

void ask_Item_ps(Item *Item, FILE *ptr)
{
    int choice;
    Item->ss = malloc(MAX_SIZE * sizeof(Item->ss));
    do
    {
        printf("Tir percant ? (OUI = 1 / NON = 0): ");
        scanf("%d", &choice);
    } while (choice < 0 || choice > 1);

    switch (choice)
    {
    case False:
        break;
    case True:
        Item->ps = "true";
        fprintf(ptr, "ps=%s\n", Item->ps);
        break;
    default:
        break;
    }
}

void ask_Item_dmg(Item *Item, FILE *ptr)
{
    int choice;
    Item->dmg = malloc(sizeof(Item->dmg));
    do
    {
        printf("Dommages ? (OUI = 1 / NON = 0): ");
        scanf("%d", &choice);

    } while (choice < 0 || choice > 1);

    if (choice == 1)
    {
        printf("Nouveau dommages : ");
        fflush(stdin);
        scanf("%d", &Item->dmg); // j'ai essayé toutes les solutions trouvées sur stackoverflow lf retourne toujours 0.0000 du coup j'ai mis en décimal
        fprintf(ptr, "dmg=%d\n", Item->dmg);
        
    }
    else
    {
    }
}

void ask_Item_shield(Item *Item, FILE *ptr)
{
    int choice;
    Item->shield = malloc(sizeof(Item->shield));
    do
    {
        printf("Bouclier ? (OUI = 1 / NON = 0): ");
        scanf("%d", &choice);

    } while (choice < 0 || choice > 1);

    if (choice == 1)
    {
        printf("Nouveau bouclier : ");
        scanf("%d", &Item->shield);
        fprintf(ptr, "shield=%d\n", Item->shield);
    }
    else
    {
    }
}

void ask_Item_hpMax(Item *Item, FILE *ptr)
{
    int choice;
    Item->hpMax = malloc(sizeof(Item->hpMax));
    do
    {
        printf("Points de vie ? (OUI = 1 / NON = 0): ");
        scanf("%d", &choice);

    } while (choice < 0 || choice > 1);

    if (choice == 1)
    {
        printf("Nouveau point(s) de vie : ");
        scanf("%d", &Item->hpMax);
        fprintf(ptr, "hpMax=%d\n", Item->hpMax);
    }
    else
    {
    }
}

void ask_Item_name(Item *Item, FILE *ptr)
{

    Item->name = malloc(MAX_SIZE * sizeof(Item->name));
    printf("\nNouveau nom : ");
    fflush(stdin);
    scanf("%s", Item->name);
    fprintf(ptr, "---\nname=%s\n", Item->name);
}
