#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char **argv){

    FILE * fp;
    char line[11];
    int row = 0;
    int col = 0;
    int bin_r[7] = {64, 32, 16, 8, 4, 2, 1};
    int bin_c[3] = {4, 2, 1};
    int seat_id_max = 0;
    int seat_id_min = 1000000;
    
    int* seat_id;
    int j = 0;
    seat_id = (int *)malloc(771 *sizeof(int));
    fp = fopen(argv[1], "r");

    while(fgets(line, 11, fp)){
        if(strcmp(line,"\n")!=0){
            printf("%s\n", line);
            row = 0;
            col = 0;

            for(int i = 0; i < 7; i++){
                if(line[i] == 'B'){
                    row = row | bin_r[i];
                }
            }
            //printf("row for %s : %d\n", line, row);
            for(int i = 7; i < 10; i++){
                if(line[i] == 'R'){
                    col = col | bin_c[i];
                }
            }

            //printf("col for %s : %d\n", line, col);
            seat_id[j++] = row*8+col;

            if(seat_id_max < (row*8+col)){
                seat_id_max = row*8+col;
            }
            if(seat_id_min > (row*8+col)){
                seat_id_min = row*8+col;
                if((row*8+col) == 0){
                    printf("%s\n", line);
                }
            }
        }
    }

    printf("Part 1: Seat ID max: %d\n", seat_id_max);
    printf("Seat ID min: %d\n", seat_id_min);

    qsort(seat_id, 771, sizeof(int), compare);

    int seat_check = seat_id[0];

    for(int i = 0; i < 771; i++){
        if(seat_id[i] != seat_check){
            printf("Your Seat ID is : %d\n", seat_check);
            i = 771;
        }
        
        seat_check++;
    }

    return 0;
}