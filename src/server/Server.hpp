/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:29:35 by adelille          #+#    #+#             */
/*   Updated: 2022/05/19 12:26:08 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "../utils/utils.hpp"
# include "Config.hpp"
# include "../client/Client.hpp"
# include "../cmd/Cmd.hpp"
# include "Reply.hpp"

# include <map>
# include <string>
# include <vector>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <poll.h>

class Client;

class Server
{
	public:
		Server(const std::string &port, const std::string &password);
		~Server();

		void		process(void);

		typedef	const std::string	(*f_reply)(const std::vector<std::string> &av);
		static std::map<std::string, f_reply>	replies;
		static void					reply(const std::string &n, Client &c);
		static void					reply(const std::string &n, Client &c,
										const std::vector<std::string> &av);
		static void					reply(const std::string &n, Client &c, Client &dst,
										const std::vector<std::string> &av);
		static const std::string	get_custom_reply(const std::string &code,
										const std::vector<std::string> &av);

		// channel
	
		Config								&get_config(void);
		const int							&get_start_time(void) const;
		std::vector<Client *>				get_clients(void);
	
	private:
		Config							_config;
		std::map<int, Client *>			_clients;	// list of clients with index
											// don't use vector because might have hole in index
		std::vector<pollfd>				_pfds;
		int								_start_time;
		int								_last_ping;
		// channel
		
		Server();
		Server(const Server &src);
		Server	&operator=(const Server &src);
		
		void	_init_m_cmd(void);
		void	_init_m_reply(void);

		void	_accept_client(void);
		void	_ping(void);
		void	_delete_client(Client &client);
		void	_handle_client_status(void);

		// display (client/channel)
};

#endif
