/*******************************************************************
 *  main.c
 *  This is an embedded program template.
 *  
 *  Author: G. Serpen
 *  Date: Date: May 22, 2017
 *
 *  
 *******************************************************************/


void question2(void){
	int factorial = 1;
	int i;

	for (i = 1; i <= 5; i++) {
		factorial *= i;
	}
}

void question3(void){
	
}

// Called by startup assembly code, start of C code
int main(void){    
	question2();
	question3();
	
  while(1){
		
  }
}


