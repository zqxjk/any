#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
	const int magical = 0x5678 ^ 0x1234;
	int sum;
	char DO_WORK_ONCE = 0;
	if(argc >= 2)
		if(strcmp(argv[1], "-q") == 0)
			DO_WORK_ONCE = 1;

	printf("Welcome to CrackMe v1.0 keygen! To generate serial key simply input desired login below.\n(Note: some symbols may be invalid)\n");
	char NO_SHOW_PROMPT = 1;

	while(NO_SHOW_PROMPT){
		char name[256];
		scanf("%s", name);
		sum = 0;
		int length = strlen(name);
		if(length > 10)
			length = 10;

		if(name[0] == '\n'){
			printf("Exiting!\n");
			break;
		}
		char NAME_IS_CORRECT = 1;

		for (int i = 0; i < length; ++i){
			if(name[i] >= 'A'){
				if(name[i] >= 'Z'){
					sum += name[i] - 0x20;
				}
				else{
					sum += name[i];
				}
			}
			else{
				printf("Incorrect symbols in name\n", );
				NAME_IS_CORRECT = 0;
				break;
			}
		}


		if(NAME_IS_CORRECT){
			sum = sum ^ magical;
			printf("Serial-->%d\n", sum);
		}
		if(DO_WORK_ONCE)
			return 0;
			
	}
	system("pause");
	return 0;
}
