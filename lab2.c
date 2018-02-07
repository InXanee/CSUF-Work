#include <stdio.h>
#include <string.h>
#include <assert.h>

<<<<<<< HEAD
int main(){

	unsigned int inputIntVal = 0;
	unsigned int pastIntVal = 0;

	char strin[10];

	while(1){
	if (scanf("%s", strin) <= 0) break;
	if (scanf(" %x", &inputIntVal) <= 0) break;
	if (strcmp(strin, "q") == 0) break;
	if (strcmp(strin, "set") == 0){
		pastIntVal = inputIntVal;
	}
	else if (strcmp(strin, "shl") == 0) {
		pastIntVal = pastIntVal << inputIntVal;
	}
	else if (strcmp(strin, "or") == 0) {
		pastIntVal = pastIntVal | inputIntVal;
	}
	else if (strcmp(strin, "shr") == 0) {
		pastIntVal = pastIntVal >> inputIntVal;
	}
	else if (strcmp(strin, "and") == 0) {
		pastIntVal = pastIntVal & inputIntVal;
	}
	else if (strcmp(strin, "xor") == 0) {
		pastIntVal = pastIntVal ^ inputIntVal;
	}
	else{
	printf("Invalid input\n");
	return 0;
	}

	printf("%s => 0x%x \n", strin, pastIntVal);
=======
void setFunc(unsigned int *z, unsigned int *y) {
	*y = *z;
}

void shlFunc(unsigned int *z, unsigned int *y) {
	*y << *z;
}

void orFunc(unsigned int *z, unsigned int *y) {
	*y | *z;
}

void shrFunc(unsigned int *z, unsigned int *y) {
	*y >> *z;
}

void andFunc(unsigned int *z, unsigned int *y) {
	*y & *z;
}

void xorFunc(unsigned int *z, unsigned int *y) {
	*y ^ *z;
}

int main(){

	unsigned int inputIntVal;
	unsigned int pastIntVal;
	int loopVal = 0;
	char strin[10];
	//printf("Please enter operation and number: ");
	while(loopVal != 3){

	if (scanf("%s", strin)==1){}
	if (scanf(" %x", &inputIntVal)==1){}

	if (strcmp(strin, "set") == 0){
			setFunc(inputIntVal, pastIntVal);
	}
	else if (strcmp(strin, "shl") == 0) {
		shlFunc(inputIntVal, pastIntVal);
	}
	else if (strcmp(strin, "or") == 0) {
		orFunc(inputIntVal, pastIntVal);
	}
	else if (strcmp(strin, "shr") == 0) {
		shrFunc(inputIntVal, pastIntVal);
	}
	else if (strcmp(strin, "and") == 0) {
		andFunc(inputIntVal, pastIntVal);
	}
	else if (strcmp(strin, "xor") == 0) {
		xorFunc(inputIntVal, pastIntVal);
	}
	else{

	}

	printf("\n%s => %x \n", strin, inputIntVal);
	loopVal++;
>>>>>>> origin/master
	}
	return 0;
}
