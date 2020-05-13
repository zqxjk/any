#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char const *argv[])
{
	const int magical = 0x5678 ^ 0x1234;
	

	int sum;

	char action;
	printf("Welcome to CrackMe v1.0 keygen! To generate serial key simply input desired logins below.\n(Note: some symbols may be invalid)\n");
	char NO_SHOW_PROMPT = 1;

	while(NO_SHOW_PROMPT){
		char name[256];
		scanf("%s", name);
		sum = 0;
		int length = strlen(name);
		if(length > 10)
			length = 10;
		printf("%d", length);

		if(name[0] == '\n'){
			printf("Exiting!\n");
			break;
		}
		char NAME_IS_CORRECT = 1;

		for (int i = 0; i < length; ++i){
			if(name[i] <= 'Z' && name[i] >= 'A'){
				sum += name[i];
			}
			else{
				if(name[i] <= 'z' && name[i] >= 'a'){
					sum += (int)name[i] - 0x20;//0x20 = .32 = 'A' - 'a'
				}
				else{
					printf("Name contains illegal symbols, provide proper name!\n");
					NAME_IS_CORRECT = 0;
					break;
				}
			}
		}
		
		if(NAME_IS_CORRECT){
			sum = sum ^ magical;
			printf("Serial-->%d\n", sum);
		}
		
	}
	return 0;
}