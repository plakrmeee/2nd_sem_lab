#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace akrami {
	struct point_t
	{
		double x;
		double y;
	};

	struct rectangle_t
	{
		point_t pos;
		double width;
		double height;
	};

	point_t operator+(point_t const& left, point_t const& right);
	point_t operator-(point_t const& left, point_t const& right);
	point_t operator/(point_t const& left, double num);
	point_t operator*(point_t const& left, double num);
}


#endif