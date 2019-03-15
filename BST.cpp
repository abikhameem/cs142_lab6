#include<iostream>
using namespace std;
class Node
{public:
	//data
	int data;
	//pointers to move to left and right
	Node *left;
	Node *right;
	//constructor
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};
class BST
{public:
	//pointer that points to root of the tree
	Node *root;
	//constructor
	BST(){
		root = NULL;
	     }
	//insert function
	void insert(int value){
		insertHelper(root,value);
	}
	//recursive function to insert values
	void insertHelper(Node *curr, int value)
	{// if curr is NULL, insert there
		if(curr == NULL){
			curr = new Node(value);
			//update head
			if(root == NULL)
				root = curr;
			return;
		}
		//else compare curr data with value
		else if(value < curr->data){
			if(curr->left == NULL)
				curr->left = new Node(value);
				else
				insertHelper(curr->left,value);
		}
		else{
			if(curr->right == NULL)
				curr->right = new Node(value);

			else
				insertHelper(curr->right,value);
		}
	}
	//display function
	void display(){
		//recursive call
		display2(root);
	}
	//recursive display function
	void display2(Node *curr)
	{   if(curr == NULL)
			return;
		//display left
		display2(curr->left);
		//display current
		cout<<curr->data<<"->";
		//display right
		display2(curr->right);
	}
	//search function
	void search(int value)
	{   cout<<endl;
		Node * var;
		var = search2(root,value);
		if(var == NULL)
			cout<<"Sorry, the element does not exist\n";
		else
			cout<<"The element exists\n";
	}
	//recursive function for searching
	Node * search2(Node *curr,int value)
	{//condition if value found or not
		if(curr == NULL || curr->data == value)
			return curr;
        else if(value < curr->data)
			return search2(curr->left,value);
        else
			return search2(curr->right,value);
	}

};

//main function
int main()
{//Variable declaration
	BST b1;
	int x;
	//inserting values
	for(int i=1;i<6;i++)
		b1.insert(i);
	//displays the tree
	b1.display();
	//asks user to enter a value to be searched
	cout<<endl<<"Enter value to be searched\n";
	cin>>x;
	b1.search(x);
	//closing program
	return 0;
}
