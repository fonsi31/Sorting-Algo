#include <stdio.h>
#include <string.h>

typedef char string[30];

void sortemails(string names[], int size);

int main() {
	
	string emails[5];
	
	for(int i = 0; i < 5; i++){
		scanf("%s", emails[i]);
	}
	
	int size = sizeof(emails) / sizeof(emails[0]);
	
	sortemails(emails, size);

	
	for(int k = 0; k < 5; k++){
		printf("%d. %s\n", k+1, emails[k]);
	}
	
           
	return 0;

}

void sortemails(string *names, int size){
	
	int i, j, k;
	int x;
	string sorted;
	string extracted[size];

	for(k = 0; k < size; k++){
		char *dot, *at;
		dot = strchr(names[k], '.');
		at = strchr(names[k], '@');
		int len = at - dot - 1;
		strncpy(extracted[k], dot + 1, len);
		extracted[k][len] = '\0';
	}
	
	for (i = 0; i < size; i++){
		for(j = i+1; j < size; j++){
			x = 1;
			while((strncmp(extracted[i], extracted[j], x) == 0) && extracted[i][x-1] != '\0' && extracted[j][x-1] != '\0'){
				x++;
			}
			
			if(strncmp(extracted[i], extracted[j], x) > 0){
				string temp;
				strcpy(temp, names[i]);
				strcpy(names[i], names[j]);
				strcpy(names[j], temp);
				
				
				strcpy(sorted, extracted[i]);
				strcpy(extracted[i], extracted[j]);
				strcpy(extracted[j], sorted);
				
			} 
		}
	}
	
}

