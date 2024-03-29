/*! @mainpage NFA2DFA
 *  @author Alejandro Peraza González
 *  @date   05/11/2019
 *  @par Universidad
 *    Universidad de La Laguna
 *  @par Curso
 *    2º de Ingeniería Informática
 *  @par Título
 *    La construccion de subconjuntos
 *  @par Correo 
 *    alu0101211770@ull.edu.es
 *  @par Referencias
 *    https://campusvirtual.ull.es/1920/pluginfile.php/181073/mod_assign/introattachment/0/CYA_1920_Practica_7.pdf?forcedownload=1
 *  @par Historial de revisiones
 *    30/10/2019 - Creación (primera versión) del código
 */
#include <iostream>
#include <fstream>
#include <string>
#include "Nfa.h"
#include "Dfa.h"

int main (int argc, char *argv[]) {	
  std::ifstream input;
  std::ofstream output;
  for (int i = 1; i < argc; i++) {
    std::string aux = argv[i];
    if (aux == "--help") {
      std::cout << "Usage: ./DFA2dot [FILE].dfa [FILE].gv \n"
        "Example: ./DFA2dot input.dfa output.gv\n"
        "When executing DFA2dot, it reads the data of the DFA\n"
        "read from the .dfa file and outputs a .gv with\n"
        "its information and which will be able to be opened\n"
        "with the aid of graphviz.\n";
      return 0;
    } 
  }

  if (argc != 3) {
    std::cout << "Modo de empleo: ./DFA2dot input.dfa output.gv\n"
      "Pruebe ’./DFA2dot --help’ para más información.\n";
      return 0;
  }
  else {
  input.open(argv[1]); 
  output.open(argv[2]);
  }
  if (input) {
    Nfa nfa (input);
    Dfa dfa;
    nfa.SubSets(dfa, output);
    
    input.close();
  } 
  else std::cout << "Error en la apertura del fichero de entrada\n";
  output.close();
  return 0;
}
