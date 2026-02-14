#include <stdio.h>
#include <string.h>

typedef char string[30];

int main() {
	
	int i, j, k;
	int x;
	string names[4] = {"nick.burrie@dlsu.edu.ph", "alfonso.cauilan@dlsu.edu.ph", "mike.alvin@dlsu.edu.ph", "james.buffer@dlsu.edu.ph"};
	string sorted;
	int size = sizeof(names) / sizeof(names[0]);
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
	
	for(int k = 0; k < 4; k++){
		printf("%d. %s\n", k+1, names[k]);
	}
	
           
	return 0;

}

