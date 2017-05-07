#include<stdio.h>
#include<string.h>
#include<stdbool.h>
	
bool yes = true;		//idk why
bool present = false; 	//for macro name printing
	
//Function inialization
void expand(char file[10]);
	
//List of macro names
char *macros[50] = {"INCR","COMP"};
	
//Main function
	
main(void){
		
	char file[10];
	//Enter file name	
	printf("Enter File Name : \n");
	scanf("%s",&file);
	
	//Calling macro expansion
	expand(file);	
					
}//End main()
	
//Function for macro expansion
void expand(char file[10]){
		
	
//Mechanism to copy the macro definition to a file
		
	FILE *f1,*f2,*f3;
		
	f2 = fopen("output.txt","w");		//Output file
	f3 = fopen(file,"r");				//Input file
	char str[100];						//String buffer 
	char fstr[100];						//String buffer to store input file string
	int i;
		
	//Reading input file
		
	while(!feof(f3)){
		
	 fgets(fstr,99,f3);	
		 
	 //Loop to check if macro is present or not
	 for(i=0; i<2; i++){
	 	
		int res = strncmp(macros[i],fstr,4);	//check if macro present
		
		if(res == 0){	//if macro found
		 		
		  present = true;	//macro found
		 		
		  f1 = fopen("macro.txt","r");	//opening macro definition file
		 		
		  //Reading content of macro file
		 		
		 while(!feof(f1)){
		
			fgets(str,99,f1);	
			// puts(str);
			//Looking for macro definition in the text file
					 
			int res = strncmp(macros[i],str,4);		
					 
			if(res == 0){	//Macro definition found 
					 		   		
			    while(yes){
						   	   
				fgets(str,99,f1);	   	//Getting string from Macro text file
				int r = strncmp(str,"MEND",4);		
				if(r == 0)		   //Checking whether MEND is encountered
				   break;    
				fprintf(f2,"+ %s",str);	  //Writing  macro definition into the output file till MEND is encountered! 	   		   	
				//puts(str);
			} //End inner while 					 	
					 
		 }	//end inner if
					
	   }//End while
		 		 		
	fclose(f1);	//Closing macro file pointer so that we can read the macro file from the beginning if another macro found
			
	 } //End if
		 	
	}//End for
	 
 	if(!present)	//if its not a macro name then print it on file else move to next string
 		fprintf(f2,"%s",fstr);  
	 
	 present = false;		 		
		 
  }//End while
		 	 	
	
	//Closing file pointers

	fclose(f2);
	fclose(f3);		
	
}
	
	

