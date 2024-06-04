#include "main.h"

/* A static variable for holding the line. */
static char *line_read = (char *)NULL;

/* Read a string, and return a pointer to it.
   Returns NULL on EOF. */
char *rl_gets (const char *prompt_string)
{
    /* If the buffer has already been allocated,
        return the memory to the free pool. */
    if(line_read)
    {
        free(line_read);
        line_read = (char *)NULL;
    }

    /* Get a line from the user. */
    line_read = readline(prompt_string);

    return line_read;
}

int main(int argc, int *argv[])
{
    char *input_string = NULL;
    int rand_number;
    int input_number;

    while(true)
    {
        // generate new random int
        srand((unsigned)time(NULL));
        rand_number = rand() % 0x101;
        printf("Bineary:\t%0#10b\n", rand_number);

        // get input
        input_string = rl_gets("Hexadecimal:\t0x");
        // some break way
        if(not strcmp(input_string, "exit"))
            break;
        input_number = strtol(input_string, NULL, 16);

        // is eq?
        if(rand_number == input_number)
            puts("Right");
        else
        {
            printf("Wrong\n");
            printf("right one is:\t%0#4x\n", rand_number);
        }
        // finish once loop
        puts("====NEXT====");
    }

    return 0;
}
