/*
* StateInterface.hpp is part of a project.
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
* Created on 2019/04/27 at 10:34:16 by  <hivert.benoit@gmail.com>
* Updated on 2019/04/28 at 02:11:14 by  <hivert.benoit@gmail.com>
*/

/*!
  @file StateInterface.hpp
  @brief ...
  */

#ifndef STATEINTERFACE_HPP
# define STATEINTERFACE_HPP

# include <ostream>
# include <vector>
# include <iostream>

template < typename E >
class AbstractStatesMachine;

template < typename E >
class StateInterface {
	public:
		StateInterface(void) {};

		virtual void	operator()(AbstractStatesMachine< E >&) = 0;
};

template < typename E >
std::ostream &	operator<<(std::ostream & o, StateInterface< E > const & C);

#endif
