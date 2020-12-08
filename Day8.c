#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EOF_Reached = 0;

int execute(char instr[1000][4], int * value, int max_ind){
    int visited[1000];
    int ind = 0;
    int jump;
    int acc = 0;
    for(int i = 0; i < 1000; i++)
        visited[i] = 0;

    while(1){
        //printf("Location: %d, Instr: %s, acc: %d\n", ind, instr[ind], acc);
        if(visited[ind] == 0){
            visited[ind] = 1;
            if(strcmp(instr[ind], "acc")==0){
                acc += value[ind];
                ind++;
            }else if(strcmp(instr[ind], "jmp")==0){
                jump = value[ind];
                ind += jump;
            }else{
                ind++;
            }
        }else{
            printf("Oops got to ind : %d, acc : %d\n", ind, acc);
            break;
        }

        if(ind == max_ind){
            printf("Reached EOF\n acc : %d\n", acc);
            EOF_Reached = 1;
            break;
        } else if(ind > max_ind){
            break;
        }
    }
}

int main(int argc, char **argv){

    FILE * fp;
    char line[255];
    char instr[1000][4];
    int * value = (int *) malloc(1000 * sizeof(int));
    int acc;
    int ind = 0;
	char * pch;
    fp = fopen("./Day8_input.txt", "r");
    // read entire file and store instructions
    while(fgets(line, 255, fp)){
        //printf("%s", line);
        pch = strtok(line, " "); // command
        strcpy(instr[ind], pch);
        pch = strtok(NULL, " "); // value
        if(pch[0] == '+'){
            value[ind] = atoi(pch + 1);
        } else {
            value[ind] = -1 * atoi(pch + 1);
        }
        //printf("%s %d\n", instr[ind], value[ind]);
        ind++;
        // go to end of line
        while(pch != NULL){
            pch = strtok(NULL, " ");
        }
    }
    int max_ind = ind;
    printf("\n%d\n", max_ind);
    // execute the list
    ind = 0;
    acc = 0;
    int visited[1000];
    for(int i = 0; i < 1000; i++)
        visited[i] = 0;
    int jump = 0;
    int loops = 0;
    // Part 1
    //execute(instr, value, max_ind);
    
    // Part 2
    int repl_ind = 0;
    char cp_instr[1000][4];
    while(1){
        printf("Curr: %d, %s, %d\n", repl_ind, instr[repl_ind], value[repl_ind]);
        // recopy the starting point
        //memcpy(cp_instr, instr, 1000);
        for(int i = 0; i < max_ind; i++){
            strcpy(cp_instr[i], instr[i]);
        }
        // find next value to try and replace
        if(strcmp(instr[repl_ind], "jmp")==0){
            strcpy(cp_instr[repl_ind], "nop");
            printf("Now : %d, %s, %d\n", repl_ind, cp_instr[repl_ind], value[repl_ind]);
            execute(cp_instr, value, max_ind);
        }else if(strcmp(instr[repl_ind], "nop")==0){
            strcpy(cp_instr[repl_ind], "jmp");
            execute(cp_instr, value, max_ind);              
        }else{ // acc then

        }
        if(EOF_Reached == 1){
            printf("ahah!\n");
            break;
        } else {
            repl_ind++;
        }
        loops++;
    }
    printf("%d\n", loops);
}