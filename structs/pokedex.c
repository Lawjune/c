#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct pokemon
typedef struct 
{
    char name[20];
    int hp;
    char type[10];
} pokemon;

// typedef struct pokemon pokemon;

void print_pokemon(const pokemon *p);
const pokemon * search_pokedex(const char *t, 
                               const pokemon dex[],  
                               int length);
pokemon * loadPokedex(char *filename, int *size);
int pokemon_compare(const void *p1, const void *p2);
int psearch(const void *target, const void *expect);

int main(int argc, char *argv[])
{
    // Check number of command line arguments
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    // FILE *pf = fopen(argv[1], "r");
    // if (!pf)
    // {
    //     fprintf(stderr, "Can't open %s for reading: ", argv[1]);
    //     perror(NULL);
    //     exit(1);
    // }

    // pokemon pokedex[10];
    // int count = 0;

    // char line[100];
    // while (fgets(line, 100, pf) != NULL) 
    // {
    //     // pokemon p;
    //     // sscanf(line, "%s,%d,%s", p.name, &p.hp, p.type);
    //     // sscanf(line, "%[^,],%d,%s", p.name, &p.hp, p.type);
    //     sscanf(line, "%[^,],%d,%s", pokedex[count].name, 
    //                                 &pokedex[count].hp, 
    //                                 pokedex[count].type);
    //     // printf("Name: %s, Hint Point: %d, Type: %s\n", 
    //     //         p.name, p.hp, p.type);
    //     count++;
    // }
    pokemon *pokedex;
    int count = 0;
    pokedex = loadPokedex(argv[1], &count);
    qsort(pokedex, count, sizeof(pokemon), pokemon_compare);

    for (int i = 0; i < count; i++)
    {
        // printf("%d: %s %d %s\n", i, 
        //                         pokedex[i].name, 
        //                         pokedex[i].hp, 
        //                         pokedex[i].type);

        printf("%d: ", i);
        print_pokemon(&pokedex[i]);
        printf("\n");
    }

    char target[20];
    printf("Enter the name of a pokemon to find: ");
    fgets(target, 20, stdin);
    // Trim newline
    char *newline = strchr(target, '\n');
    if (newline) *newline = '\0';

    // Do linear search
    for (int i = 0; i < count; i++)
    {
        if (strcmp(target, pokedex[i].name) == 0)
        {
            printf("%d: ", i);
            print_pokemon(&pokedex[i]);
            printf("\n");
        }
    }
    // const pokemon *found = search_pokedex(target, pokedex, count);
    const pokemon *found = (pokemon *)bsearch(target, 
                                   pokedex, 
                                   count, 
                                   sizeof(pokemon),
                                   psearch);
    if (found) 
    {
        printf("Found: ");
        print_pokemon(found);
        printf("\n");
    }
    else 
    {
        printf("Awww, didn't find it.\n");
    }

    // fclose(pf);
    free(pokedex);
    return 0;
}

int pokemon_compare(const void *p1, const void *p2)
{
    char * p1_name = ((pokemon *)p1)->name;
    char * p2_name = ((pokemon *)p2)->name;
    int cmp = strcmp(p1_name, p2_name);
    if (cmp == 0)
    {
        return (((pokemon *)p1)->hp - ((pokemon *)p2)->hp);
    }
    else
    {
        return cmp;
    }
}

void print_pokemon(const pokemon *p)
{
    printf("%s %d %s", p->name, p->hp, p->type);
}

// Given the name of target pokemon to find,
// and the array of pokemon to search through,
// and the  length of the array,
// return the found pokemon or NULL.
const pokemon * search_pokedex(const char *t, 
                               const pokemon dex[],  
                               int length)
{
    for (int i = 0; i < length; i++)
    {
        // Compare target name with name of pokedex
        if (strcmp(t, dex[i].name) == 0)
        {
            return &dex[i];
        }
    }

    return NULL;
}

pokemon * loadPokedex(char *filename, int *size)
{
    FILE *pf = fopen(filename, "r");
    if (!pf)
    {
        fprintf(stderr, "Can't open %s for reading: ", filename);
        perror(NULL);
        exit(1);
    }

    pokemon *pokedex = (pokemon *)malloc(10 * sizeof(pokemon));
    int count = 0;
    char line[100];
    while (fgets(line, 100, pf) != NULL) 
    {
        sscanf(line, "%[^,],%d,%s", pokedex[count].name, 
                                    &pokedex[count].hp, 
                                    pokedex[count].type);
        count++;
    }

    // Close pokemon file
    fclose(pf);

    // Return pokemon array
    *size = count;
    return pokedex;
}

int psearch(const void *target, const void *expect)
{
    char *t = (char *)target;
    pokemon *e = (pokemon *)expect;

    return strcmp(t, e->name);
}