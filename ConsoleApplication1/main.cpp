#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "ukr");
	datatype choice = 0, value = 0, value1 = 0, c = 0 ;
	Node* root = NULL;

	do {
		
		cout << "1.�������� ������ ����� � �������� ����� ������ �� ������������" << endl;
		cout << "2.�������� ���������  �������  �����  (������)  �  ��������  ����� ������" <<endl;
		cout << "3.�������� ������� ������ ����� � ������ ������ ������" << endl;
		cout << "4.�������� ������  ������������  ����� Successor" << endl;
		cout << "5.�������� ������  ������������  ����� Predessor" << endl;
		cout << "6.��������� ����� " << endl;
		cout << "7.����� " << endl;
		cout << "������ ��� ���� - ";
		cin >> choice;


		switch (choice) {
		case 1 :
			if (root != NULL) {
				cout << "�������� ����� , ��� ������ - ";
				cin >> c;
				if (SearchNodeBST(root, c) != NULL) {
					cout << "����� ��������" << endl;
				}
				else
					cout << "����� �� �������� " << endl;
			}
			else
				cout << "�� �� �������� ��� �����";

			break;

		case 2:
			if (root == NULL) {
			cout << "�������� �������� ��� ��� ����� - ";
			cin >> value;
			CreateRootBST(root,value);
			ShowTree(root, 0);
			}
			break;

		case 3:
			if (root != NULL) {

				cout << "�������� ������� ����� - ";
				cin >> c;
				CreateRootBST(root,value);
				for (int i = 1; i < c; i++) {
					cout << "�������� �������� ��� ����� - ";
					cin >> value;
					InsertNodeBST(root,value);
				}
				ShowTree(root, 0);
			}
			else
				cout << "�� �� �������� ��� �����"<<endl;
			break;
		case 4:
			if (root != NULL) {
				cout << "�������� �������� ��� ����� ����� ������ �����:";
				cin >> value;
				Node* succ = SuccessorNodeBST(SearchNodeBST(root,value));
				cout << "����� � ��������� " << succ->key << " � successor ��� �������� " << value << endl;
			}
			else {
				cout << "�� �� �������� ��� �����" << endl;
			}
			break;
		case 5:
			if (root != NULL) {
				cout << "�������� �������� ��� ����� ����� ������ �����:";
				cin >> value;
				Node* pred = PredessorNodeBST(SearchNodeBST(root, value));
				cout << "����� � ��������� " << pred->key << " � predessor ��� �������� " << value << endl;
			}
			else 
				cout << "�� �� �������� ��� �����" << endl;
			break;
		case 6: 
			if (root != NULL) {
				cout << "�������� �������� ����� - ";
				cin >> value;
				DelNodeBST(root,value);
				ShowTree(root, 0);
			}
			if (root == NULL) {
				cout << "����� ��� ���������" << endl;
			}
			break;
		}

	} while (choice != 7);
	return 0;
}

