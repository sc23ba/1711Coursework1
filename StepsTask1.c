#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    int buffer_size = 100;
    char line_buffer[buffer_size];
    int count = 0;
    FILE *file = fopen("FitnessData_2023.csv", "r"); //change from filename
    if (file == NULL){
        perror("");
        return 1;
    }
    else{
        while(fgets(line_buffer, buffer_size, file) != NULL){
            count++;
        }
    }
    rewind(file);  //code is from suggestion from chatgbt
   
    FITNESS_DATA Array[count];

    if (file == NULL){
        perror("");
        return 1;
    }
    else{
        char date[11];
        char time[6];
        char steps[10];
        int stepsint;

        while(fgets(line_buffer, buffer_size, file) != NULL){
            printf("%s", line_buffer);
            tokeniseRecord(line_buffer, ",", date, time, steps);
        }
    }

    printf("\n%d\n", count);
    
    

    fclose(file);
    return 0;
}
