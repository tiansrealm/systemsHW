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
static void printNameValuesBackwards();
////////////////////////////////////////////////////////
char* input;
NameValue *nameValues;
int numPairs = 0;
////////////////////////////////////////////////////
int main(int argc, char* argv[]){
  readStdin();
  printf("input:\n%s\n", input);
  parseInput();
  
  printf("reverse:\n");
  printNameValuesBackwards();
}

static void readStdin(){
	int i;
	char c;
	input = malloc(MAX_INPUT_SIZE);
	fread(input, MAX_INPUT_SIZE, 1, stdin);
}

//after readStdin only
//process and saves the namevaule pairs from input
static void parseInput(){
	int verticalBars = 0;
	int i;
	for(i = 0; input[i] != '\0'; i++)
		if(input[i] == '|') verticalBars++;
	int totalPairs = verticalBars / 2;

	nameValues = calloc(totalPairs, sizeof(NameValue));
	int vBarCount = 0;
	int boolColonProcessed = 0;
	//int boolUpComingValue = 0; not used

	//namepointer after odd number of '|'
	//value pointer after ':' (skipping one space)
	// ':' and even '|' changed to '\0' 
	for(i = 0; i < MAX_INPUT_SIZE && numPairs <= totalPairs; i++){
	  	if(input[i] == '|'){
	  		if(++vBarCount % 2 == 0){
	  			input[i] = '\0';
	  			numPairs++;
	  			boolColonProcessed = 0;
	  		}else
	  			nameValues[numPairs].name = &input[i+1];
	  	}else if(input[i] == ':' && !boolColonProcessed){
	  		input[i] = '\0';
	  		nameValues[numPairs].value = &input[i+2];
	  		boolColonProcessed = 1;
		}
	}
}

static void printNameValuesBackwards(){
	int i;
	for(i= numPairs - 1; i >= 0; i--){
		printf("%s = %s\n", nameValues[i].value,nameValues[i].name);
	}
}
