/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reply.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:29:35 by adelille          #+#    #+#             */
/*   Updated: 2022/06/09 19:07:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLY_HPP
# define REPLY_HPP

# include "../utils/utils.hpp"

# include <map>
# include <string>
# include <vector>

namespace Reply
{
	const std::string	r_RPL_WELCOME(const std::vector<std::string> &av);

	const std::string	r_ERR_NOSUCHNICK(const std::vector<std::string> &av);
	const std::string	r_ERR_NEEDMOREPARAMS(const std::vector<std::string> &av);
	const std::string	r_ERR_NORECIPIENT(const std::vector<std::string> &av);
	const std::string	r_ERR_NOTEXTTOSEND(const std::vector<std::string> &av);
	
	static const std::string	RPL_WELCOME(			"001");
	static const std::string	ERR_NOSUCHNICK(			"401");
	static const std::string	ERR_NOORIGIN(			"409");
	static const std::string	ERR_NORECIPIENT(		"411");
	static const std::string	ERR_NOTEXTTOSEND(		"412");
	static const std::string	ERR_NONICKNAMEGIVEN(	"431");
	static const std::string	ERR_NICKCOLLISION(		"436");
	static const std::string	ERR_NOTREGISTERED(		"451");
	static const std::string	ERR_NEEDMOREPARAMS(		"461");
	static const std::string	ERR_ALREADYREGISTRED(	"462");
	static const std::string	ERR_PASSWDMISMATCH(		"464");
};

/*	
	static const std::string	r_RPL_WELCOME(const std::vector<std::string> &av);

	static const std::string	r_ERR_NEEDMOREPARAMS(const std::vector<std::string> &av);
*/

#endif
