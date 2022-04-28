#include "base-types.hpp"


akrami::point_t akrami::operator+(point_t const& left, point_t const& right)
{
	return point_t{ left.x + right.x, left.y + right.y };
}

akrami::point_t akrami::operator-(point_t const& left, point_t const& right)
{
	return point_t{ left.x - right.x, left.y - right.y };
}

akrami::point_t akrami::operator/(point_t const& left, double num)
{
	return point_t{ left.x / num, left.y / num };
}

akrami::point_t akrami::operator*(point_t const& left, double num)
{
	return point_t{ left.x * num, left.y * num };
}