/** 
 * @details Archivo State.h: Clase conformada por un string y vector de 
 *                  pares, dichos pares son un Estado (un objeto de la 
 *                  misma clase) y un char. Este vector indica las diversas 
 *                  transiciones de cada estado
 * 
 *  @brief Clase empleada para representar cada estado del DFA
 *  @author Alejandro Peraza González
 *  @date   28/10/2019
 *  @par Universidad
 *    Universidad de La Laguna
 *  @par Curso
 *    2º de Ingeniería Informática
 *  @par Título
 *    Autómatas finitos deterministas
 *  @par Correo 
 *    alu0101211770@ull.edu.es
 *  @par Referencias
 *    https://campusvirtual.ull.es/1920/pluginfile.php/176735/mod_assign/introattachment/0/CYA_1920_Practica_6.pdf?forcedownload=1
 *  @par Historial de revisiones
 *    10/10/2019 - Creación (primera versión) del código
 */

#include <string>
#include <vector>

#ifndef STATE
#define STATE

class State {
 public:
  /// Constructor de la clase State por defecto 
  State ();
  /** @brief Constructor al recibir una string, esta es asignada a
   *  la variable state_
   *  @param state - identificador de cada estado
   */
  State (std::string state);
  /** @brief Destructor que libera la memoria reservada por el vector
   *  transitions_
   */
  ~State ();
  /** @brief Getter del atributo state_
   *  @return string que identifica a cada estado
   */
  std::string getStr ();
  /** @brief Setter del atributo state_
   *  @param str - una string que modifica el valor de state_  
   */
  void setStr (std::string &str);
  /** @brief Método que devuelve el estado siguiente dado un estado
   *  actual y un char
   * @param token - un char
   * @return un estado siguiente
   */ 
  State Delta (char token);
  /** @brief Método para comparar si dos estados son iguales 
   *  @param state - estado a comparar
   *  @return un booleano que indica si son o no iguales
   */
  bool Equal (State &state) const;
  /** @brief Método que inserta un estado en el vector de transiciones
   *  @param token - un char   
   *  @param q - un estado
   */
  void Insert(char token, State q);
  
 private:
  std::string state_;
  std::vector<std::pair<State, char>> transitions_;
};

#endif