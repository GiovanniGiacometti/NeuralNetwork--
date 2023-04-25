#pragma once
#include <vector>
#include <memory>

class Node;


class Node {

public:

	Node(float value);
	Node(float value, std::vector<Node*> parents, std::vector<float> incGradients);
	

	Node add(Node &other);
	Node subtract(Node &other);
	Node multiply(Node &other);

	void backward();

	void log();

private:

	std::vector<Node*> parents;

	float value;
	std::vector<float> gradients;

	float gradient = 0.0f;

	void backprop(float value);

};
