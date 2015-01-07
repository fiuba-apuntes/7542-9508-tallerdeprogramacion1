#include <iostream>

/**
 * Una clase que representa a un buffer, mal implementado
 */
class WrongBuffer{
public:
	WrongBuffer(): buffer(0){}
	/*
	 * Crea un buffer de tamaño size
	 */
	void startBuffer(int size){
		if (this->buffer){
			delete this->buffer;
		}
		this->buffer = new char[size];
	}
	/*
	 * Limpia el buffer
	 */
	void deleteBuffer(){
		delete[] this->buffer;
	}
	/**
	 * Devuelve el buffer almacenado
	 */
	char* getBuffer(){
		return this->buffer;
	}
private:
	char* buffer;
};

/**
 * Implementacion mas prolija del buffer
 */
class Buffer{
public:
	/*
	 * Constructor
	 */
	Buffer(int size){
		this->buffer = new char[size];
	}
	/*
	 * Destructor, limpia el buffer
	 */
	~Buffer(){
		delete[] this->buffer;
	}
	/**
	 * Devuelve el buffer almacenado
	 */
	char* getBuffer(){
		return this->buffer;
	}
private:
	char* buffer;
};

/**
 * Ejemplo de codigo sin patron RAII
 */
void badExample1(){
	WrongBuffer buff;
	buff.startBuffer(42);
	/**
	 * ERROR! El programador debe recordar liberar la memoria, de lo contrario
	 * la aplicacion tendra leaks.
	 * En esta seccion de codigo no pueden lanzarse excepciones, ya que
	 * se perderia el puntero al buffer sin haberlo liberado.
	 */
	buff.deleteBuffer();
}

/**
 * Ejemplo de codigo que sigue el patron RAII
 */
void example(){
	Buffer buffer(42);
	/**
	 * Notese que hacer Buffer *buffer = new Buffer(42) tambien estaria
	 * rompiendo el patron RAII.
	 */
	char* buffContent = buffer.getBuffer();
	/**
	 * Al finalizar la funcion, se llama al destructor de buffer. El destructor
	 * se llama automaticamente, no es necesario que el programador lo haga
	 * explicitamente, por lo que la memoria reservada en la instancia buffer
	 * es liberada siempre.
	 */
}
