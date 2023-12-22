#include <ostream>
#include "List.h"

using namespace std;

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;				//Tamaño máximo del array
		int n;					//Número de elementos
		static const int MINSIZE = 2;
		
		void resize(int new_size){		//Redimensiona el array al tamaño
			T* new_arr = new T[new_size];		//"new_size"
			for(int i = 0; i <= n - 1; i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}

	public:
		ListArray(){			//Reserva memoria dinámica para "arr"
			arr = new T[MINSIZE];	//tipo T de tamaño MINSIZE
        		max = MINSIZE;
        		n = 0;			//n = Núm. elementos -> n-1 = pos.
		}				//del último valor del array

		~ListArray(){			//Libera memoria dinámica reservada
			delete[] arr;
		}

		T operator[] (int pos){		//Devuelve el elemento de la posición "pos"
			if(pos < 0 || pos > max - 1)
                		throw out_of_range("Valor fuera de rango");
        		else
	                	return arr[pos];
		}

		friend ostream& operator<<(ostream &out, const ListArray<T> &list){
			out << "List => [";
			for(int i = 0; i <= list.n - 1; i++){
				out << list.arr[i];			//El "out" es por el
				if(i < list.n - 1){			//"operator<<"
					out << ", ";
				}
			}
			out << "]";
			return out;
		}

		void insert(int pos, T e) override{	//Inserta "e" en la posición "pos"
			if(pos < 0 || pos > max - 1){
				throw out_of_range("Posición fuera de rango");
			}

			if(n >= max){
				resize(max * 2);      //Redimensiona si es necesario
			}			      //significativamente (*2)

			for(int i = n - 1; i >= pos; i--){
				arr[i + 1] = arr[i];		//Asigna al siguiente el
			}					//anterior hasta llegar a
								//"pos"
			arr[pos] = e;
			n++;
		}

		void append(T e) override{		//Inserta "e" al final del vector
			if(n >= max){
				resize(max * 2);
			}

			arr[n] = e;
			n++;
		}

		void prepend(T e) override{		//Inserta "e" al principio del vector
			if(n >= max){
				resize(max * 2);
			}

			for(int i = n - 1; i >= 0; i--){
				arr[i + 1] = arr[i];		//Asignar al siguiente el
			}					//anterior hasta llegar a 0

			arr[0] = e;
			n++;
		}

		T remove(int pos) override{		//Elimina y devuelve elemento de "pos"
			if(pos < 0 || pos > n - 1){
				throw out_of_range("Posición fuera de rango");
			}

			T ValElim = arr[pos];

			for(int i = pos; i < n - 1; i++){	//Asignamos al anterior el
				arr[i] = arr[i + 1];		//siguiente -> borrar "pos"
			}
			n--;

			if(n < max / 4){	  //Si la lista <25% llena
				resize(max / 2);  //Reducimos capacidad a la mitad
			}

			return ValElim;
		}

		T get(int pos) override{	//Devuelve elemento de la posición "pos"
			if(pos < 0 || pos > n - 1){
				throw out_of_range("Posición fuera de rango");
			}

			return arr[pos];
		}

		int search(T e) override{	//Busca el primer valor "e" del vector
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;	//Devuelve la posición
				}
			}
			return -1;			//Devuelve no encontrado
		}

		bool empty() override{		//Indica si la lista está vacía
			if(n == 0){
				return true;
			}
			else{
				return false;
			}
		}

		int size() override{		//Devuelve núm elementos de la lista
			return n;
		}

		void duplicate_list() override{
			resize(max * 2);
			
			int medio = (max - 1) / 2;
			int j = medio;

			for(int i = 0; i <= medio; i++){
				arr[j + 1] = arr[i];
			       	j++;	
			}
			n = n*2;
		}

};
