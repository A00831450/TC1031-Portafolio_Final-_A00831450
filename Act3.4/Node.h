#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
	private:
		int data;
		string ip;
		bool checked;
		
		Node *left;
		Node *right;
	public:
		Node(int data, string acc){
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
			this->ip = acc;
			this->checked = false;
		}
		
		Node(int data, Node *left, Node *right){
			this->data = data;
			this->left = left;
			this->right = right;
		}
		
		int getData(){
			return this->data;
		}
		
		Node* getLeft(){
			return this->left;
		}
		
		Node* getRight(){
			return this->right;
		}
		
		void setData(int data){
			this->data = data;
		}
		
		void setLeft(Node *left){
			this->left = left;
		}
		
		void setRight(Node *right){
			this->right = right;
		}
		
		string getIp()
		{
			return ip;
		}
		
		bool getChecked()
		{
			return checked;
		}
		
		void setChecked(bool tr)
		{
			this->checked = tr;
		}
};

#endif
