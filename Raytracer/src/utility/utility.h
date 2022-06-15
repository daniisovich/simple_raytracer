#pragma once

#include <random>

#include "../core/vec3.h"


namespace utility {

	Vec3 gradientColor(const Vec3& direction, const Vec3& lower_color = { 1.0f, 1.0f, 1.0f }, const Vec3& upper_color = { 0.5f, 0.7f, 1.0f });

	float randomScalar(float min = 0.0f, float max = 1.0f);
	Vec3 randomInDisk(float radius = 1.0f);
	Vec3 randomInSphere(float radius = 1.0f);
	Vec3 randomInHemisphere(const Vec3& normal);

	Vec3 brdfHemisphere(const Vec3& ray_direction, const Vec3& normal);

	const float infinity{ std::numeric_limits<float>::infinity() };

}