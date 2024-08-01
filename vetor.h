#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename T> class Vetor
{
	private:
		Node<T>* ptr;
		int tamanho;
		void clear();

	public:
		Vetor();
		~Vetor();

		int size() const;
		bool add(T i_);
		bool remove(int i);
		void show() const;
		T at(int i) const;
		bool sort(bool (*func_compara)(T, T));

};

#include "vetor.cpp"
#endif

