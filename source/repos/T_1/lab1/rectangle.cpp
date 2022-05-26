#include <cmath>
#include "rectangle.hpp"
#include <iostream>
#include <string>

akrami::Rectangle::Rectangle(const point_t& pos1, const point_t& pos2) :
	posFirst_(pos1),
	posSecond_(pos2)
{
	if (pos2.x < pos1.x || pos2.y < pos1.y)
	{
		throw std::logic_error("Rectangle edges must be placed correctly.");
	}
}

double akrami::Rectangle::getArea() const
{
	return (abs(posFirst_.x - posSecond_.x) * abs(posFirst_.y - posSecond_.y));
}

akrami::rectangle_t akrami::Rectangle::getFrameRect() const
{
	return rectangle_t
	{
		((posFirst_ + posSecond_) / 2),
		abs(posFirst_.x - posSecond_.x),
		abs(posFirst_.y - posSecond_.y)
	};
}

void akrami::Rectangle::move(const point_t& pos)
{
	point_t delta = pos - ((posFirst_ + posSecond_) / 2);
	posFirst_ = posFirst_ + delta;
	posSecond_ = posSecond_ + delta;
}

void akrami::Rectangle::move(double dx, double dy)
{
	posFirst_.x += dx;
	posSecond_.x += dx;

	posFirst_.y += dy;
	posSecond_.y += dy;
}

void akrami::Rectangle::scale(double k)
{
	if (k < 0)
	{
		throw std::logic_error("Coefficient cannot be negative");
	}
	point_t center = getFrameRect().pos;
	posFirst_ = posFirst_ + (posFirst_ - center) * k / 2;
	posSecond_ = posSecond_ + (posSecond_ - center) * k / 2;
}

