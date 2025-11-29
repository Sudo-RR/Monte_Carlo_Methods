#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <random>

int main() {
    const long num_samples = 1'000'000;

    const double radius = 1.0;
    const double radius_squared = radius * radius;
    const double area_circle_theoretical = M_PI * radius_squared;
    const double square_area = 4.0 * radius_squared;

    long inside_circle_count = 0;

    std::mt19937_64 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    for (long i = 0; i < num_samples; i++) {
        double x = dist(rng);
        double y = dist(rng);
        if (x * x + y * y <= radius_squared)
            inside_circle_count++;
    }

    double area_circle_estimated =
        (static_cast<double>(inside_circle_count) / num_samples) * square_area;

    std::cout << "Estimated Area of Circle: " << area_circle_estimated << "\n";
    std::cout << "Theoretical Area of Circle: " << area_circle_theoretical << "\n";
}
