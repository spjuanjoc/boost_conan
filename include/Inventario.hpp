//
// Created by juan.castellanos on 28/04/21.
//
#pragma once

#include "boost/property_tree/json_parser.hpp"
#include "boost/property_tree/ptree.hpp"

namespace pt = boost::property_tree;

struct DiscoDuro
{
  std::string  nombre;
  std::int32_t sizeDisco;

  explicit operator pt::ptree() const;
};

struct Archivos
{
  std::int32_t cantidad;
  std::int32_t pesoMb;

  explicit operator pt::ptree() const;
};

struct Inventario
{
  std::string nombreEquipo;
  DiscoDuro   disco;
  Archivos    lstFiles;
  std::string IP;

  explicit operator pt::ptree() const;
};

DiscoDuro::operator pt::ptree() const
{
  pt::ptree root;
  root.put<std::string>("Nombre", nombre);
  root.put<std::int32_t>("Tamaño", sizeDisco);
  return root;
}

Archivos::operator pt::ptree() const
{
  pt::ptree root;
  root.put<std::int32_t>("Cantidad", cantidad);
  root.put<std::int32_t>("Peso(Mb)", pesoMb);
  return root;
}

Inventario::operator pt::ptree() const
{
  pt::ptree root;
  root.put<std::string>("Equipo", nombreEquipo);
  root.put_child("Disco", static_cast<pt::ptree>(disco));
  root.put_child("Archivos", static_cast<pt::ptree>(lstFiles));
  root.put<std::string>("IP", IP);
  return root;
}
