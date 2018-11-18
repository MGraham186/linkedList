#include <iostream>
using namespace std;
struct node{
	int data;
	struct node *next;

};

void displayNodes(struct node *n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n = n->next;
	}
}
void pushFrontNode(struct node ** frontNode, int val){
	struct node* front = (struct node*)malloc(sizeof(struct node));
	front->data = val;
	front->next = (*frontNode);
	(*frontNode) = front;
}
void append(struct node** head, int val){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node *last = *head;

	newNode->data = val;
	newNode->next = NULL;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	while(last->next !=NULL){
		last = last->next;
	}
	last->next = newNode;
	return;
}
void insertAfterNode(struct node* prevNode, int val){
	if(prevNode == NULL){
		cout<<"the list cannot be empty!"<<endl;
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}
void deleteNode(struct node** head, int val){
	struct node* tempNode = *head,*prev;
	if(tempNode != NULL and tempNode->data == val){
		*head = tempNode->next;
		free(tempNode);
	}
	while(tempNode!=NULL and tempNode->data!=val){
		prev = tempNode;
		tempNode = tempNode->next;
	}
	if(tempNode == NULL){ return; }  // value not found in list
	prev->next = tempNode->next; free(tempNode); return;

}
int lengthLinkedList(struct node *head){
	int c = 0;
	struct node *iter = head;
	while(iter->next != NULL){
		c++;iter = iter->next;
	}
	return c;
}
bool search(struct node* head, int val){
	struct node *current = head;
	if(current == NULL){ return false;}
	while(current->next != NULL){
		if(current->data == val){
			return true;
		}
	}return false;
}
int main() {
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));

	head->data = 1; head->next = second;
	second->data = 5;second->next = third;
	third->data = 18; third->next = NULL;
	pushFrontNode(&head, 72);
	append(&second, 815);
	insertAfterNode(second,111);
	insertAfterNode(head,151);
	insertAfterNode(head,253);
	pushFrontNode(&head,735);
	append(&head,99);
	insertAfterNode(second,3);
	append(&head,5531);
	deleteNode(&head,72);
	displayNodes(head);
	int length = lengthLinkedList(head);
	cout<<endl<<"The length is: " << length << endl;
	cout<<(search(head,735)?"Yay":"Nay")<<endl;

}
