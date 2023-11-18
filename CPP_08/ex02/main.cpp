/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <fbecht@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:12:04 by fbecht            #+#    #+#             */
/*   Updated: 2023/09/14 17:12:05 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int>	mstack;
	std::list<int>		lstack;

	mstack.push(5);
	mstack.push(17);
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "mstack.top()=" << mstack.top() << " || lstack.back()=" << lstack.back() << std::endl;
	mstack.pop();
	lstack.pop_back();
	std::cout << "mstack.size()=" << mstack.size() << " || lstack.size()=" << lstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);
	
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	std::list<int>::iterator	itl = lstack.begin();
	std::list<int>::iterator	itle = lstack.end();
	++it;
	--it;
	++itl;
	--itl;
	std::cout << "mstack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "lstack:" << std::endl;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	
	std::cout << "Copying mstack to std::stack<int>" << std::endl;
	std::stack<int> s(mstack);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	
	return 0;
}
