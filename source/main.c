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

int main(int argc, char *argv[])
{
    struct config_struct config_struct;
    confit_structure_init(&config_struct);
    char *input_string = NULL;
    int rand_number;
    int input_number;

    /* handle CLI flags */
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            // --help
            if(not strcmp(argv[i], "--help"))
            {
                puts("Flags are unstable");
                puts("--help | --version | --num_base <num>");
                goto normal_exit;
            }
            // --version
            if(not strcmp(argv[i], "--version"))
            {
                puts(APP_VERSION_STRING);
                goto normal_exit;
            }
            // --num_base
            if(not strcmp(argv[i], "--num_base"))
            {
                if(argc - 1 - i > 0)
                {
                    i++;
                    config_struct.number_base = atoi(argv[i]);
                }
                else
                    goto error_std;
                continue;
            }
        }
    }

    while(true)
    {
        // generate new random int
        srand((unsigned)time(NULL));
        rand_number = rand() % 0x101;
        printf("Bineary:\t%0#10b\n", rand_number);

        // get input
        printf("Convert Number Base to %d\n", config_struct.number_base);
        input_string = rl_gets("Input:\t");
        // some break way
        if(not strcmp(input_string, "exit"))
            break;
        input_number = strtol(input_string, NULL, config_struct.number_base);

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

    normal_exit:
    return 0;
    error_std:
    puts("Standard error");
    return 1;
}

int confit_structure_init(struct config_struct *config)
{
    config->number_base = 16;
    return 0;
}
