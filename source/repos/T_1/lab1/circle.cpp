#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "circle.hpp"


akrami::Circle::Circle(const point_t& pos, double radius) :
	pos_(pos),
	radius_(radius)
{
	if (radius <= 0)
	{
		throw std::logic_error("Radius cannot be negative");
	}
}

double akrami::Circle::getArea() const
{
	return M_PI * radius_ * radius_;
}

akrami::rectangle_t akrami::Circle::getFrameRect() const
{
	return rectangle_t{ pos_, radius_ * 2 , radius_ * 2 };
}

void akrami::Circle::move(const point_t& pos)
{
	pos_ = pos;
}

void akrami::Circle::move(double dx, double dy)
{
	pos_.x += dx;
	pos_.y += dy;
}

void akrami::Circle::scale(double k)
{
	if (k < 0)
	{
		throw std::logic_error("Coefficient cannot be negative");
	}
	point_t center = getFrameRect().pos;
	radius_ *= k;
	pos_ = pos_ + (pos_ - center) * k;
}

