#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bag {
	char* color;
	int num;
	struct bag* baglist[100];
	int isLeaf;
};

int main(void){
	
	FILE *fp;
	int bufferLength = 255;
	char buffer[bufferLength];
	char rules[10000][50];
	strcpy(rules[0], "shiny gold");
	int r_i = 1;
	char * pch;
	char prule1[100];
	char prule2[100];
	char prule[300];
	char pbag[300];
	int colors = 0;
	int pass = 0;
	char curr_line[100];
	int loops = 0;
	
	fp = fopen("./Day7_input.txt", "r");
	
	//printf("---Obtain Color Rules---\nshiny gold\n");
	
	// Run through file obtain bag rules, stop when no new bag rules added.
	while(loops < 5){
		//printf("\n---Here are the colors in the color list---\n");
		for(int i = 0; i < r_i; i++){
			printf("%s\n", rules[i]);
		}

		while(fgets(buffer, bufferLength, fp)) {
			pch = strtok(buffer, " "); // adjective
			strcpy(prule1, pch);
			pch = strtok(NULL, " "); // color
			strcpy(prule2, pch);
			sprintf(prule, "%s %s", prule1, prule2);
			//printf("---Is %s in our colors list already, or does it contain a bag in our list?---\n", prule);
			for(int i = 0; i < r_i; i++){
				if(strcmp(prule, rules[i])==0){
					pass = 1;
					break;
				}
			}
			if(pass == 1){
				//("Already in the Colors List\n");
				// Advance the line until it returns NULL
				while (pch != NULL){
					pch = strtok(NULL, " ");
				}
				goto loop_end;
			}
			pch = strtok(NULL, " "); // bags
			pch = strtok(NULL, " "); // contains
			pch = strtok(NULL, " "); // # 
			while (pch != NULL) {
				pch = strtok(NULL, " ");	// color 1
				strcpy(prule1, pch);
				pch = strtok(NULL, " ");	// color 2
				strcpy(prule2, pch);
				sprintf(pbag, "%s %s", prule1, prule2);
				//printf("---Checking for %s in %s---\n", pbag, prule);
				for(int i = 0; i < r_i; i++){
					//printf("---Does %s match %s?---\n", pbag, rules[i]);
					if(strcmp(pbag, rules[i])==0){
						pass = 1;
						//printf("Contains the bag %s\n", rules[i]);
						break;
					}
				}
				if(pass == 1){	// means we found a shiny gold or another bag that contains shiny gold indirectly
					//printf("%s\n", prule);
					strcpy(rules[r_i], prule);
					r_i++;
					// Advance the line until it returns NULL
					while (pch != NULL){
						pch = strtok(NULL, " ");
					}
					break;
				} else {
					//printf("Nope\n");
				}
				
				pch = strtok(NULL, " ");  //bags, 
				pch = strtok(NULL, " ");  //# or NULL for end line
			}
			if(pass == 0){
				//printf("nope\n");
			}
loop_end:
			pass = 0;
		}
		fclose(fp);
	
		fp = fopen("./Day7_input.txt", "r");
		
		loops++;	
	}
	printf("# of Bags: %d\n", r_i);
	fclose(fp);
	
	
	// Time to start over i guess
	char accounted_for[1000][50]; // has struct assigned
	char need_to_check[1000][50]; // found because of previous struct assignment, still needs own struct.
	int num_in_bag = 0;
	int a_i = 0;
	int c_i = 0;
	int ind = 0;
	struct bag outside; // init for shiny gold
	outside.color = "shiny gold";
	strcpy(need_to_check[c_i++], "shiny gold");
	loops = 0;
	while(loops < 3){
		printf("\n---Here are the colors in the accounted for list---\n");
		for(int i = 0; i < a_i; i++){
			printf("%s\n", accounted_for[i]);
		}
		while(fgets(buffer, bufferLength, fp)) {
			pch = strtok(buffer, " "); 	// adjective
			strcpy(prule1, pch);
			pch = strtok(NULL, " "); 	// color
			strcpy(prule2, pch);
			sprintf(prule, "%s %s", prule1, prule2);
			
			// Is this color already accounted for?
			for(int i = 0; i < a_i; i++){
				if(strcmp(prule, accounted_for[i])==0){
						pass = 1;
						break;
				}
			}
			if(pass == 1){		// yes in the accounted list, we can ignore
				pass = 0;
				// Advance to the end of line
				while (pch != NULL){
					pch = strtok(NULL, " ");
				}
				break;
			} 
			// otherwise not in accounted for list, now check in need to check list
			for(int i = 0; i < c_i; i++){
				if(strcmp(0, need_to_check[i])==0){
						pass = 1;
						break;
				}
			}
			if(pass == 1){	// yes in the need to check list, we need to see whats in here then add it to the queue.
				pass = 0;
				outside.color = prule;
				struct 
				// Advance to the start of inards
				pch = strtok(NULL, " ");	// bags
				pch = strtok(NULL, " "); 	// contain
				while (pch != NULL){
					pch = strtok(NULL, " "); // #
					outside.num[ind] = 1
					
				}
				break;
			} 
		
		}
		loops++;
	}
	return 1;
}
