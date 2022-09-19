#include "pushswap.h"

void	l_action(t_act act, int n, t_prog *prog)
{
	int	i;

	i = 0;
	while(i < n)
	{
		action(act, prog);
		i++;
	}
}

