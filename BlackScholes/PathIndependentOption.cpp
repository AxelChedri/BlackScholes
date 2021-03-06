#include "PathIndependentOption.h"
#include <iostream>

PathIndependentOption::PathIndependentOption()
{
	this->K = 100;
	this->T = 1;
}

PathIndependentOption::PathIndependentOption(double const& K, double const& T)
{
	this->K = K;
	this->T = T;
}

void PathIndependentOption::setStrike(double const& K)
{
	this->K = K;
}

void PathIndependentOption::setMaturity(double const& T)
{
	this->T = T;
}

void PathIndependentOption::setMultiplier(double const& multiplier)
{
	this->multiplier = multiplier;
}

double PathIndependentOption::getStrike() const
{
	return K;
}

double PathIndependentOption::getMaturity() const
{
	return T;
}

double PathIndependentOption::getMultiplier() const
{
	return multiplier;
}

double PathIndependentOption::payoff(double const& S) const
{
	return 0.0;
}

double PathIndependentOption::payoff(std::vector<double> prices_vector) const
{
	return 0.0;
}

PathIndependentOption::~PathIndependentOption()
{
}

void PathIndependentOption::print() const
{
	std::cout << "Strike K : " << K << std::endl;
	std::cout << "Maturity T : " << T << " (in years)" << std::endl;
	if (multiplier != 1.0)
		std::cout << "Multiplier : " << multiplier << std::endl;

}
