/*
* state_1.hpp is part of a project.
* Copyright (C) 2019  <hivert.benoit@gmail.com>
*
* This project is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This project is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>
*
* Created on 2019/04/27 at 14:53:17 by  <hivert.benoit@gmail.com>
* Updated on 2019/05/01 at 16:00:54 by  <hivert.benoit@gmail.com>
*/

/*!
  @file state_1.hpp
  @brief ...
  */

#ifndef STATE_1_HPP
# define STATE_1_HPP

# include "test_conf.hpp"
# include <iostream>

class State_1 : public StateInterface< test_conf > {
	private:
		size_t	_i = 0;

	public:
		virtual void	operator()(AbstractStatesMachine< test_conf >& st) {
			std::cout << "state 1" << std::endl;
			if (++_i % 3)
				st.setNextState(test_conf::_1);
			else
				st.setNextState(test_conf::_2);
		};
};

#endif
