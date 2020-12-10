#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main(int argc, char **argv){
    FILE * fp;
    char nline[255];
    char line[255];
    int preamble_size = 25;
    int preamble[preamble_size];
    int input[1001];
    int line_loc = 0;
    int value, i, j, invalid;
    int valid = 0;
    fp = fopen("./Day9_input.txt", "r");

    // Part 1
    while(fgets(line, 255, fp)){
        line[strlen(line)-1] = '\0';
        printf("%s\n", line);
        if(line_loc < preamble_size){
            preamble[line_loc] = atoi(line);
            input[line_loc] = atoi(line);
            
        }else{
            // continue storing
            input[line_loc] = atoi(line);

            // Valid?
            value = atoi(line);
            for(i = 0; i < preamble_size; i++){
                for(j=i+1; j < preamble_size; j++){
                    if((preamble[i] + preamble[j]) == value){
                        valid = 1;
                        printf("%d + %d = %d\n\n", preamble[i], preamble[j], (preamble[i] + preamble[j]));
                    }
                }
            }
            if(valid == 0){
                // invalid value
                printf("Invalid Value: %d\n", value);
                invalid = value;
                break;
            }else{
                // shift preamble
                for(i=0; i < preamble_size-1; i++){
                    preamble[i] = preamble[i+1];
                }
                preamble[preamble_size-1] = value;
                // continue storing
                input[line_loc] = atoi(line);
            }
            
            valid = 0;
            
        }
        line_loc++;
    }
    
    // Part 2
    int cont_sum = 0;
    // Check for contiguous
    i = -1;
    int max, min;
    while(cont_sum != invalid){
        i++;
        cont_sum = input[i];
        min = input[i];
        max = input[i];

        for(j = i+1; j < line_loc; j++){
            if(input[j] < min){
                min = input[j];
            }
            if(input[j] > max){
                max = input[j];
            }
            cont_sum += input[j];
            if(cont_sum == invalid){
                printf("Found, ans: %d\n", (min+max));
                break;
            }else if(cont_sum > invalid){
                break;
            }
        }
    }

    // int cont_array[(j-i)+1];
    // int k = 0;
    // for(i; i < j; i++){
    //     cont_array[k++] = input[i];
    // }
    // qsort (cont_array, (j-i+1), sizeof(int), compare);
    fclose(fp);

}