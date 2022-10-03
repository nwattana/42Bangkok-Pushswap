t_ch *assign_ch(t_prog *prog, int cs, int ngrp)
{
	t_ch *res;
	int		i;

	res = ft_calloc(sizeof(t_ch), ngrp);
	if (!res)
		return (NULL);
	i = 0;
	while (i < ngrp)
	{
		ch[i].index = index;
		ch[i].lower = cs * (i - 1);
		ch[i].upper = cs * i;
		if (i == 0)
			ch[i].lower = 1;
		if (i == ngrp - 1)
			ch[i].upper = prog->size - 2;
		ch[i].size = ch[i].upper - ch[i].lower;
		ch[i].ina = ch[i].size;
		i++;
	}
	return (res);
}

void	dump_ch(t_ch ch)
{
	ft_printf("index %d\n",ch.index);
	ft_printf("lower %d\n",ch.lower);
	ft_printf("upper %d\n",ch.upper);
	ft_printf("size %d\n",ch.size);
	ft_printf("ina %d\n",ch.ina);
	ft_printf("inb %d\n",ch.inb);
	ft_printf("PassB %d\n",ch.passb);
	ft_printf("PassA %d\n",ch.passa);
}
