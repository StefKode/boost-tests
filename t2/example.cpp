#include <boost/geometry/geometry.hpp>
 
#include <iostream>
 
static void CartesianToSpherical();
static void SphericalToCartesian();
 
int main()
{
  CartesianToSpherical();
  SphericalToCartesian();
}
 
void CartesianToSpherical()
{
  std::cout << "CartesianToSpherical()" << std::endl;
  namespace bg = boost::geometry; // bg = 'B'oost 'G'eometry
  namespace cs = bg::cs; // cs = 'C'oordinate 'S'ystem
 
  typedef bg::model::point<long double, 3, cs::cartesian> CartesianType;
  CartesianType cartesian(0.084186, 0.0225576, 0.996195);
 
  typedef bg::model::point<long double, 2, cs::spherical<bg::degree> > SphericalType;
  SphericalType spherical;
 
  bg::strategy::transform::from_cartesian_3_to_spherical_polar_2<CartesianType, SphericalType> strategy;
  bg::transform(cartesian, spherical, strategy);
 
  std::cout
      << "cartesian: " << bg::dsv(cartesian) << std::endl // dsv = Delimiter Separated Values
      << "spherical: " << bg::dsv(spherical) << std::endl;
}
 
void SphericalToCartesian()
{
  std::cout << "SphericalToCartesian()" << std::endl;
  namespace bg = boost::geometry; // bg = 'B'oost 'G'eometry
  namespace cs = bg::cs; // cs = 'C'oordinate 'S'ystem
 
  // (theta=5.0, phi=15.0)
  typedef bg::model::point<long double, 2, cs::spherical<bg::degree> > SphericalType;
  SphericalType spherical(15.0, 5.0);
 
  typedef bg::model::point<long double, 3, cs::cartesian> CartesianType;
  CartesianType cartesian;
 
  bg::strategy::transform::from_spherical_polar_2_to_cartesian_3<SphericalType, CartesianType> strategy;
  bg::transform(spherical, cartesian, strategy);
 
  std::cout
      << "spherical: " << bg::dsv(spherical) << std::endl // dsv = Delimiter Separated Values
      << "cartesian: " << bg::dsv(cartesian) << std::endl;
}
