/*#include<stdio.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int i;
	
	printf("I am EXEC.c called by execvp() ");
	printf("\n");
	
	return 0;
}*/




#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
		
		char *args[]={"./EXEC",NULL};
		execvp(args[0],args);

		
printf("Ending-----");
	
	return 0;
}

