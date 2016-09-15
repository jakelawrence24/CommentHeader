#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_SZ 512

int main(){

    char name[22] = "Christopher Lawrence";
    char class[10];

    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 26, "%m/%d/%Y", tm_info);

    char *instructor = malloc(MAX_NAME_SZ);
    if (instructor == NULL) {
        printf ("No memory\n");
        return 1;
    }

    /* Ask user for name. */
    printf("Instructor name: ");

    /* Get the name, with size limit. */
    fgets(instructor, MAX_NAME_SZ, stdin);

    /* Remove trailing newline, if there. */
    if ((strlen(instructor)>0) && (instructor[strlen (instructor) - 1] == '\n'))
        instructor[strlen (instructor) - 1] = '\0';

    printf("Class ID: ");
    scanf("%s", class);

    printf("/*\n * Programmer: %s      ", name);

    printf("Date completed: %s\n", buffer);

    printf(" * Instructor: Professor %s", instructor);

    int spaces = (strlen(name) - strlen(instructor)) - 4;

    for(int i = 0; i < spaces; i++){
       printf(" ");
    }

    printf("Class: %s\n *\n", class);

    printf(" * Description of program: \n *\n *\n");

    printf(" */\n");
   
    free(instructor);
    return 0;
}