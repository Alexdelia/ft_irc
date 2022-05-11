/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:29:35 by adelille          #+#    #+#             */
/*   Updated: 2022/05/11 14:22:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "../utils/utils.hpp"
// config	// map(string key, string val)
# include "Config.hpp"
# include "../client/Client.hpp"
# include "../cmd/map_cmd.hpp"

# include <map>
# include <string>
# include <vector>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netinet/ip.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <poll.h>

# include <unistd.h> // (debug) for sleep()

class Client;

class Server
{
	public:
		Server(const std::string &port, const std::string &password);
		~Server();

		void	process(void);

		// channel
	
		Config					&get_config(void);
		int						get_start_time(void) const;
		std::vector<Client *>	get_clients(void);
	
	private:
		Config						_config;
		std::map<int, Client *>		_clients;	// list of clients with index
											// don't use vector because might have hole in index
		std::vector<pollfd>			_pfds;
		int							_start_time;
		int							_last_ping;
		// channel
		
		Server();
		Server(const Server &src);
		Server	&operator=(const Server &src);

		void	_accept_client(void);
		void	_ping(void);
		void	_delete_client(Client &client);
		void	_init_m_cmd(void);
		void	_handle_client_status(void);


		// display (client/channel)
};

#endif
