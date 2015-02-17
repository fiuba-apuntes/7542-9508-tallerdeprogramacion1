class Perro{
public:
	/**
	 * Cualquier clase o función puede llamar a este método
	 */
	void ladrar(); // 
protected:
	/**
	 * Solo instancias de Perro o de clases derivadas
	 * a él pueden acceder a este atributo.
	 */
	std::string raza;
private:
	/**
	 * Solo instancias de Perro pueden acceder a este atributo.
	 */
	int edad;
};