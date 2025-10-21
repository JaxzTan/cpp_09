/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   V_PmergeMe.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 22:29:02 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/21 09:50:47 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

std::string PmergeMe::strVec() const
{
	std::string result;
	for (std::vector<int>::const_iterator it = _Vec.begin(); it != _Vec.end(); ++it)
	{
		result += std::to_string(*it) + " ";
	}
	return result;
}

size_t	PmergeMe::getVectorSize(void) const
{
	return (this->_Vec.size());
}

void	PmergeMe::fordJohnsonSortVector(int unitSize)
{
	int			numOfUnits = _Vec.size() / unitSize;
	if (numOfUnits < 2)
		return ;
	
	bool	hasStraggler = numOfUnits % 2 == 1;

	std::vector<int>::iterator	start = _Vec.begin();
	std::vector<int>::iterator	end = advanceIter(_Vec.begin(), numOfUnits * unitSize - (hasStraggler * unitSize)); //

	for (std::vector<int>::iterator it = start; it != end; std::advance(it, 2 * unitSize))
	{
		std::vector<int>::iterator	firstUnit = advanceIter(it, unitSize - 1);
		std::vector<int>::iterator	secondUnit = advanceIter(it, unitSize * 2 - 1);
		numOfComparisons++;
		if (*firstUnit > *secondUnit)
			swapUnits(firstUnit, unitSize);
	}
	fordJohnsonSortVector(unitSize * 2);

	std::vector< std::vector<int>::iterator>	main;
	std::vector< std::vector<int>::iterator>	pend;
	main.insert(main.end(), advanceIter(_Vec.begin(), unitSize - 1));
	main.insert(main.end(), advanceIter(_Vec.begin(), (unitSize * 2) - 1));
	for (int i = 4; i <= numOfUnits; i += 2)
	{
		pend.insert(pend.end(), advanceIter(_Vec.begin(), unitSize * (i - 1) - 1));
		main.insert(main.end(), advanceIter(_Vec.begin(), unitSize * i - 1));
	}

	if (hasStraggler)
		pend.insert(pend.end(), advanceIter(_Vec.begin(), unitSize * numOfUnits - 1));

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

		std::vector< std::vector<int>::iterator>::iterator	pendIt = pend.begin() + jacobsthalDiff - 1;
		long int	boundIndex = currJacobsthal + insertedNums;
		while (numOfUnitInsertions--)
		{
			std::vector< std::vector<int>::iterator>::iterator boundIt = main.begin() + boundIndex - offset;
			std::vector< std::vector<int>::iterator>::iterator idx = std::upper_bound(main.begin(), boundIt, *pendIt, compare<std::vector<int>::iterator>);
			std::vector< std::vector<int>::iterator>::iterator inserted = main.insert(idx, *pendIt);
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
		std::vector< std::vector<int>::iterator>::iterator	currPend = pend.begin() + i;
		std::vector< std::vector<int>::iterator>::iterator	currBound = advanceIter(main.begin(), main.size() - pend.size() + i + hasStraggler);
		std::vector< std::vector<int>::iterator>::iterator	idx = std::upper_bound(main.begin(), currBound, *currPend, compare<std::vector<int>::iterator>);
		main.insert(idx, *currPend);
	}

	std::vector<int>	copy;
	copy.reserve(_Vec.size());
	for (std::vector< std::vector<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (int i = 0; i < unitSize; i++)
		{
			std::vector<int>::iterator	unitStart = *it;
			std::advance(unitStart, -unitSize + i + 1);
			copy.insert(copy.end(), *unitStart);
		}
	}

	std::vector<int>::iterator containerIt = _Vec.begin();
	std::vector<int>::iterator copyIt = copy.begin();
	while (copyIt != copy.end())
	{
		*containerIt = *copyIt;
		containerIt++;
		copyIt++;
	}
}
