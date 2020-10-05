#include <iostream>
#include <string>
#include <stdlib.h>
 
/*��������� �������*/
struct Student
{
    char Name[20];                          //���
    char NameLast[30];                      //�������
    int Age;                                //�������
    char School[30];                        //����� �����
 
    void Input(Student &student);           //������� ����� ������ � ���������
    Student *Next;                          //����� �� ��������� �������
};
 
class List
{
    Student *Head;                          //��������� �� ������ ������
public:
    List():Head(NULL){};                    //����������� �� ��������� (Head=NULL)
    ~List();                                //�������� �����������
    void Add(Student &student);             //�������� ������� ���������� �������� � ������
    void Show();                            //�������� ������� ������ ������ �� �����
};
 
/*������� ���������� ������ �� ��������*/
void Student::Input(Student &student)
{
    cout << endl;                           //��������� ������ ��� ������ ����� �����
    cout << "���:  ";
    cin.getline(Name,20);                   //���� �����
    cout << "�������:  ";
    cin.getline(NameLast,30);               //����  �������
    cout << "������ ��� ";
    cin >> Age;                             //���� ��������
    cin.ignore();                           //���������� ������
    cout << "��� ������ ";
    cin.getline(School, 30);                //���� ����� �����
}
 
 List::~List()                              //���������� ������ List
{
        while (Head != NULL)                //���� �� ������ ���� ���� ���-��
        {
            Student *temp = Head->Next;     //����� ���������� ��������� �� ����� ���������� �������� ���������
            delete Head;                    //����������� ������ �� ����� ������ ������
            Head = temp;                    //������ ����� ������ ������
        }
}
 
/*������� ���������� ����� ��������� � ������*/
 void List::Add(Student &student)
 {
     Student *temp = new Student;           //��������� ������ ��� ����� ���������
     temp->Next = Head;                     //���������, ��� ����� ���������� �������� ��� ������ ������
 
//����������� ����������� ��������� student � ������ ��� ��������� ����������
       strcpy(temp->Name, student.Name);
       strcpy(temp->NameLast, student.NameLast);
       temp->Age = student.Age;
       strcpy(temp->School, student.School);
 
     Head = temp;                           //����� ������ ������ ������
 }
 
 
/*������� ������ LIST ��� ������ ������ �� �����*/
 void List::Show()
 {
     Student *temp = Head;                  //��������� ��������� � ���������� �� ��������� �� ������
 
     while (temp != NULL)                   //���� �� ������ �� ������ ���� ���-�� ����
     {
     //������� ��� �������� ���������
         cout << temp->Name << "\t\t";      //����� �����
         cout << temp->NameLast <<"\t\t";   //����� �������
         cout << temp->Age << "\t\t";       //����� ��������
         cout << temp->School << endl;      //����� ����� �����
 
         temp = temp->Next;                 //��������� �� ��������� ����� �� ������
     }
     cout << endl;
 }
 
int main ()
{
  Student student;                          //�������� ����������, ��� ������� �������
  int N;                                    //�������� ���������� - ����� ���������
  List lst;                                 //�������� ���������� ���� ������. ��� ��������� ��� ��������� ������
 
    cout << "N = ";
    cin >> N;                               //����� ����� ���������
    cin.ignore();                           //���������� ������� Enter
 
    for (int i=0; i<N; i++)
    {
     student.Input(student);                //�������� � ������� ���������� ���������� �������
     lst.Add(student);                      //��������� ����������� ��������� � ������
    }
 
    cout << endl;
    lst.Show();                             //���������� ������ �� ������
  cin.ignore().get();
  return 0;
}
