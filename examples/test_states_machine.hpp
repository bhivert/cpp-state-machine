/*
* state_machine_example.hpp is part of a project.
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
* Created on 2019/04/28 at 02:54:39 by  <hivert.benoit@gmail.com>
* Updated on 2019/04/28 at 02:59:35 by  <hivert.benoit@gmail.com>
*/

/*!
  @file test_states_machine.hpp
  @brief ...
  */

#ifndef TEST_STATES_MACHINE_HPP
# define TEST_STATES_MACHINE_HPP

# include "../StatesMachine.hpp"

typedef enum class _test_conf : unsigned char {
	_0 = 0,
	_1,
	_2,
}				test_conf;

# include "./state_0.hpp"
# include "./state_1.hpp"
# include "./state_2.hpp"

static const std::vector< StateInterface < test_conf > * >	g_test_states({
	new State_0(),
	new State_1(),
	new State_2()
});

StatesMachine < test_conf >							test_states_machine(g_test_states);

#endif
