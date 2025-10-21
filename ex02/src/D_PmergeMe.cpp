/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_PmergeMe.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:28:21 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/21 09:48:08 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

long	jacobsthalGenerator(long n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	long	prev = 0, curr = 1;
	for (long i = 2; i <= n; i++)
	{
		long	next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return (curr);	
}

std::string PmergeMe::strDeque() const
{
	std::string result;
	for (std::deque<int>::const_iterator it = _Deq.begin(); it != _Deq.end(); ++it)
	{
		result += std::to_string(*it) + " ";
	}
	return result;
}

size_t	PmergeMe::getDequeSize(void) const
{
	return (this->_Deq.size());
}

void	PmergeMe::fordJohnsonSortDeque(int unitSize)
{
	int			numOfUnits = _Deq.size() / unitSize;
	if (numOfUnits < 2)
		return ;
	
	bool	hasStraggler = numOfUnits % 2 == 1;

	std::deque<int>::iterator	start = _Deq.begin();
	std::deque<int>::iterator	end = advanceIter(_Deq.begin(), numOfUnits * unitSize - (hasStraggler * unitSize));

	for (std::deque<int>::iterator it = start; it != end; std::advance(it, 2 * unitSize))
	{
		std::deque<int>::iterator	firstUnit = advanceIter(it, unitSize - 1);
		std::deque<int>::iterator	secondUnit = advanceIter(it, unitSize * 2 - 1);
		numOfComparisons++;
		if (*firstUnit > *secondUnit)
			swapUnits(firstUnit, unitSize);
	}
	fordJohnsonSortDeque(unitSize * 2);

	std::deque<std::deque<int>::iterator>	main;
	std::deque<std::deque<int>::iterator>	pend;
	main.insert(main.end(), advanceIter(_Deq.begin(), unitSize - 1));
	main.insert(main.end(), advanceIter(_Deq.begin(), (unitSize * 2) - 1));
	for (int i = 4; i <= numOfUnits; i += 2)
	{
		pend.insert(pend.end(), advanceIter(_Deq.begin(), unitSize * (i - 1) - 1));
		main.insert(main.end(), advanceIter(_Deq.begin(), unitSize * i - 1));
	}

	if (hasStraggler)
	{
		pend.insert(pend.end(), advanceIter(_Deq.begin(), unitSize * numOfUnits - 1));
	}

	long	prevJacobsthal = jacobsthalGenerator(2);
	int		insertedNums = 0;
	for (int k = 3;; k++)
	{
		long	currJacobsthal = jacobsthalGenerator(k);
		long	jacobsthalDiff = currJacobsthal - prevJacobsthal;
		int		offset = 0;
		if (jacobsthalDiff > static_cast<long>(pend.size()))
			break ;
		long	numOfUnitInsertions = jacobsthalDiff;

		std::deque<std::deque<int>::iterator>::iterator	pendIt = pend.begin() + jacobsthalDiff - 1;
		long int	boundIndex = currJacobsthal + insertedNums;
		while (numOfUnitInsertions--)
		{
			std::deque<std::deque<int>::iterator>::iterator boundIt = main.begin() + boundIndex - offset;
			std::deque<std::deque<int>::iterator>::iterator idx = std::upper_bound(main.begin(), boundIt, *pendIt, compare<std::deque<int>::iterator>);
			std::deque<std::deque<int>::iterator>::iterator inserted = main.insert(idx, *pendIt);
			pendIt = pend.erase(pendIt);
			if (pendIt != pend.begin())
				pendIt--;
			offset += ((inserted - main.begin()) == boundIndex);
		}
		prevJacobsthal = currJacobsthal;
		insertedNums += jacobsthalDiff;
		offset = 0;
	}

	for (long unsigned int i = 0; i < pend.size(); i++)
	{
		std::deque<std::deque<int>::iterator>::iterator	currPend = pend.begin() + i;
		std::deque<std::deque<int>::iterator>::iterator	currBound = advanceIter(main.begin(), main.size() - pend.size() + i + hasStraggler);
		std::deque<std::deque<int>::iterator>::iterator	idx = std::upper_bound(main.begin(), currBound, *currPend, compare<std::deque<int>::iterator>);
		main.insert(idx, *currPend);
	}

	std::deque<int>	copy;
	for (std::deque<std::deque<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < unitSize; i++)
		{
			std::deque<int>::iterator	unitStart = *it;
			std::advance(unitStart, -unitSize + i + 1);
			copy.insert(copy.end(), *unitStart);
		}
	}

	std::deque<int>::iterator containerIt = _Deq.begin();
	std::deque<int>::iterator copyIt = copy.begin();
	while (copyIt != copy.end())
	{
		*containerIt = *copyIt;
		containerIt++;
		copyIt++;
	}
}
