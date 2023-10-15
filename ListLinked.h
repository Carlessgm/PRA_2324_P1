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
		ListLinked(){
			first = nullptr;
			n = 0;
		}

		~ListLinked(){
			Node<T>* aux;

			while(first != nullptr){
				aux = first -> next;
				delete first;
				first = aux;	
			}
		}

		T operator[](int pos){
			if(pos < 0 || pos > n - 1){
				throw out_of_range("Posición fuera de rango");
			}

			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux -> next;	//Avanza al siguiente nodo
			}				//hasta llegar a pos

			return aux -> data;
		}

		friend ostream& operator<<(ostream &out, const ListLinked<T> &list){
			Node<T>* aux = list.first;

			out << "[";
			while(aux != nullptr){
				out << aux -> data;
				if(aux -> next != nullptr){
					out << ", ";
				}
				aux = aux -> next;
			}
			out << "]";

			return out;
		}

};
