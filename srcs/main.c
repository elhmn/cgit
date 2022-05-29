#include <stdio.h>
#include "init.h"
#include "config.h"

int main(int ac, char **av) {
	t_config conf = new_config(ac, av);

	init(conf);
	return (0);
}
