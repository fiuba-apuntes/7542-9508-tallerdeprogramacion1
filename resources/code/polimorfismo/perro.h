class Perro{
public:
	/**
	 * Método base, todos los perros ladran por defecto de la misma forma
	 */
	std::string ladrar() const{
		return "guau";
	}

	/**
	 * Otros métodos base
	 */
	int getEdad() const{
		return this->edad;
	}

	void setEdad(int edad){
		this->edad = edad;
	}

private:
	int edad;
};

class Doge : public Perro{
public:
	/**
	 * Se sobreescribe la forma de ladrar
	 */
	std::string ladrar() const{
		return "wow, such code, many meme";
	} 
};