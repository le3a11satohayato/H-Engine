#pragma once
#include<cmath>
#include"HHelper.h"

namespace HEase
{
	float OutQuart(float x) {
		return 1 - pow(1 - x, 4);
	}

	float OutQuint(float x) {
		return 1 - pow(1 - x, 5);
	}

	float OutCirc(float x) {
		return sqrtf(1 - pow(x - 1, 2));
	}

	float OutBack(float x) {
		const float c1 = 1.70158;
		const float c3 = c1 + 1;
		return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
	}

	float OutElastic(float x) {
		const float c4 = (2 * HHelper::H_PI_F) / 3;

		return x == 0
			? 0
			: x == 1
			? 1
			: pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
	}

	float OutBounce(float x) {
		const float n1 = 7.5625;
		const float d1 = 2.75;

		if (x < 1 / d1) {

			return n1 * x * x;
		}
		else if (x < 2 / d1) {
			return n1 * (x -= 1.5 / d1) * x + 0.75;
		}
		else if (x < 2.5 / d1) {

			return n1 * (x -= 2.25 / d1) * x + 0.9375;
		}
		else {
			return n1 * (x -= 2.625 / d1) * x + 0.984375;
		}
	}
}