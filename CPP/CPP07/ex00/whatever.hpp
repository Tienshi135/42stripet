/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tienshi <tienshi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:19:07 by tienshi           #+#    #+#             */
/*   Updated: 2025/09/13 19:27:43 by tienshi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


template	<typename T>
void	swap(T &a, T &b) {
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template	<typename T>
T	min(const T &a, const T &b) {
	return (a < b ? a : b);
}

template	<typename T>
T	max(const T &a, const T &b) {
	return (a > b ? a : b);
}