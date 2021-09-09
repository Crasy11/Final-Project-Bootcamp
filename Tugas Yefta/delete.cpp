#include <stdio.h>
void dlete (){
FILE *fp = fopen ("./isiorderan.txt", "w");
	
	fclose(fp);
}


int main (){
		dlete();
	
	
	return 0;
}
