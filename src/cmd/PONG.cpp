/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PONG.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:55:48 by adelille          #+#    #+#             */
/*   Updated: 2022/06/10 15:22:00 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cmd.hpp"
# include "../client/Client.hpp"
# include "../server/Server.hpp"

void	Cmd::PONG(const Cmd &c)
{
	if (!c.get_prefix().size()
			&& (c.get_arg().empty() || !c.get_arg()[0].size()))
		return (Server::reply(Reply::ERR_NOORIGIN, c.get_client()));

	c.get_client().set_last_ping(std::time(NULL));
}