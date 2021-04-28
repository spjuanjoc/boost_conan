#include "catch2/catch.hpp"
#include "fmt/core.h"
#include "Inventario.hpp"

TEST_CASE("should get Inventario struct as a JSON", "[JSON][property_tree]")
{
  std::string_view expectedJson = R"EOL({
    "Equipo": "MY-PC",
    "Disco": {
        "Nombre": "C:",
        "Tamaño": "200"
    },
    "Archivos": {
        "Cantidad": "100",
        "Peso(Mb)": "20000"
    },
    "IP": "192.168.0.4"
}
)EOL";

  DiscoDuro  Hd{"C:", 200};
  Archivos   Fle{100, 20000};
  Inventario prInv{"MY-PC", Hd, Fle, "192.168.0.4"};
  pt::ptree  root = static_cast<pt::ptree>(prInv);

  std::stringstream actual;
  pt::write_json(actual, root);

  REQUIRE(expectedJson == actual.str());
}
