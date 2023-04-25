#include <iostream>
#include "node.hpp"


int main() {

	std::cout << "----------" << std::endl;
	std::cout << "l = ((a+b) + c) * d" << std::endl;

	Node b = Node(4.0f);
	Node a = Node(3.0f);

	Node c = Node(3.0f);
	Node d = Node(10.0f);

	Node e = a.add(b);
	Node f = c.add(e);

	Node l = f.multiply(d);

	l.backward();

	std::cout << "\n" << "a:" << std::endl;

	a.log();


	std::cout << "----------" << std::endl;
	std::cout << "l2 = x^2" << std::endl;

	Node x = Node(3.0f);
	Node l2 = x.multiply(x);

	l2.backward();

	std::cout << "\n" << "x:" << std::endl;
	x.log(); // dl2/dx = 2*x = 6.0

	std::cout << "----------" << std::endl;
	std::cout << "l3 = x^3" << std::endl;

	Node x0 = Node(3.0f);
	Node x2 = x0.multiply(x0);
	Node l3 = x2.multiply(x0);

	l3.backward();

	std::cout << "\n" << "x:" << std::endl;
	x0.log(); // dl3/dx = 3*x^2 = 27.0

}