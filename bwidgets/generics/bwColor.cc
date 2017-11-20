#include <cassert>
#include <math.h>

#include "bwColor.h"


using namespace bWidgets;

bwColor::bwColor(
        float red,
        float green,
        float blue,
        float alpha)
{
	setColor(red, green, blue, alpha);
}
bwColor::bwColor(
        float rgb,
        float alpha)
{
	setColor(rgb, alpha);
}
bwColor::bwColor(
        unsigned int red,
        unsigned int green,
        unsigned int blue,
        unsigned int alpha)
{
	assert(red < 256);
	assert(green < 256);
	assert(blue < 256);
	assert(alpha < 256);

	setColor(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
}
bwColor::bwColor(
        unsigned int rgb,
        unsigned int alpha)
{
	assert(rgb < 256);
	assert(alpha < 256);

	setColor(rgb / 255.0f, alpha / 255.0f);
}

bwColor::bwColor()
{
	setColor(0.0f);
}

bwColor& bwColor::shade(const float rgb_shade, float alpha_shade)
{
	for (int i = 0; i < 3; i++) {
		rgba[i] = fmin(rgba[i] + rgb_shade, 1.0);
	}
	rgba[3] = fmin(rgba[3] + alpha_shade, 1.0);

	return *this;
}

void bwColor::setColor(float red, float green, float blue, float alpha)
{
	const float rgba[4] = {red, green, blue, alpha};
	setColor(rgba);
}

void bwColor::setColor(float rgb, float alpha)
{
	const float rgba[4] = {rgb, rgb, rgb, alpha};
	setColor(rgba);
}

void bwColor::setColor(const float _rgba[4])
{
	rgba[0] = _rgba[0];
	rgba[1] = _rgba[1];
	rgba[2] = _rgba[2];
	rgba[3] = _rgba[3];
}

const float* bwColor::getColor() const
{
	return rgba;
}

void bwColor::operator=(const float rgb)
{
	setColor(rgb);
}

bool bwColor::operator==(const bwColor& compare_color) const
{
	return ((rgba[0] == compare_color[0]) &&
	        (rgba[1] == compare_color[1]) &&
	        (rgba[2] == compare_color[2]) &&
	        (rgba[3] == compare_color[3]));
}

float& bwColor::operator[](unsigned int index)
{
	return rgba[index];
}

bwColor::operator const float*() const
{
	return rgba;
}
