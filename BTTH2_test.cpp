#include <iostream>

using namespace std;

// Khai báo cấu trúc của một Node
struct Node
{
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Class định nghĩa danh sách liên kết kép
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Thêm một phần tử vào đầu danh sách
    void addFirst(int value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Thêm một phần tử vào cuối danh sách
    void addLast(int value)
    {
        Node *new_node = new Node(value);
        if (tail == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Xuất các phần tử trong danh sách
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Xoá phần tử đầu danh sách
    void deleteFirst()
    {
        if (head == nullptr)
        {
            cout << "Danh sách rỗng, không có phần tử để xoá." << endl;
            return;
        }
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }

    // Xoá phần tử cuối danh sách
    void deleteLast()
    {
        if (tail == nullptr)
        {
            cout << "Danh sách rỗng, không có phần tử để xoá." << endl;
            return;
        }
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    // Tìm một phần tử trong danh sách và xoá nếu tìm thấy
    void deleteNode(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                // Xoá current
                if (current == head)
                {
                    deleteFirst();
                }
                else if (current == tail)
                {
                    deleteLast();
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return;
            }
            current = current->next;
        }
        cout << "Không tìm thấy phần tử " << value << " trong danh sách." << endl;
    }

    // Tìm một phần tử có giá trị bằng với giá trị x hoặc gần nhất và lớn hơn phần tử x nhập vào
    // Thêm một phần tử trước phần tử tìm thấy
    void insertBefore(int x, int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data >= x)
            {
                // Tạo node mới chứa giá trị mới
                Node *new_node = new Node(value);

                // Cập nhật liên kết
                new_node->next = current;
                new_node->prev = current->prev;
                if (current->prev != nullptr)
                {
                    current->prev->next = new_node;
                }
                else
                {
                    head = new_node;
                }
                current->prev = new_node;
                return;
            }
            current = current->next;
        }

        // Nếu không tìm thấy phần tử thích hợp, thêm vào cuối danh sách
        addLast(value);
    }
};

int main()
{
    DoublyLinkedList dll;

    // Thêm các phần tử vào danh sách
    dll.addLast(1);
    dll.addLast(2);
    dll.addLast(3);
    dll.addLast(4);
    dll.addLast(5);

    // Hiển thị danh sách
    cout << "Danh sach hien tai: ";
    dll.display();

    // Xoá phần tử đầu danh sách
    dll.deleteFirst();
    cout << "Sau khi xoá phần tử đầu: ";
    dll.display();

    // Xoá phần tử cuối danh sách
    dll.deleteLast();
    cout << "Sau khi xoá phần tử cuối: ";
    dll.display();

    // Tìm và xoá phần tử có giá trị là 3
    dll.deleteNode(3);
    cout << "Sau khi xoá phần tử có giá trị 3: ";
    dll.display();

    // Chèn phần tử 7 vào trước phần tử có giá trị gần nhất và lớn hơn 5
    dll.insertBefore(5, 7);
    cout << "Sau khi chen 7 vao truoc phan tu co gia tri gan nhat va lon hon 5: ";
    dll.display();

    return 0;
}