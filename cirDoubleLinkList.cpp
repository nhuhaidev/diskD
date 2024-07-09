#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
	Node *prev;
	Node(int val):data(val),next(NULL),prev(NULL){}
};
class CirDoubleLinkList
{
private:
	Node *head;
	Node *tail;
public:
	CirDoubleLinkList():head(NULL),tail(NULL){}
	void addFist(int val) {
		Node *new_node = new Node(val);
		if (head == NULL)
		{
			head = tail = new_node;
			new_node->next = head;
			head->prev = tail;
		}
		else {
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
			tail->next = new_node;
			head->prev = tail;
		}
	}
	void addLast(int val) {
		Node *new_node = new Node(val);
		if (head == NULL)
		{
			head = tail = new_node;
			new_node->next = head;
			head->prev = tail;
		}
		else {
			new_node->next = head;
			new_node->prev = tail;
			head->prev = new_node;
			tail->next = new_node;
			tail = new_node;
		}
	}
	void display() {
		if (head == NULL) {
			cout << "Danh sách rỗng\n";
			return;
		}

		Node *tem = head;
		do {
			cout << tem->data << " ";
			tem = tem->next;
		} while (tem != head);
		cout << endl;

		Node *tmp = tail;
		do {
			cout << tmp->data << " ";
			tmp = tmp->prev;
		} while (tmp != tail);

		cout << endl;
	}
	void deleteFirst()
	{
		if (head == NULL)
		{
			cout << "Không có phần tử để xóa\n";
			return;
		}
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			tail->next = head->next;
			head->next->prev = tail;
			head->next = NULL;
			delete head;
			head = tail->next;
		}
	}
};
int main()
{
	CirDoubleLinkList cll;
	cll.addFist(0);
	cll.addFist(1);
	cll.addFist(2);
	cll.addFist(3);
	cll.addFist(4);
	cll.addLast(-1);
	cll.addLast(-2);
	cout << "Danh sach hien tai: \n";
	cll.display();
	cll.deleteFirst();
	cout << "Danh sach sau khi xoa dau: \n";
	cll.display();
	system("pause");
	return 0;
}