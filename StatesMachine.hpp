/*
* StatesMachine.hpp is part of a project.
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
* Created on 2019/04/27 at 11:06:01 by  <hivert.benoit@gmail.com>
* Updated on 2019/05/01 at 16:16:57 by  <hivert.benoit@gmail.com>
*/

/*!
  @file StatesMachine.hpp
  @brief ...
  */

#ifndef STATESMACHINE_HPP
# define STATESMACHINE_HPP

#include "./core/AbstractStatesMachine.hpp"

template < typename E >
class StatesMachine : public AbstractStatesMachine< E > {
	public:
		typedef typename AbstractStatesMachine< E >::status_type	status_type;
		typedef typename AbstractStatesMachine< E >::error_type		error_type;

		StatesMachine(const std::vector< StateInterface < E > * > &states_pool) \
			: AbstractStatesMachine< E >(states_pool) {
		};

		error_type				executeNextState(void) {
			return AbstractStatesMachine< E >::executeNextState();
		};

	protected:
	private:
		StatesMachine(void) = delete;
		StatesMachine(StatesMachine const & src) = delete;
		StatesMachine &	operator=(StatesMachine const & src) = delete;
};

template < typename E >
std::ostream &	operator<<(std::ostream & o, StatesMachine< E > const & C) {
	o << dynamic_cast<AbstractStatesMachine< E > const &>(C);
	return o;
};
#endif
