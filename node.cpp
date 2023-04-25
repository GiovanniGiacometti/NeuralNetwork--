#include "node.hpp"
#include <iostream>



Node::Node(float value) {
	this->value = value;
}

Node::Node(float value,  std::vector<Node*> parents, std::vector<float> incGradients){
	this->value = value;
	this->gradients = incGradients;
	this->parents = parents;
}


Node Node::add(Node &other)
{	
	std::vector<Node*> parents;
	std::vector<float> gradients;


	parents.push_back(this);
	gradients.push_back(1.0f);

	parents.push_back(&other);
	gradients.push_back(1.0f);
	
	return Node(this->value + other.value, parents, gradients);
}

Node Node::subtract(Node &other){
	Node toSub = Node(-other.value);
	return this->add(toSub);
}

Node Node::multiply(Node &other)
{

	std::vector<Node*> parents;
	std::vector<float> gradients;


	parents.push_back(this);
	gradients.push_back(other.value);

	parents.push_back(&other);
	gradients.push_back(this->value);

	return Node(this->value * other.value, parents, gradients);
}

void Node::backward(){
	this->backprop(1.0f);
}

void Node::backprop(float accGrad){

	this->gradient += accGrad;

	for (int i = 0; i < parents.size(); i++) {
		parents[i]->backprop(gradients[i] * this->gradient);
	}
}

void Node::log() {
	std::cout  << "value   \t= "    << this->value << std::endl;
	std::cout  << "gradient\t= " << this->gradient << std::endl;
}