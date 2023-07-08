
// . . . . . . . . . . . . . . . . . . . . . . . . . .   C   O   M   E   N   T   A   R   I   O   S . . . . . . . . . . . . . . . . . . . . . . . . . .  

// -L E Y  D E   D E M E T E R: esta ley lo que dice es como un m�todo (a) de una clase (b) debe comunicarse con otros m�todos de otras clases.
// La ley se cumple en este codigo ya que cuando una clase necesita acceder a un m�todo de otra clase, solo se comunica con 
// clases amigas (asociadas). Un ejemplo de esto es al llamar a un m�todo de la Vista a la clase estudiante, primero llama a la clase Sistema
// Gestor esta llama a la matr�cula y esta a su estudiante

// -R E S P O N S A B I L I D A D  U N I C A: El concepto de esto es que una clase deber�a tener una �nica raz�n para cambiar.
// En el c�digo se cumple porque cada una de las clases tiene una �nica raz�n de ser, por ejemplo Gestor de Archivos es manejar los
// archivos, Controladora es controlar los m�todos, vista interact�a con el usuario, sistemaGestor guarda las listas las cuales se
// generan de una lista template

// -H E R E N C I A: se uso el concepto de herencia para poder encapsular los datos de las clases ProfesorGuia, Estudiante y Encargado en
// la clase persona

// -M E T O D O S  A B S T R A C T O S  P U R O S: estos m�todos son utilizados para que las clases hijas de persona usen los get y
// set de cedula, nombre y apellido

// -A G R E G A C I O N  Y  C O M P O S I C I O N: la clase Estudiante tiene agregaci�n deEncargado, Profesor y Fecha. Y para la composicion: 
// la clase matr�cula es una composici�nde profesorGuia, estudiante y encargado

// -M E T O D O S  A B S T R A C T O S: este concepto es utilizado para poder sobreescribir los m�todos de persona, el constructor y el toString

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

#include "GestorArchivos.h"
#include "Lista.h"
#include "Controladora.h"
using namespace std;

int main() {
	Controladora* control = new Controladora();
	control->control();
	system("pause");
	return 0;
}


