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
        while (pos[i] != '\n' &&  pos[i]!=0)
        {
            sub[i] = pos[i];
            i++;
        }
	sub[i+1]=0;
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
    fp = popen("nmap -sP 10.7.0.0/24", "r");
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
	char subsubsub[MAX_LINE_LENGTH];
	char subsubsubsub[MAX_LINE_LENGTH];
        for (int i = 0; i < MAX_LINE_LENGTH; i++){
            sub[i] = 0;
		subsub[i]=0;
		subsubsub[i]=0;
		subsubsubsub[i]=0;
}

        int found = extract_line(path, "Nmap scan report for ", sub, 1);

        if (found == 0)
        {
    //        printf("sub:\"%s\"\n", sub);

            str_before_delimiter(sub, '.', subsub) ;
  //          printf("subsub:\"%s\"\n", subsub);
		if(extract_line(subsub,"for",subsubsub,1)==0){
//		printf("subsubsub \"%s\"\n",subsubsub);

		if(extract_line(subsubsub," ",subsubsubsub,1)==0)
		printf("Hôte dispo :%s\n",subsubsubsub);
		}
	
        }
        // printf("%s", path);
    }

    /* close */
    pclose(fp);

    return 0;
}
