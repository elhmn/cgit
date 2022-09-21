#include "config.h"
#include "init.h"
#include <stdio.h>

int main(int ac, char **av) {
    t_config conf = new_config(ac, av);

    init(conf);
    return (0);
}
