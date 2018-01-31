#include <stdio.h>
#include <assert.h>
#include <string.h>

void bump_int(int *i, int amount)
{
	*i += amount;
}

void bump_once(int *i)
{
	bump_int(i,1);
}

void bump_string(char *str, char chrTemp)
{
	int currentPos = strlen(str);
	str[currentPos] = chrTemp;
	str[currentPos + 1] = 0x0;
}

void bump_string_once(char *str)
{
	bump_string(str, 'o');
}

int main()
{
	int i = 1;
	
	printf("%d \n",i);
	bump_once(&i);
	printf("%d \n",i);
	bump_int(&i,2);
	printf("%d \n",i);

	char buf[10] = "foo";

	printf("%s \n", buf);
	bump_string_once(buf);
	printf("%s \n", buf);
	bump_string(buf, 'x');
	printf("%s \n", buf);

	return 0;
}
