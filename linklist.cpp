#include <iostream>
using namespace std;
/* Khai báo giá trị data và con trỏ pNext trỏ tới phần tử kế tiếp */
struct Node
{
    int data;
    Node* pNext;
};
/* Khai báo Node đầu pHead và Node cuối pTail*/
struct SingleList
{
    Node* pHead; 
    Node* pTail; 
};
/* khởi tạo giá trị cho Node đầu và Node cuối */
void Initialize(SingleList& list)
{
    list.pHead = list.pTail = NULL;// khởi tạo giá trị cho Node đầu và Node cuối là Null
}

/* Đếm số phần tử trong danh sách */
int SizeOfList(SingleList list)
{
    Node* pTmp = list.pHead;
    int nSize = 0;
    while (pTmp != NULL)
    {
        pTmp = pTmp->pNext;
        nSize++;
    }
    return nSize;
}

/* tạo Node trong danh sách liên kết đơn */
Node* CreateNode(int d)
{
    Node* pNode = new Node; //sử dụng pNode để tạo một Node mới
    if (pNode != NULL) // Nếu pNode != Null, tức là pNode có giá trị thì
    {
        pNode->data = d; // gán giá trị data cho d
        pNode->pNext = NULL;// và cho con trỏ pNext trỏ tới giá trị Null
    }
    else // Nếu pNode == Null, tức là pNode không có giá trị thì xuất thông tin
    {
        cout << "Error allocated memory";
    }
    return pNode;//trả về pNode
}

/* chèn Node đầu danh sách */
void InsertFirst(SingleList& list, int d)
{
    Node* pNode = CreateNode(d);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        pNode->pNext = list.pHead;
        list.pHead = pNode;
    }
}

/* chèn node vào cuối danh sách */
void InsertLast(SingleList& list, int d)
{
    Node* pNode = CreateNode(d);
    if (list.pTail == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}

/* chèn node vào giữa danh sách */
void InsertMid(SingleList& list, int pos, int d) {
    // Nếu pos < 0 hoặc pos lớn hơn kích thước của danh sách thì reuturn
    if (pos < 0 || pos >= SizeOfList(list)) {
        cout << "Không thể chèn Node!!!";
        return;
    }
    // Nếu pos == 0 thì gọi hàm InsertFirst
    if (pos == 0) {
        InsertFirst(list, d);
    }
    //Nếu pos == SizeOfList - 1 thì gọi hàm InsertLast
    else if (pos == SizeOfList(list) - 1) {
        InsertLast(list, d);
    }
    //Ngược lại thì thay đổi mối liên kết giữa các phần tử, cụ thể:
    else {
        Node* pNode = CreateNode(d);
        Node* pIns = list.pHead;
        Node* pPre = NULL;
        int i = 0;
        //thực hiện vòng lặp tìm pPre và pIns
        while (pIns != NULL) {
            if (i == pos)
                break;
            pPre = pIns;
            pIns = pIns->pNext;
            i++;
        }
        //sau khi tìm được thì thay đổi con trỏ pNext
        pPre->pNext = pNode;
        pNode->pNext = pIns;
    }
}

/* hàm xuất dữ liệu */
void PrintList(SingleList list)
{
    Node* pTmp = list.pHead;
    if (pTmp == NULL)
    {
        cout << "The list is empty!";
        return;
    }
    while (pTmp != NULL)
    {
        cout << pTmp->data << " ";
        pTmp = pTmp->pNext;
    }
}

int main() {
    SingleList list;
    Initialize(list);

    //Thêm node đầu danh sách
    InsertFirst(list, 5);
    InsertFirst(list, 7);
    InsertFirst(list, 3);
    cout << "Các Node trong danh sách sau khi InsertFirst là: ";
    PrintList(list);

    //Thêm node cuối danh sách
    InsertLast(list, 4);
    InsertLast(list, 2);
    InsertLast(list, 6);
    cout << "\nCác Node trong danh sách sau khi InsertLast là: ";
    PrintList(list);

    //Thêm node giữa danh sách
    InsertMid(list, 4, 11);
    InsertMid(list, 2, 12);
    InsertMid(list, 3, 13);
    cout << "\nCác Node trong danh sách sau khi InsertMid là: ";
    PrintList(list);

    cout << "\n-------------------------------------\n";
    cout << "Chương trình này được đăng tại Freetuts.net";
}