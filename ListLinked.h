#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

	private:
		Node<T>* first;
		int n;

	public:
		ListLinked(){			//Método constructor, inicializa argumentos
			first = nullptr;	
			n = 0;			//Número elementos de la lista (Nodos creados)
		}

		~ListLinked(){			//Elimina los Nodos (de izquierda a derecha)
			Node<T>* aux;

			while(first != nullptr){
				aux = first -> next;
				delete first;
				first = aux;	
			}
		}

		T operator[](int pos){		//Devuelve elemento del Nodo "pos"
			if(pos < 0 || pos > n - 1){
				throw out_of_range("Posición fuera de rango");
			}

			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux -> next;	//Avanza al siguiente nodo
			}				//hasta llegar a pos

			return aux -> data;
		}

		friend ostream& operator<<(ostream &out, const ListLinked<T> &list){	//Imprime los datos de los
			Node<T>* aux = list.first;					//Nodos

			out << "List => [";
			if(aux != nullptr){
			  out << "\n";
			  while(aux != nullptr){
			    out << "   " << aux -> data;
			    if(aux -> next != nullptr){
			      out << "\n";
			    }
			    aux = aux -> next;
			  }
			  out << "\n]";
			}
			else{
			  out << "]";
			}
			  
			return out;
		}

		void insert(int pos, T e) override{	//Inserta "e" en el Nodo "pos"
			if(pos < 0 || pos > n){
				throw out_of_range("Posición fuera de rango");
			}

			if(pos == 0){						//Crear Nodo al principio (pos == 0)
				Node<T>* nuevoNodo = new Node<T>(e, first);
				first = nuevoNodo;
			}
			else{
				Node<T>* aux = first;
				for(int i = 0; i < pos - 1; i++){		//Nos situamos en el Nodo "pos"
					aux = aux -> next;			
				}
				Node<T>* nuevoNodo = new Node<T>(e, aux -> next);	//Creo un Nodo que apunta
				aux -> next = nuevoNodo;				//al siguiente y lo vinculo
			}								//al anterior
			n++;
		}

		void append(T e) override{		//Inserta "e" en un nuevo Nodo al final
			if(first == nullptr){		//Caso donde no hay ningun Nodo
				Node<T>* nuevoNodo = new Node<T>(e);
				first = nuevoNodo;
			}
			else{
				Node<T>* aux = first;
				while(aux -> next != nullptr){
					aux = aux -> next;
				}
				Node<T>* nuevoNodo = new Node<T>(e);	//Creo un Nodo con "e" que apunta a nullptr
				aux -> next = nuevoNodo;		//Lo vinculo al anterior
			}
			n++;
		}

		void prepend(T e) override{		//Inserta un Nodo con "e" al principio
			Node<T>* nuevoNodo = new Node<T>(e, first);
			first = nuevoNodo;
			n++;
		}

		T remove(int pos) override{		//Elimina el Nodo de la posición "pos" y devuelve su data
			if(pos < 0 || pos >= n){
				throw out_of_range("Posición fuera de rango");
			}

			T ValElim;
			
			if(pos == 0){			//Caso en que sea el primero
				Node<T>* aux = first;
				ValElim = aux -> data;
				first = first -> next;
				delete aux;
			}
			else{
				Node<T>* aux = first;
				for(int i = 0; i < pos - 1; i++){	//Nos colocamos en posición anterior a "pos"
					aux = aux -> next;
				}
				Node<T>* aux2 = aux -> next;		
				ValElim = aux2 -> data;
				aux -> next = aux2 -> next;
				delete aux2;
			}
			n--;
			return ValElim;
		}

		T get(int pos) override{		//Devuelve el elemento del Nodo "pos"
			if(pos < 0 || pos >= n){
				throw out_of_range("Posición fuera de rango");
			}

			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){	//Nos colocamos en Nodo "pos"
				aux = aux -> next;
			}

			return aux -> data;
		}

		int search(T e) override{		//Buscamos el primer Nodo que contenga "e"
			Node<T>* aux = first;
			int pos = 0;

			while(aux != nullptr){
				if(aux -> data == e){
					return pos;
				}
				aux = aux -> next;
				pos++;
			}
			
			return -1;
		}

		bool empty() override{			//Indica que si no hay Nodos creados
			if(n == 0){
				return true;
			}
			else{
				return false;
			}
		}

		int size() override{			//Devuelve el número de Nodos
			return n;
		}

		void duplicate_list() override{ 
		  /*int j = n;
			
			Node<T>* aux = first;
                        for(int i = 0; i < j; i++){
				int e = aux -> data;
                               	append(e);
				aux = aux -> next;
                        }*/
			}

};
