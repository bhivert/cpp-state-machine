/*
* main.cpp is part of a project.
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
* Created on 2019/04/27 at 11:04:23 by  <hivert.benoit@gmail.com>
* Updated on 2019/04/28 at 02:58:49 by  <hivert.benoit@gmail.com>
*/

/*!
  @file main.cpp
  @brief ...
  */

# include "test_states_machine.hpp"
# include <iostream>

int		main() {
	test_states_machine.reset();;
	test_states_machine.start();;
	while (!test_states_machine.isStoped()) {
		test_states_machine.executeNextState();
		std::cout << test_states_machine << std::endl;
	}
	return 0;
}

