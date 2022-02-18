#!/bin/sh
make fclean all
./real_containers > std_result
./my_containers > my_result

diff std_result my_result  > ladiff
make fclean