#include <stdio.h>
#include <math.h>

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;


t_vector	init_vector(float x, float y)
{
	t_vector	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

float	vector_norm(t_vector v)
{
	float	res;

	res = v.x * v.x + v.y * v.y;
	res = sqrt(res);
	return (res);
}

int main()
{
	t_vector	pos;

	pos = init_vector(1.0, INFINITY);
	printf("pos = (%f, %f)\n", pos.x, pos.y);
	if (vector_norm(pos) == INFINITY)
		printf("pos norm: %f\n", vector_norm(pos));
	else
		printf("TOO BIIIIG!\n");
	return (0);
}
