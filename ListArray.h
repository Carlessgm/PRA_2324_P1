#include <ostream>
#include "List.h"

using namespace std;

template <typename T>
class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		
		void resize(int new_size){
			T* new_arr = new T[new_size];
			for(int i = 0; i <= n - 1; i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}

	public:
		ListArray(){
			arr = new T[MINSIZE];
        		max = MINSIZE;
        		n = 0;			//n = Núm. elementos -> n-1 = pos.
		}				//del último valor del array

		~ListArray(){
			delete[] arr;
		}

		T operator[] (int pos){
			if(pos < 0 || pos > max - 1)
                		throw out_of_range("Valor fuera de rango");
        		else
	                	return arr[pos];
		}

		friend ostream& operator<<(ostream &out, const ListArray<T> &list){
			out << "[";
			for(int i = 0; i < list.n; i++){
				out << list.arr[i];		//El "out" es por el
				out << ", ";			//"operator<<"
			}
			out << "]";
			return out;
		}

		void insert(int pos, T e) override{
			if(pos < 0 || pos > max - 1){
				throw out_of_range("Posición fuera de rango");
			}

			if(n >= max){
				resize(max * 2);      //Redimensiona si es necesario
			}			      //significativamente (*2)

			for(int i = n - 1; i >= pos; i--){
				arr[i + 1] = arr[i];
			}

			arr[pos] = e;
			n++;
		}

		void append(T e) override{
			if(n >= max){
				resize(max * 2);
			}

			arr[n] = e;
			n++;
		}

		void prepend(T e) override{
			if(n >= max){
				resize(max * 2);
			}

			for(int i = n - 1; i >= 0; i--){
				arr[i + 1] = arr[i];
			}

			arr[0] = e;
			n++;
		}

		T remove(int pos) override{
			if(pos < 0 || pos > n - 1){
				throw out_of_range("Posición fuera de rango");
			}

			T ValElim = arr[pos];

			for(int i = pos; i < n - 1; i++){
				arr[i] = arr[i + 1];
			}
			n--;

			if(n < max / 4){	  //Si la lista <25% llena
				resize(max / 2);  //Reducimos capacidad a la mitad
			}

			return ValElim;
		}

		T get(int pos) override{
			if(pos < 0 || pos > n - 1){
				throw out_of_range("Posición fuera de rango");
			}

			return arr[pos];
		}

		int search(T e) override{
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;
				}
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
