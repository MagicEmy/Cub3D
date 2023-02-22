/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlicame <emlicame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:15:05 by emlicame          #+#    #+#             */
/*   Updated: 2023/02/21 12:15:58 by emlicame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define C_RESET	"\x1b[0m"

# define C_LRED		"\x1b[38;2;255;128;128m"
# define C_RED		"\x1b[38;2;255;0;0m"
# define C_DRED		"\x1b[38;2;128;0;0m"
# define C_LORANGE	"\x1b[38;2;255;192;128m"
# define C_ORANGE	"\x1b[38;2;255;128;0m"
# define C_DORANGE	"\x1b[38;2;128;64;0m"
# define C_LYELLOW	"\x1b[38;2;255;255;128m"
# define C_YELLOW	"\x1b[38;2;255;255;0m"
# define C_DYELLOW	"\x1b[38;2;128;128;0m"
# define C_LCHRT	"\x1b[38;2;192;255;128m"
# define C_CHRT		"\x1b[38;2;128;255;0m"	//chartreuse
# define C_DCHRT	"\x1b[38;2;64;128;0m"
# define C_LGREEN	"\x1b[38;2;128;255;128m"
# define C_GREEN	"\x1b[38;2;0;255;0m"
# define C_DGREEN	"\x1b[38;2;0;128;0m"
# define C_LSPRGR	"\x1b[38;2;128;255;192m"
# define C_SPRGR	"\x1b[38;2;0;255;128m"	//spring green
# define C_DSPRGR	"\x1b[38;2;0;128;64m"
# define C_LCYAN	"\x1b[38;2;128;255;255m"
# define C_CYAN		"\x1b[38;2;0;255;255m"
# define C_DCYAN	"\x1b[38;2;0;128;128m"
# define C_LAZURE	"\x1b[38;2;0;192;255m"
# define C_AZURE	"\x1b[38;2;0;128;255m"
# define C_DAZURE	"\x1b[38;2;0;64;128m"
# define C_LBLUE	"\x1b[38;2;128;128;255m"
# define C_BLUE		"\x1b[38;2;0;0;255m"
# define C_DBLUE	"\x1b[38;2;0;0;128m"
# define C_LVIOLET	"\x1b[38;2;192;0;255m"
# define C_VIOLET	"\x1b[38;2;128;0;255m"
# define C_DVIOLET	"\x1b[38;2;64;0;255m"
# define C_LMGNT	"\x1b[38;2;255;128;255m"
# define C_MGNT		"\x1b[38;2;255;0;255m"	//magenta
# define C_DMGNT	"\x1b[38;2;128;0;128m"
# define C_1UP_DEL	"\033[F\x1b[0J"

#endif