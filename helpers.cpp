#include <getopt.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include "helpers.h"

Config get_config(const int argc, char** argv)
{
    int c;
    int opt_index = 0;
    struct option opts[] = {
        {"algorithm",    required_argument, 0, 'a'},
        {"speed",        required_argument, 0, 's'}
    };

    Config ret_val{ERROR, -1};

    while ((c = getopt_long(argc, argv, "a:s:", opts, &opt_index)) != -1)
    {
        switch (c)
        {
            case 'a':
                if (strncmp(optarg, "bubble", 10) == 0)
                    ret_val.option = BUBBLE;
                else if (strncmp(optarg, "insert", 10) == 0)
                    ret_val.option = INSERTION;
                else if (strncmp(optarg, "select", 10) == 0)
                    ret_val.option = SELECTION;
                else if (strncmp(optarg, "quick", 10) == 0)
                    ret_val.option = QUICK;
                break;
            case 's':
                ret_val.fps = std::stoi(optarg);
                break;
        }
    }

    return ret_val;
}
