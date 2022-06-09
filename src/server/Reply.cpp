/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:52:44 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 19:09:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Reply.hpp"

void	Server::reply(const std::string &code, Client &c, Client &dst, const std::vector<std::string> &av)
{
	int	tmp = atoi(code.c_str());
	if (tmp <= 0 || tmp > 502)
		return (debug("SERVER", "you dumbass, you use an illegal reply number"));

	if (DEBUG)
		std::cerr << s_debug("REPLY", "") << ANSI::reply << '(' << code << ") "
			<< ANSI::reset << ANSI::red << c << ANSI::reset << std::endl;

	std::string	to;
	if (c.get_status() == ONLINE)
		to = c.get_nickname();
	else
		to = "*";
	c.write_to(dst, code + " " + to + Server::get_custom_reply(code, av));
}

void	Server::reply(const std::string &code, Client &c, const std::vector<std::string> &av)
{
	Server::reply(code, c, c, av);
}

void	Server::reply(const std::string &code, Client &c)
{
	std::vector<std::string>	empty;
	Server::reply(code, c, empty);
}

const std::string	Server::get_custom_reply(const std::string &code, const std::vector<std::string> &av)
{
	if (Server::replies.find(code) == Server::replies.end())
	{
		debug("REPLY", "custom replies not found\t(" + code + ")");
		return ("");
	}

	return (std::string(" " + Server::replies[code](av)));
}

const std::string	Reply::r_RPL_WELCOME(const std::vector<std::string> &av)
{ return (std::string(":Welcome to the Internet Relay Network " + av[0])); }

const std::string	Reply::r_ERR_NEEDMOREPARAMS(const std::vector<std::string> &av)
{ return (std::string(av[0] + " :Not enough parameters")); }

const std::string	Reply::r_ERR_NOSUCHNICK(const std::vector<std::string> &av)
{ return (std::string(av[0] + " :No such nick/channel")); }

const std::string	Reply::r_ERR_NORECIPIENT(const std::vector<std::string> &av)
{ return (":No recipient given (" + std::string(av[0]) + ')'); }

const std::string	Reply::r_ERR_NOTEXTTOSEND(const std::vector<std::string> &av)
{ return (":No text to send"); (void)av; }