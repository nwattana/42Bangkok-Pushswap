t_ms	*ms_init(int cs, t_prog *prog)
{
	t_ms *ms;

	ms = ft_calloc(sizeof(t_ms));
	if (!ms)
		return (NULL);
	ms->last_p = prog->size - 2;
	ms->ngrp = prog->size / cs + (prog->size % cs > 0);
	ms->p_top = ms->ngrp;
	ms->p_bot = 0;
	ms->ch = assign_ch(prog, cs, ms->ngrp);
	return (ms);
}

void	show_ms(t_ms *ms)
{
	ft_printf("last_p %d\n", ms->last_p);
	ft_printf("ngrp %d\n", ms->ngrp);
	ft_printf("p_top %d\n", ms->p_top);
	ft_printf("p_bot %d\n", ms->p_bot);
}

void	show_ms_cs(t_ms *ms)
{
	int	i;

	if (ms == NULL || ms->ch == NULL)
	{
		ft_putstr_fd("Empty\n", 1);
		return ;
	}
	i = 0;
	while (i<ms->ngrp)
		dump_ch(ms->ch[i++]);
}
