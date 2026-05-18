// Using GNU AFFERO GENERAL PUBLIC LICENSE Version 3

class Node {

	Node* parent = nullptr;
	Node* smallerChild = nullptr;
	Node* largerChild = nullptr;
	int value;
	
	public:

	Node(int value, Node* parent = nullptr){
		this->value = value;
		this->parent = parent;
	}

	void setSmallerChild(Node* smallerChild){
		this->smallerChild = smallerChild;
	}

	void setLargerChild(Node* largerChild){
		this->largerChild = largerChild;
	}

	void setParent(Node* parent){
		this->parent = parent;
	}
	
	int getValue(){
		return this->value;
	}

	void addAlgorithm(Node* Node){
		if(this->value > Node->getValue()){
			if(this->smallerChild == nullptr){
				this->setSmallerChild(Node);
			}else{
				smallerChild->addAlgorithm(Node);
			}
		}
		if(this->value < Node->getValue()){
			if(this->largerChild == nullptr){
				this->setLargerChild(Node);
			}else{
				largerChild->addAlgorithm(Node);
			}
		}
	return;
	}

	int searchAlgorithm(int value){
		if(this->value == value){
			return this->value;
		}
		if(this->value > value){
			return this->smallerChild->searchAlgorithm(value);
		}
		if(this->value < value){
			return this->largerChild->searchAlgorithm(value);
		}
	return 0;
	}
};

class Tree {

	Node* root;
	
	public:

	Tree(int rootValue = 100){
		Node* Nroot = new Node(rootValue);
		this->root = Nroot;
	}

	void add(int value){
		Node* addedNodePointer = new Node(value);
		this->root->addAlgorithm(addedNodePointer);
	}
	
	void remove(){
		//this->root.removeAlgorithm();
	}
	
	int search(int value){
		return this->root->searchAlgorithm(value);
	}
};
