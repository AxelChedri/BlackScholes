#include "Asian.h"
#include <iostream>

AsianArithmeticCall::AsianArithmeticCall()
{
	this->setStrike(100);
	this->setMaturity(1);
}

AsianArithmeticCall::AsianArithmeticCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianArithmeticCall::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0;
	for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
		mean += prices_vector[i];
	}
	mean /= static_cast<double>(prices_vector.size());

	if ((mean - this->getStrike()) > 0)
		return mean - this->getStrike();
	return 0.0;
}

void AsianArithmeticCall::print() const
{
	std::cout << "-- Asian Arithmethic Call --" << std::endl;
	PathDependentOption::print();
}

AsianArithmeticCall::~AsianArithmeticCall()
{
}

AsianArithmeticPut::AsianArithmeticPut()
{
	this->setStrike(100);
	this->setMaturity(1);
}

AsianArithmeticPut::AsianArithmeticPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianArithmeticPut::payoff(std::vector<double> const& prices_vector) const
{
	double mean = 0;
	for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
		mean += prices_vector[i];
	}
	mean /= static_cast<double>(prices_vector.size());

	if ((this->getStrike()) - mean > 0)
		return this->getStrike() - mean;
	return 0.0;
}

void AsianArithmeticPut::print() const
{
	std::cout << "-- Asian Arithmethic Put --" << std::endl;
	PathDependentOption::print();
}

AsianArithmeticPut::~AsianArithmeticPut()
{
}

AsianGeometricCall::AsianGeometricCall()
{
	this->setStrike(100);
	this->setMaturity(1);
}

AsianGeometricCall::AsianGeometricCall(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianGeometricCall::payoff(std::vector<double> const& prices_vector) const
{
	double geometric_mean = 0;
	for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
		geometric_mean += log(prices_vector[i]);
	}
	geometric_mean = exp(geometric_mean / static_cast<double>(prices_vector.size()));

	if ((geometric_mean - this->getStrike()) > 0)
		return geometric_mean - this->getStrike();
	return 0.0;
}

void AsianGeometricCall::print() const
{
	std::cout << "-- Asian Arithmethic Call --" << std::endl;
	PathDependentOption::print();
}

AsianGeometricCall::~AsianGeometricCall()
{
}

AsianGeometricPut::AsianGeometricPut()
{
	this->setStrike(100);
	this->setMaturity(1);
}

AsianGeometricPut::AsianGeometricPut(double const& K, double const& T)
{
	this->setStrike(K);
	this->setMaturity(T);
}

double AsianGeometricPut::payoff(std::vector<double> const& prices_vector) const
{
	double geometric_mean = 0;
	for (int i = 0; i < static_cast<int>(prices_vector.size()); i++) {
		geometric_mean += log(prices_vector[i]);
	}
	geometric_mean = exp(geometric_mean / static_cast<double>(prices_vector.size()));

	if ((this->getStrike()) - geometric_mean > 0)
		return this->getStrike() - geometric_mean;
	return 0.0;
}

void AsianGeometricPut::print() const
{
	std::cout << "-- Asian Arithmethic Put --" << std::endl;
	PathDependentOption::print();
}

AsianGeometricPut::~AsianGeometricPut()
{
}
