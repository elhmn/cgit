#ifndef CONFIG_H
#define CONFIG_H

typedef struct 	s_options {
	int verbose;
	char *file;
	/* optind index of the last string parsed from argv */
	int optind;
} 				t_options;

typedef struct  s_config {
  	t_options opts;
  	/* cmd is command specified after git [command] */
  	char *cmd;
} 				t_config;

t_config new_config(int ac, char **av);
char *get_subcommand(char* cmd);
int is_cmd_supported(char *cmd);
void print_options(t_options opts, int depth);
void print_config(t_config conf);
void printfln_with_padding(char *str, int depth, ...);

#endif /* CONFIG_H */
