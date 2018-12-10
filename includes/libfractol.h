/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalombo <dpalombo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:20:26 by dpalombo          #+#    #+#             */
/*   Updated: 2018/12/09 11:53:53 by dpalombo         ###   ########.fr       */
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
# define DEFAULTC		0xFFFFFF
# define JNBR			5
# define MNBR			10
# define BNBR			11
# define THREADSTORE	4

/*
**	Keyboard and Colors
*/

# define ESC_KEY		53
# define UP_KEY			126
# define DOWN_KEY		125
# define RIGHT_KEY		124
# define LEFT_KEY		123
# define MORE_KEY		69
# define LESS_KEY		78
# define C_COLOR		8
# define R_ROTATE		15
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
	double			x;
	double			y;
	double			ym;
	double			xm;
	double			xi;
	double			yi;
	double			color;
	double			imax;
	double			zoom;
}					t_manda;

typedef	struct		s_val
{
	double				y;
	double				x;
	double				i;
	double				xl;
	double				xr;
	double				yt;
	double				yb;
	t_cp				z;
	t_cp				c;
}					t_val;

typedef	struct		s_fract
{
	int				fct;
	t_manda			*mna;
	t_val			*val;
	void			*mlx_ptr;
	void			*win_ptr;
	t_mlximg		*img;
}					t_fract;


/*
**	Functions
*/

int ft_key(int key, t_fract *fract);
int ft_mouse(int x, int y, t_fract *fract);
int ft_exit(t_fract *fract);
int	ft_burningship(t_fract *fract);
int	ft_inimg(t_fract *fract);
int	ft_imgdel(t_fract *fract);
int	ft_julia(t_fract *fract);
int	ft_findft(t_fract *fract);
int	ft_mandelbrot(t_fract *fract);
void	ft_pixel(unsigned int *data, int x, int y, unsigned int color);
int		ft_init(char *title, t_fract *fract);
int		ft_imgdel(t_fract *fract);
t_fract		*ft_infract(t_fract *fract);
int		ft_inimg(t_fract *fract);
int		ft_init(char *title, t_fract *fract);







#endif
