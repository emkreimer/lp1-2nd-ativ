#include "vetor.h"

//<------------- FUNCOES EXTRAS ---------->
template <typename T>
void Vetor<T>::clear()
{
    while (ptr)
    {
        Node<T> *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    tamanho = 0;
}

template <typename T>
void bubbleSort(T *array, int size, bool (*func_compara)(const T &, const T &))
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (!func_compara(array[j], array[j + 1]))
            {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//<------------- FIM DAS FUN��ES EXTRAS ---------->

template <typename T>
Vetor<T>::Vetor() : ptr(nullptr), tamanho(0) {}

template <typename T>
Vetor<T>::~Vetor()
{
    clear();
}

template <typename T>
int Vetor<T>::size() const
{
    return tamanho;
}

template <typename T>
void Vetor<T>::show() const
{
    Node<T> *temp = ptr;
    while (temp)
    {
        std::cout << temp->content << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool Vetor<T>::add(T i_)
{
    try
    {
        Node<T> *el = new Node<T>(i_);
        if (!ptr)
        {
            ptr = el;
        }
        else
        {
            Node<T> *temp = ptr;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = el;
        }
        tamanho++;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

template <typename T>
bool Vetor<T>::remove(int i)
{
    if (i < 0 || i >= tamanho)
    {
        return false;
    }

    try
    {
        Node<T> *temp = ptr;
        if (i == 0)
        {
            ptr = ptr->next;
            delete temp;
        }
        else
        {
            for (int j = 0; j < i - 1; ++j)
            {
                temp = temp->next;
            }
            Node<T> *el_removido = temp->next;
            temp->next = el_removido->next;
            delete el_removido;
        }
        tamanho--;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

template <typename T>
T Vetor<T>::at(int i) const
{
    if (i < 0 || i >= tamanho)
        throw std::out_of_range("Esse �ndice n�o existe!");

    Node<T> *temp = ptr;
    for (int j = 0; j < i; ++j)
    {
        temp = temp->next;
    }
    return temp->content;
}

template <typename T>
bool Vetor<T>::sort(bool (*func_compara)(const T &, const T &))
{
    if (tamanho <= 1)
        return false;

    T *array = new T[tamanho];
    Node<T> *temp = ptr;
    for (int i = 0; i < tamanho; ++i)
    {
        array[i] = temp->content;
        temp = temp->next;
    }

    bubbleSort(array, tamanho, func_compara);

    temp = ptr;
    for (int i = 0; i < tamanho; ++i)
    {
        temp->content = array[i];
        temp = temp->next;
    }

    delete[] array;
    return true;
}
