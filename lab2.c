#include <stdio.h>
#include <string.h>
#include <assert.h>

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
	}
	return 0;
}
