#include <stdio.h>
#include <stdlib.h>

void testfun(int argc, char *argv[]) {
	printf("test\n");
	for (int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
}


int main() {
	// Test example
	/*
	struct commandNode test = {&testfun};
	test.validParameters = malloc (sizeof(char*) * 2);
	test.validParameters[0] = "test";
	test.validParameters[1] = "b";

	char **testGivenParameters = malloc(sizeof(char*) * 2);
	testGivenParameters[0] = "a";
	testGivenParameters[1] = "b";

	test.fptr(2, testGivenParameters);

	// We have to do this in a loop later!
	free(test.validParameters);
	free(testGivenParameters);

	*/
	
	printf("Hello world!\n");
	return 0;
}
