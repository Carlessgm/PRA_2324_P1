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

			out << "List => [";
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

		void insert(int pos, T e) override{
			if(pos < 0 || pos > n){
				throw out_of_range("Posición fuera de rango");
			}

			if(pos == 0){
				Node<T>* nuevoNodo = new Node<T>(e, first);
				first = nuevoNodo;
			}
			else{
				Node<T>* aux = first;
				for(int i = 0; i < pos - 1; i++){
					aux = aux -> next;
				}
				Node<T>* nuevoNodo = new Node<T>(e, aux -> next);
				aux -> next = nuevoNodo;
			}
			n++;
		}

		void append(T e) override{
			if(first == nullptr){
				Node<T>* nuevoNodo = new Node<T>(e);
				first = nuevoNodo;
			}
			else{
				Node<T>* aux = first;
				while(aux -> next != nullptr){
					aux = aux -> next;
				}
				Node<T>* nuevoNodo = new Node<T>(e);
				aux -> next = nuevoNodo;
			}
			n++;
		}

		void prepend(T e) override{
			Node<T>* nuevoNodo = new Node<T>(e, first);
			first = nuevoNodo;
			n++;
		}

		T remove(int pos) override{
			if(pos < 0 || pos >= n){
				throw out_of_range("Posición fuera de rango");
			}

			T ValElim;
			
			if(pos == 0){
				Node<T>* aux = first;
				ValElim = aux -> data;
				first = first -> next;
				delete aux;
			}
			else{
				Node<T>* aux = first;
				for(int i = 0; i < pos - 1; i++){
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

		T get(int pos) override{
			if(pos < 0 || pos >= n){
				throw out_of_range("Posición fuera de rango");
			}

			Node<T>* aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux -> next;
			}

			return aux -> data;
		}

		int search(T e) override{
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

		bool empty() override{
			if(n == 0){
				return true;
			}
			else{
				return false;
			}
		}

		int size() override{
			return n;
		}

};
