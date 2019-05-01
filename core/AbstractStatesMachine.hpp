/*
* AbstractStatesMachine.hpp is part of a project.
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
* Created on 2019/04/27 at 09:32:29 by  <hivert.benoit@gmail.com>
* Updated on 2019/05/01 at 16:16:52 by  <hivert.benoit@gmail.com>
*/

/*!
  @file AbstractStatesMachine.hpp
  @brief ...
  */

#ifndef ABSTRACTSTATESMACHINE_HPP
# define ABSTRACTSTATESMACHINE_HPP

# include <vector>
# include <ostream>
# include <string>

# include "StateInterface.hpp"

template < typename E >
class AbstractStatesMachine {
	public:
		enum class	status_type : unsigned char {
			STOPED = 0,
			RUNNING,
			ERROR
		};

		enum class	error_type : unsigned char {
			NO_ERR = 0,
			UNKNOW,
			UNKNOW_STATE
		};

		virtual					~AbstractStatesMachine(void) {
			for (typename std::vector< StateInterface < E > * >::iterator it = m_states_pool.begin(); it != m_states_pool.end(); ++it) {
				delete *it;
			}
		};

		status_type				getStatus(void) const {
			return m_status;
		};

		E						getActiveState(void) const {
			return m_active_state;
		};

		E						getNextState(void) const {
			return m_next_state;
		};

		error_type				setNextState(E next_state) {
			m_next_state = next_state;
			return error_type::NO_ERR;
		};

		error_type				reset(void) {
			m_status = status_type::STOPED;
			m_active_state = (E)0;
			m_next_state = (E)0;
			return error_type::NO_ERR;
		};

		error_type				start(void) {
			if (m_status == status_type::ERROR)
				return error_type::UNKNOW;
			m_status = status_type::RUNNING;
			return error_type::NO_ERR;
		};

		error_type				stop(void) {
			if (m_status == status_type::ERROR)
				return error_type::UNKNOW;
			m_status = status_type::STOPED;
			return error_type::NO_ERR;
		};

		bool					isStoped(void) const {
			return m_status == status_type::STOPED || m_status == status_type::ERROR;
		};

	protected:
		AbstractStatesMachine(const std::vector< StateInterface < E > * > &states_pool) \
			: m_status(status_type::STOPED), m_active_state(static_cast< E >(0)), m_next_state(static_cast< E >(0)), m_states_pool(states_pool) {
		};

		error_type				executeNextState(void) try {
			if (m_status == status_type::RUNNING) {
				StateInterface< E > *tmp(m_states_pool.at(static_cast<typename std::vector< StateInterface < E > * >::size_type>(m_next_state)));
				m_active_state = m_next_state;
				(*tmp)(*this);
				return error_type::NO_ERR;
			} else {
				return error_type::UNKNOW;
			}
		} catch (const std::out_of_range &e) {
			m_status = status_type::ERROR;
			return error_type::UNKNOW_STATE;
		} catch (...) {
			m_status = status_type::ERROR;
			return error_type::UNKNOW;
		};

	private:
		status_type								m_status;
		E										m_active_state;
		E										m_next_state;

		std::vector< StateInterface< E > * >	m_states_pool;

		AbstractStatesMachine(void) = delete;
		AbstractStatesMachine(AbstractStatesMachine const & src) = delete;
		AbstractStatesMachine &	operator=(AbstractStatesMachine const & src) = delete;
};

template < typename E >
std::ostream &	operator<<(std::ostream & o, AbstractStatesMachine< E > const & C) {
	o << "status [" << std::to_string(static_cast<typename std::vector< StateInterface< E > >::size_type>(C.getStatus())) \
		<< "] active_state [" << std::to_string(static_cast<typename std::vector< StateInterface< E > >::size_type>(C.getActiveState())) \
		<< "] next_state [" << std::to_string(static_cast<typename std::vector< StateInterface< E > >::size_type>(C.getNextState())) << ']';
	return o;
};

#endif
