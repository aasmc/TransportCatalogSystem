#pragma once

#include <cmath>

namespace Sphere {
  double ConvertDegreesToRadians(double degrees);

  struct Point {
    double latitude;
    double longitude;

    static Point FromDegrees(double latitude, double longitude);
  };

  bool operator<(const Point& lhs, const Point &rhs);

  double Distance(Point lhs, Point rhs);
}
