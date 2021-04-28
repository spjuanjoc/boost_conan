#include "fmt/core.h"
#include "Inventario.hpp"
#include <iostream>

int main()
{
  fmt::print("{}\n{}",
             "boost::property_tree::ptree",
             "Create a JSON from a struct using Boost.PropertyTree\n");

  DiscoDuro Hd{"C:", 200};
  Archivos  Fle{100, 20000};

  Inventario prInv{"MY-PC", Hd, Fle, "192.168.0.4"};

  pt::ptree root = static_cast<pt::ptree>(prInv);
  fmt::print("The json:\n");

  std::stringstream ss;
  pt::write_json(ss, root);
  fmt::print("{}", ss.str());

  return 0;
}
