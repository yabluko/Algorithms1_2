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
		
		cout << "1.Алгоритм пошуку даних у бінарному дереві пошуку за ключемпошуку" << endl;
		cout << "2.Алгоритм створення  першого  вузла  (кореня)  у  бінарному  дереві пошуку" <<endl;
		cout << "3.Алгоритм вставки нового вузла у бінарне дерево пошуку" << endl;
		cout << "4.Алгоритм пошуку  термінального  вузла Successor" << endl;
		cout << "5.Алгоритм пошуку  термінального  вузла Predessor" << endl;
		cout << "6.Видалення вузла " << endl;
		cout << "7.Вихід " << endl;
		cout << "Введіть ваш вибір - ";
		cin >> choice;


		switch (choice) {
		case 1 :
			if (root != NULL) {
				cout << "Напишіть число , яке шукаєте - ";
				cin >> c;
				if (SearchNodeBST(root, c) != NULL) {
					cout << "Число знайдено" << endl;
				}
				else
					cout << "Число не знайдено " << endl;
			}
			else
				cout << "Ви не свторили рут вузол";

			break;

		case 2:
			if (root == NULL) {
			cout << "Напишіть значення для рут вузла - ";
			cin >> value;
			CreateRootBST(root,value);
			ShowTree(root, 0);
			}
			break;

		case 3:
			if (root != NULL) {

				cout << "Напишіть кількість вузлів - ";
				cin >> c;
				CreateRootBST(root,value);
				for (int i = 1; i < c; i++) {
					cout << "Напишіть значення для вузла - ";
					cin >> value;
					InsertNodeBST(root,value);
				}
				ShowTree(root, 0);
			}
			else
				cout << "Ви не створили рут вузол"<<endl;
			break;
		case 4:
			if (root != NULL) {
				cout << "Напишіть значення для вузла якого хочете найти:";
				cin >> value;
				Node* succ = SuccessorNodeBST(SearchNodeBST(root,value));
				cout << "Вузол зі значенням " << succ->key << " є successor для значення " << value << endl;
			}
			else {
				cout << "Ви не створили рут вузол" << endl;
			}
			break;
		case 5:
			if (root != NULL) {
				cout << "Напишіть значення для вузла якого хочете найти:";
				cin >> value;
				Node* pred = PredessorNodeBST(SearchNodeBST(root, value));
				cout << "Вузол зі значенням " << pred->key << " є predessor для значення " << value << endl;
			}
			else 
				cout << "Ви не створили рут вузол" << endl;
			break;
		case 6: 
			if (root != NULL) {
				cout << "Напишіть значення вузла - ";
				cin >> value;
				DelNodeBST(root,value);
				ShowTree(root, 0);
			}
			if (root == NULL) {
				cout << "Вузол був видалений" << endl;
			}
			break;
		}

	} while (choice != 7);
	return 0;
}

