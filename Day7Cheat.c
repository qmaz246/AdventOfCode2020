#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define LEN(a) ((int)(sizeof(a)/sizeof(*(a))))

static char names[1024][32];
static int counts[1024][1024];
static int nnames;

static int
getid(const char *name)
{
	int i;

	for (i=0; i<nnames; i++){
		if (!strcmp(names[i], name)){
			return i;
        }
    }
	if (++nnames > LEN(names)){
		printf("Error: name overflow\n");
    }

	snprintf(names[i], LEN(names[i]), "%s", name);
	return i;
}

static void
parse(void)
{
    FILE *fp;
    int bufferLength = 255;
	char buffer[bufferLength];
    char * pch;

    fp = fopen("./Day7_input.txt", "r");
	char adj[16], col[16], name[32], prule1[16];
	int c=0, subj, count;

    // while(fgets(buffer, bufferLength, fp)) {
    //     if(strcmp(buffer, "\n")==0){
    //         break;
    //     }
    //     pch = strtok(buffer, " "); // adjective
    //     strcpy(adj, pch);
    //     pch = strtok(NULL, " "); // color
    //     strcpy(col, pch);
    //     snprintf(name, 32, "%s %s", adj, col);
    //     subj = getid(name);
    //     pch = strtok(NULL, " "); // bags
    //     pch = strtok(NULL, " "); // contains
    //     pch = strtok(NULL, " "); // #
    //     while(pch != NULL){
    //         sprintf(prule1, "%s", pch);
    //         count = atoi(prule1);
    //         pch = strtok(NULL, " "); // Adj
    //         sprintf(adj, "%s", pch);
    //         pch = strtok(NULL, " "); // Color
    //         sprintf(col, "%s", pch);
    //         counts[subj][getid(name)] = count;
    //         pch = strtok(NULL, " "); // bags,/bags.
    //         pch = strtok(NULL, " "); // #
    //     }
    // }
	while (c != EOF) {
		if (scanf("%15s %15s", adj, col) != 2)
			return;
		snprintf(name, 32, "%s %s", adj, col);
		subj = getid(name);

		while ((c=getchar()) != EOF && c!='\n')
			if (isdigit(c))
				{ ungetc(c, stdin); break; }
		while (c != EOF && c != '\n') {
			if (scanf(" %d %15s %15s", &count,adj,col) != 3)
				return;
			snprintf(name, 32, "%s %s", adj, col);
			counts[subj][getid(name)] = count;

			while ((c=getchar())!=EOF && c!=',' && c!='\n')
				;
		}
	}
}

static int holds(int subj, int obj)
{
	int i;

	if (counts[subj][obj]){
		return 1;
    }
	for (i=0; i<nnames; i++){
		if (counts[subj][i] && holds(i, obj)){
			return 1;
        }
    }
	return 0;
}

static int bagcount(int subj)
{
	int i, acc = 1;
    
	for (i=0; i<nnames; i++){
		if (counts[subj][i]){
			acc += counts[subj][i] * bagcount(i);
        }
    }
	return acc;
}

int
main()
{
	int i, p1=0, p2, gold;

	parse();
    printf("here");
	gold = getid("shiny gold");
    printf("Gold id: %d, nnames: %d\n", gold, nnames);
	for (i=0; i < nnames; i++)
		p1 += holds(i, gold);
	p2 = bagcount(gold)-1;

	printf("%d %d\n", p1, p2);
}