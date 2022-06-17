#include "utility.h"

#define _USE_MATH_DEFINES
#include <math.h>


namespace utility {

	float randomScalar(float min, float max) {

		static std::mt19937 generator(std::random_device{}());
		std::uniform_real_distribution<float> distribution{ min, max };

		return distribution(generator);

	}

	Vec3 randomInDisk(float radius) {

		while (true) {
			Vec3 random{ randomScalar(-radius, radius), randomScalar(-radius, radius), 0.0f };
			if (random.sq_length() <= radius * radius) return random;
		}

		//const float phi{ randomScalar(0.0f, 2.0f * float(M_PI)) };
		//const float length{ randomScalar(0.0f, std::abs(radius)) };

		//return length * Vec3{ std::cosf(phi), std::sinf(phi), 0.0f };

	}

	Vec3 randomInSphere(float radius) {

		while (true) {
			auto random{ Vec3::random(-radius, radius) };
			if (random.sq_length() <= radius * radius) return random;
		}

		//const float theta{ randomScalar(0.0f, float(M_PI)) }, phi{ randomScalar(0.0f, 2.0f * float(M_PI))};
		//const float length{ randomScalar(0.0f, std::abs(radius)) };

		//return length * Vec3{ std::sinf(theta) * std::cosf(phi), std::sinf(theta) * std::sinf(phi), std::cosf(theta) };

	}

	Vec3 randomOnHemisphere(const Vec3& normal) {

		auto random_unit_vec{ Vec3::normalize(randomInSphere()) };
		if (Vec3::dot(random_unit_vec, normal) > 0.0f) return random_unit_vec;
		return -random_unit_vec;

	}

	Vec3 gradientColor(const Vec3& direction, const Vec3& lower_color, const Vec3& upper_color) {

		const Vec3 normalized_direction{ Vec3::normalize(direction) };
		const float t{ (normalized_direction.y() + 1.0f) * 0.5f };
		return lower_color * (1.0f - t) + upper_color * t;

	}

}