/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:20:26 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/17 16:32:06 by dpalombo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FRACTOL
# define LIB_FRACTOL

#include "libft.h"
#include "mlx.h"
#include <math.h>
# include <pthread.h>

/*
**	Map
*/

# define WIN_WIDTH		1000
# define WIN_HEIGHT		800
# define DWIN_WIDTH		500.0
# define DWIN_HEIGHT	400.0
# define DEFAULTC		0xFFFFFF
# define JNBR			5
# define MNBR			10
# define BNBR			11
# define TNBR			7
# define THREADNBR		80
# define C(x)			(char)(x)
# define D(x)			(double)(x)
# define I(x)			(int)(x)
# define V(x)			(void)(x)
# define VS(x)			(void *)(x)

/*
**	Keyboard and Colors
*/

# define SCROLL_A		4
# define SCROLL_B		5
# define ESC_KEY		53
# define UP_KEY			126
# define DOWN_KEY		125
# define RIGHT_KEY		124
# define LEFT_KEY		123
# define MORE_KEY		69
# define LESS_KEY		78
# define C_COLOR		8
# define R_KEY			15
# define KING			40
# define Q_KEY			12
# define W_KEY			13
# define WHITE			0xFFFFFF
# define YELLOW			0xFFF00A
# define ORANGE			0xFF9900
# define PINK			0xFF00FF
# define BLUE			0x0000FF
# define RED			0xFF0000

/*
**	Structures
*/

typedef	struct		s_cp
{
	double			i;
	double			r;
}					t_cp;

typedef	struct		s_mlximg
{
	void			*img_ptr;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_mlximg;

typedef	struct		s_manda
{
	double			ym;
	double			xm;
	int				j;
	int				color;
	double			imax;
	double			zoom;
	double			xmin;
	double			ymin;

}					t_manda;

typedef	struct		s_val
{
	double			y;
	double			x;
	double			i;
	double 			tmp;
	t_cp			z;
	t_cp			c;
}					t_val;

typedef struct s_fract t_fract;

typedef struct		s_thread
{
	int				id;
	t_fract			*fract;
}					t_thread;

struct				s_fract
{
	pthread_t		thread[THREADNBR];
	t_thread		thbase[THREADNBR];
	int				fct;
	t_manda			*mna;
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlximg		*img;
};


/*
**	Functions
*/

void		ft_mandelbrot(t_thread *t);
void		ft_tricorn(t_thread *tmp);
void		ft_burningship(t_thread *tmp);
void		ft_julia(t_thread *tmp);

/*
**	img.c
*/

int			ft_imgdel(t_fract *fract);
t_fract		*ft_infract(t_fract *fract);
int			ft_inimg(t_fract *fract);
int			ft_init(char *title, t_fract *fract);

/*
**	main.c
*/

int			ft_expose(t_fract *fract);
void		ft_initval(t_fract *fract);

/*
**	colors.c
*/

int			ft_colorpx(t_fract *fract, t_val val);
void		ft_pixel(unsigned int *data, int x, int y, unsigned int color);

/*
**	event.c
*/

int 		ft_exit(t_fract *fract);
int			ft_scroll(int s, int x, int y, t_fract *fract);
int			ft_mouse(int x, int y, t_fract *fract);
int			ft_key(int key, t_fract *fract);
int			ft_movearrow(int key, t_fract *fract);

/*
**	thread.c
*/

int			ft_thread(t_fract *fract);

#endif
