#include <cmath>

#include "light.h"

using namespace std;

double DirectionalLight::distanceAttenuation(const Vec3d& P) const
{
  // distance to light is infinite, so f(di) goes to 0.  Return 1.
  return 1.0;
}


Vec3d DirectionalLight::shadowAttenuation(const ray& r, const Vec3d& p) const
{
  // YOUR CODE HERE:
  // You should implement shadow-handling code here.
  return Vec3d(1,1,1);
}

Vec3d DirectionalLight::getColor() const
{
  return color;
}

Vec3d DirectionalLight::getDirection(const Vec3d& P) const
{
  // for directional light, direction doesn't depend on P
  return -orientation;
}

double PointLight::distanceAttenuation(const Vec3d& P) const
{

  Vec3d directionVector = this->position - P;


  return min(1.0, 1/(constantTerm + linearTerm*directionVector.length() + quadraticTerm*directionVector.length2()));
}

Vec3d PointLight::getColor() const
{
  return color;
}

Vec3d PointLight::getDirection(const Vec3d& P) const
{
  Vec3d ret = position - P;
  ret.normalize();
  return ret;
}


Vec3d PointLight::shadowAttenuation(const ray& r, const Vec3d& p) const
{
  Vec3d d =getDirection(p);
  d.normalize();
  isect i;
  ray r2 = ray(p, d, ray::SHADOW);
  if(scene->intersect(r2, i)) {

    return Vec3d(0,0,0);
  }
  return Vec3d(1,1,1);
}
