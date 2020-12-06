#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

    FILE * fp;
    char line[26];
    int running_sum = 0;
    int* ans;
    int questions = 0;
    int num_in_group = 0;
    ans = (int *)malloc(26 *sizeof(int));
    fp = fopen(argv[1], "r");
    
    for(int i = 0; i < 26; i++){
        ans[i] = 0;
    }

    int test = 0;
    while(fgets(line, 28, fp)){
        printf("%s\n", line);

        if(strcmp(line, "\n")==0){
            printf("%d\n", num_in_group);
            questions = 0;
            for(int i = 0; i < 26; i++){
                if(ans[i] == num_in_group){
                    questions++;
                }
            }

            running_sum += questions;
            for(int i = 0; i < 26; i++){
                ans[i] = 0;
            }
            num_in_group = 0;
        } else {
                    
            for(int i = 0; i < 28; i++){
                if(line[i] == '\n'){
                    break;
                }
                ans[line[i]-'a']++;
            }
            num_in_group++;
        }
    }

    printf("%d\n", running_sum);
}