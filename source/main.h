#pragma onec

#include <stdbool.h>
#include <iso646.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <readline/readline.h>

struct config_struct
{
    uint8_t number_base;
};

int main(int argc, char *argv[]);
char *rl_gets (const char *prompt_string);
int confit_structure_init(struct config_struct *config);
