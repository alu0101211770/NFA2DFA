/* Universidad de La Laguna
 *  Escuela Superior de Ingeniería y Tecnología
 *  Grado en Ingeniería Informática
 *  Asignatura: Computabilidad y Algoritmia (CyA)
 *  Curso: 2º 
 *  Práctica 7 CyA - La construccion de subconjuntos
 *  Autor: Alejandro Peraza González
 *  Correo: alu0101211770@ull.edu.es
 *  Fecha: 05/11/2019
 *  Archivo State.cc:   Esta clase es empleada con el fin de simbolizar
 *                      cada estado de un autómata
 *  Referencias: 
 *                       Enunciado de la práctica:
 *                       https://campusvirtual.ull.es/1920/pluginfile.php/181073/mod_assign/introattachment/0/CYA_1920_Practica_7.pdf?forcedownload=1
 *  Historial de revisiones
 *                       30/10/2019 - Creación (primera versión) del código
 */

#include <iostream>
#include "State.h"
typedef std::vector<std::pair<State, char>> vector_pair;

State::State () : state_(), transitions_(), marked_() {
  marked_ = 0;
}

State::State (std::string state) : state_(), transitions_(), marked_() {
  state_ = state;
  marked_ = 0;
}

State::~State () {
  transitions_.erase(transitions_.begin(), transitions_.end());
}

std::string State::getStr () const {
  return state_;
}

void State::setStr (std::string &str) {
  state_ = str;
}

bool State::getMark() const {
  return marked_;
}

void State::setMark(bool mark) {
  marked_ = mark;
}
 
vector_pair State::getTransitions () const {
  return transitions_;
}

State State::Delta (char token) {
  State dead ("NULL");
  for(std::size_t i = 0; i < transitions_.size(); i++) {
    if (transitions_[i].second == token) {
      return transitions_[i].first;
    }
  }
  return dead;
}
void State::Insert (char token, State q) {
  transitions_.push_back(std::make_pair(q, token));
}

bool State::operator< (const State &other) const { 
  return state_ < other.getStr(); 
}  

bool State::operator== (const State &other) const { 
  if (state_ == other.getStr()) return 1;
  else return 0;
}  