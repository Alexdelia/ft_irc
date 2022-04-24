/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:29:35 by adelille          #+#    #+#             */
/*   Updated: 2022/04/24 12:00:59 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_HPP
# define USER_HPP

# include "utils/utils.hpp"

# include <map>
# include <string>
# include <vector>
# include <netinet/in.h>

# define DELETE		0

class Server;

class User
{
	public:
		User(const int fd, struct sockaddr_in addr);
		~User();
	
		User	&operator=(const User &src);

		// send

		void	set_status(const int status);

		int		get_fd(void) const;
		int		get_status(void) const;
	
	private:
		int		_fd;
		int		_status;

		// name
		// addr


		User();
};

#endif
