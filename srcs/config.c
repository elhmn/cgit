#include "config.h"
#include <getopt.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int set_params(t_options *opts, int ac, char **av) {
    int c = 0;
    int option_index = 0;

    if (!opts) {
        return -1;
    }

    if (!opts) {
        printf("Error: opts is set to null");
        return -1;
    }

    struct option long_options[] = {{"verbose", no_argument, &opts->verbose, 1},
                                    {"file", required_argument, NULL, 'f'},
                                    {0}};

    while ((c = getopt_long(ac, av, "vf:", long_options, &option_index)) !=
           -1) {
        switch (c) {
        case 1:
            if (optarg) {
                opts->verbose = atoi(optarg);
            }
            break;
        case 'f':
            opts->file = optarg;
            break;
        default:
            break;
        }
    }
    opts->optind = optind;
    return 0;
}

t_config new_config(int ac, char **av) {
    t_options opts = {};
    t_config conf = {opts, get_subcommand(av[1])};

    if (set_params(&conf.opts, ac, av)) {
        printf("failed to set_params");
    }

    return conf;
}

/* is_cmd_supported returns 0 if a command is supported and -1 if not */
int is_cmd_supported(char *cmd) {
    if (strcmp("init", cmd)) {
        return -1;
    }

    return 0;
}

char *get_subcommand(char *cmd) {
    if (!cmd) {
        return NULL;
    }

    if (is_cmd_supported(cmd) == -1) {
        return NULL;
    }

    return cmd;
}

char *padding(int depth) {
    int i = 0;
    char *str = (char *)malloc((sizeof(char) * depth) + 1);

    for (i = 0; i < depth; i++) {
        str[i] = '\t';
    }
    str[i] = '\0';

    return str;
}

void print_options(t_options opts, int depth) {
    printfln_with_padding("opts {", depth - 1);
    printfln_with_padding("verbose: %d", depth, opts.verbose);
    printfln_with_padding("optind: %d", depth, opts.optind);
    printfln_with_padding("file: %s", depth, opts.file);
    printfln_with_padding("}", depth - 1);
}

void printfln_with_padding(char *str, int depth, ...) {
    va_list arglist;
    va_start(arglist, depth);

    // TODO: fix this, not very safe
    // make it a little more dynamique
    char format[2048] = "";

    sprintf(format, "%s%s\n", padding(depth), str);
    vprintf(format, arglist);
    va_end(arglist);
}

void print_config(t_config conf) {
    printf("config {\n");
    printfln_with_padding("cmd: %s", 1, conf.cmd);
    print_options(conf.opts, 2);
    printf("}\n");
}
