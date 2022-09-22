#include <stdio.h>
#include <math.h>
#include "cub3d.h"

// t_vector	pos = {1.1, 1.1};
// // t_vector	dir = {1.0 / (float)sqrt(2.0), 1.0 / (float)sqrt(2.0)};
// // t_vector	plane = {-1.0 / sqrt(2.0), 1.0 / sqrt(2.0)};
// // t_character	myself = {pos, dir, plane, 0.66};

// char	*grid[11] = {"1111111111",
// 				"1001010001",
// 				"1001010001",
// 				"1001010001",
// 				"1001010001",
// 				"1000000001",
// 				"1001010001",
// 				"1001000001",
// 				"1000010001",
// 				"1111111111"};

// // t_env	env = {10, 10, grid};
// // t_global	global = {env, &myself, 0, 0, 0};


// int main()
// {
// 	t_vector	dir = {1.0 / (float)sqrt(2.0), 1.0 / (float)sqrt(2.0)};
// 	t_vector	plane = {-1.0 / sqrt(2.0), 1.0 / sqrt(2.0)};
// 	t_character	myself = {pos, dir, plane, 0.66};
// 	t_env	env = {10, 10, grid};
// 	t_RC	tools_RC;
// 	t_edge	wall;

// 	printf("Map:\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",\
// 		grid[0], grid[1], grid[2], grid[3], grid[4], grid[5],\
// 		grid[6], grid[7], grid[8], grid[9]);
// 	printf("I'm at (%f, %f)\n", pos.x, pos.y);
// 	printf("Looking towards (%f, %f)\n", dir.x, dir.y);
// 	tools_RC = init_RC_env(myself, 100);
// 	wall = find_wall(myself.pos, tools_RC, env);
// 	printf("wall found at: ( %f ; %f ).\n", pos.x + wall.v_edge.x, pos.y + wall.v_edge.y);
// 	printf("necessary steps in x: %u\nnecessary steps in y: %u\n", wall.c_x, wall.c_y);
// 	printf("horizontal edge: %d\n", wall.horizontal);
// 	return (0);
// }
