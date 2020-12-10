#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){
	FILE * fp;
	char line[6];
	int sizeofAdapters = 107;
	int adapters[sizeofAdapters];
	int chain[108];
	chain[0] = 0;
	int chainIdx = 0;
	int line_loc = 0;
	fp = fopen("Day10_input.txt", "r");
	int mouseketool = 0;
	//parse
	while(fgets(line, 6, fp)){
		line[strlen(line)-1] = '\0';
		adapters[line_loc] = atoi(line);
		if(adapters[line_loc] > mouseketool)
			mouseketool = adapters[line_loc];
		
		line_loc++;
	}
	line_loc--;
	printf("\n%d\n", mouseketool);
	
	
	//part 1
	int found = 0;
	int i, j, k;
	int one, three = 0;
	while(line_loc >= 0){
		for(j = 1; j < 4; j++){
			//printf("%d\n", line_loc);
			for(i = 0; i < line_loc+1; i++){
				if((adapters[i]-chain[chainIdx]) == j){
					found = 1;
					chain[++chainIdx] = adapters[i];
					break;
				}
			}
			if(found == 1){
				found = 0;
				if(i != line_loc){
					adapters[i] = adapters[line_loc];
				}	
				adapters[line_loc--] = 0;
				if(j == 1){
					one++;
				}else if(j == 3){
					three++;
				}
				break;
			}
		}
	}
	
	printf("one: %d, three: %d\n", one, ++three);
	printf("ans: %d\n", (one*three));
	
	//part2
	

}
