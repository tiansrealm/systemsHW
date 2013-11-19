#include <stdio.h>	
#include <stdlib.h>

#define MAX_INPUT_SIZE 300
//
typedef struct NameValue {
	char *name;
	char *value;
}NameValue;

// Prototypes
static void readStdin();
static void parseInput();
////////////////////////////////////////////////////////
char* input;
NameValue *nameValues;

////////////////////////////////////////////////////
int main(int argc, char* argv[]){
	readStdin();
	parseInput();
}

static void readStdin(){
	int i;
	char c;
	input = malloc(MAX_INPUT_SIZE);
	fread(input, MAX_INPUT_SIZE, 1, stdin);
	/*
	for(i = 0; i < MAX_INPUT_SIZE; i++){
		if((c = fgetc(stdin)) != EOF){
			input[i] = c; 
		}else {	break; }
	}
	*/
}

//after readStdin only
//process and saves the namevaule pairs from input
static void parseInput(){
	int verticalBars = 0;
	int i;
	for(i = 0; input[i] != '\0'; i++)
		if(input[i] == '|') verticalBars++;
	int numPairs = verticalBars / 2;

	//*nameValues = calloc(numPairs, sizeof NameValue);
	//for(i = 0; i < numPairs; i++){
	  //	//nameValues[i].name = 
	  //}
	printf("%s",input); //testing succesful 11/18/2013
	printf("%d\n", numPairs);
	printf("OK");
}
