#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#include "main.h"

#include <string.h>

#define MAX_LINE_LENGTH 1000
// sens=1 -> vers la droite
int extract_line(const char *full, const char *to_search, char *sub, int sens)
{
    // find substring position
    char *pos = strstr(full, to_search);
    if (pos == NULL)
        return -1;

    // read line until \n
    int i = 0;
    if (sens == 1)
    {
        while (pos[i] != '\n')
        {
            sub[i] = pos[i];
            i++;
        }
    }
    else if (sens == 0)
    {
        int debut_str = full - pos;
        // printf("debut_str:%d\n", debut_str);
        //  remonter jusq'a la ligne d'avant
        while (pos[i] != '\n' && i > debut_str)
        {
            i--;
        }
        i = i + 1;
        int j = 0;
        while (pos[i] != '\n')
        {
            sub[j] = pos[i];
            i++;
            j++;
        }
    }
    else
    {
        printf("Sens inatendu");
        return -1;
    }
    return 0;
}

void str_before_delimiter(const char *full, const char delimiter, char *sub)
{
    int i = 0;
    while (full[i] != delimiter)
    {
        sub[i] = full[i];
        i++;
    }
}

int main()
{
    bool fail = false;

    FILE *fp;
    char path[1035];

    /* Open the command for reading. */
    fp = popen("nmap -n -sP 10.7.0.0/24", "r");
    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path), fp) != NULL)
    {
        char sub[MAX_LINE_LENGTH];
        char subsub[MAX_LINE_LENGTH];
        for (int i = 0; i < MAX_LINE_LENGTH; i++)
            sub[i] = 0;
        int found = extract_line(path, "Nmap scan report for ", sub, 1);

        if (found == 0)
        {
            printf("\"%s\"\n", sub);

            str_before_delimiter(sub, ".pedago.ipb.fr", subsub) ;
            printf("\"%s\"\n", subsub);
        } // else  printf("Ligne pas trouvé READ:\n\"%s\"", line);
        // printf("%s", path);
    }

    /* close */
    pclose(fp);

    if (fail == true)
    {
        printf("======================\n");
        printf(ANSI_RED "        FAIL" ANSI_RESET "\n");
        printf("======================\n");
    }
    else
    {
        printf("======================\n");
        printf(ANSI_GREEN "        PASS" ANSI_RESET "\n");
        printf("======================\n");
    }

    return 0;
}