/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfarouk <zfarouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 22:07:44 by zfarouk           #+#    #+#             */
/*   Updated: 2026/02/12 22:15:41 by zfarouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

template <typename T>
void print(T &x) { std::cout << x << std::endl; }

template <typename T>
void addOne(T &x) { x += 1; }

int main() {
    int arr[3] = {1,2,3};
    const int c_arr[3] = {4,5,6};

    iter(arr, 3, print<int>);
    iter(arr, 3, addOne<int>);
    iter(arr, 3, print<int>);

    iter(c_arr, 3, print<const int>);    // works for const array
    // iter(c_arr, 3, addOne<const int>); // error: cannot modify const

    return 0;
}
