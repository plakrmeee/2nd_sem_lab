#include "complexquad.hpp"
#include <cmath>
#include <iostream>

akrami::Complexquad::Complexquad(const point_t& pos1, const point_t& pos2, const point_t& pos3, const point_t& pos4) :
	posFirst_(pos1),
	posSecond_(pos2),
	posThird_(pos3),
	posFourth_(pos4)
{
	if (pos1.y > pos2.y || pos3.y < pos4.y || pos3.x > pos2.x || pos1.x > pos4.x)
	{
		throw std::logic_error("The complexquad is not built correctly.");
	}
}

double akrami::Complexquad::getArea() const
{
	double COEFFICIENT = 0.5;

	double firstTriangleSide_1 = (posThird_.x - getFrameRect().pos.x) * (posFirst_.y - getFrameRect().pos.y);
	double secondTriangleSide_1 = (posFirst_.x - getFrameRect().pos.x) * (posThird_.y - getFrameRect().pos.y);

	double firstTriangleSide_2 = (posSecond_.x - getFrameRect().pos.x) * (posFourth_.y - getFrameRect().pos.y);
	double secondTriangleSide_2 = (posFourth_.x - getFrameRect().pos.x) * (posSecond_.y - getFrameRect().pos.y);


	double firstTriangle = COEFFICIENT * (firstTriangleSide_1 - secondTriangleSide_1);
	double secondTriangle = COEFFICIENT * (firstTriangleSide_2 - secondTriangleSide_2);

	return (abs(firstTriangle) + abs(secondTriangle));
}

akrami::rectangle_t akrami::Complexquad::getFrameRect() const
{
	double sideHeight_1 = abs(posFirst_.y - posThird_.y);
	double sideHeight_2 = abs(posSecond_.y - posFourth_.y);

	double sideWidth_1 = abs(posFirst_.x - posFourth_.x);
	double sideWidth_2 = abs(posThird_.x - posSecond_.x);

	return rectangle_t
	{
		((posFirst_ + posSecond_ + posThird_ + posFourth_) / 4),
		(sideWidth_1 > sideWidth_2 ? sideWidth_1 : sideWidth_2),
		(sideHeight_1 > sideHeight_2 ? sideHeight_1 : sideHeight_2)
	};
}

void akrami::Complexquad::move(const point_t& pos)
{
	point_t delta = pos - ((posFirst_ + posSecond_ + posThird_ + posFourth_) / 4);
	posFirst_ = posFirst_ + delta;
	posSecond_ = posSecond_ + delta;
	posThird_ = posThird_ + delta;
	posFourth_ = posFourth_ + delta;
}

void akrami::Complexquad::move(double dx, double dy)
{
	posFirst_.x += dx;
	posSecond_.x += dx;
	posThird_.x += dx;
	posFourth_.x += dx;

	posFirst_.y += dy;
	posSecond_.y += dy;
	posThird_.y += dy;
	posFourth_.y += dy;
}

void akrami::Complexquad::scale(double k)
{
	if (k < 0)
	{
		throw std::logic_error("Coefficient cannot be negative");
	}

	point_t center = getFrameRect().pos;
	posFirst_ = posFirst_ + (posFirst_ - center) * k / 2;
	posSecond_ = posSecond_ + (posSecond_ - center) * k / 2;
	posThird_ = posThird_ + (posThird_ - center) * k / 2;
	posFourth_ = posFourth_ + (posFourth_ - center) * k / 2;
}