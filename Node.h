#include <ostream>

using namespace std;

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;

		Node(T data, Node<T>* next = nullptr){	//"= nullptr" -> Si no se
			this -> data = data;		//proporciona "next" es nullptr
			this -> next = next;		//Si sí, es igual a "next"
		}

		friend ostream& operator<<(ostream &out, const Node<T> &node){	//Imprime una instancia de Node
			out << node.data;

			return out;
		}

};
