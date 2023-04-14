#include "Book.h";

//функція створення каталогу
void createKatalog(string name) { 
	int n;
	Book b;
	ofstream fOut(name, ios::binary);
	cout << "Input number of books: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "\nInput title: ";
		cin.getline(b.title, MAX_LETTERS);
		cout << "Input author: ";
		cin.getline(b.author, MAX_LETTERS);
		cout << "Input language: ";
		cin.getline(b.language, MAX_LETTERS);
		cout << "Input year of publication: ";
		cin >> b.year_of_publication;
		cout << "Input numbers of copies: ";
		cin >> b.num_of_copies;
		fOut.write((char*)&b, sizeof(Book));
	}
	fOut.close();
}

//функція виводу каталогу на екран
void printKatalog(string name) { 
	Book b;
	int num_of_book = 1;
	ifstream fIn(name, ios::binary);
	cout << "\nList of books: \n";
	while (fIn.read((char*)&b, sizeof(Book))) {
		cout << "--------------------------------------------\n";
		cout << "Book number " << num_of_book << ":\n";
		cout << "Title of book: " << b.title << "\n";
		cout << "Author of book: " << b.author << "\n";
		cout << "Language of book: " << b.language << "\n";
		cout << "Publication year of book: " << b.year_of_publication << "\n";
		cout << "Copies of book: " << b.num_of_copies << "\n";
		num_of_book++;
	}
	cout << "--------------------------------------------\n";
	fIn.close();
}

//функція додавання книг до каталогу
void addBooksToKatalog(string name) { 
	int n;
	Book b;
	char answer;
answer_point:
	cout << "\nDo you want to add some books to the katalog? (y/n)";
	cin >> answer;
	cin.ignore();
	if (answer == 'y' || answer == 'Y') {
		ofstream fOut(name, ios::binary | ios::app);
		cout << "Input number of books you want to add to the katalog: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin.ignore();
			cout << "\nInput title: ";
			cin.getline(b.title, MAX_LETTERS);
			cout << "Input author: ";
			cin.getline(b.author, MAX_LETTERS);
			cout << "Input language: ";
			cin.getline(b.language, MAX_LETTERS);
			cout << "Input year of publication: ";
			cin >> b.year_of_publication;
			cout << "Input numbers of copies: ";
			cin >> b.num_of_copies;
			fOut.write((char*)&b, sizeof(Book));
		}
		fOut.close();
	}
	else if (answer == 'n' || answer == 'N') {}
	else {
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		cout << "!!!Uncorect answer, please try again!!!\n";
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
		goto answer_point;
	}
}

//функція знаходжкння книг одного автора і запис їх до каталогу
void findAuthor(string name, string nameOut) {
	Book b;
	string author;
	bool authorBooks = 0;
	int num_of_book = 1;
	ifstream fIn(name, ios::binary);
	cout << "\nEnter the author`s name: ";
	cin >> author;
	cin.ignore();
	ofstream fOut(nameOut, ios::binary);
	while (fIn.read((char*)&b, sizeof(Book))) {
		if (b.author == author) {
			if (authorBooks == 0) {
				cout << "Book(s) of " << author << " : \n";
				authorBooks = 1;
			}
			cout << "===========================================\n";
			cout << "Book number " << num_of_book << ":\n";
			cout << "Title of book: " << b.title << "\n";
			cout << "Language of book: " << b.language << "\n";
			cout << "Publication year of book: " << b.year_of_publication << "\n";
			cout << "Copies of book: " << b.num_of_copies << "\n";
			num_of_book++;
			fOut.write((char*)&b, sizeof(Book));
		}
	}
	cout << "===========================================\n";
	cout << "In katalog we have " << num_of_book - 1 << " books with " << author << " author.\n";
	fOut.close();
	fIn.close();
}

/*функція сортування книг одного автора за алфавітним порядком назв книг
і запис відсортованих книг в новий каталог*/
void sortAuthor(string name, string nameOut) {
	Book b;
	int authorAmount = 0;
	ifstream fIn(name, ios::binary);
	ofstream fOut(nameOut, ios::binary);
	string author;
	cout << "\nEnter the author`s name to sort the katalog: ";
	cin >> author;
	cin.ignore();
	while (fIn.read((char*)&b, sizeof(Book))) {
		if (b.author == author) {
			authorAmount++;
		}
	}
	fIn.close();
	fIn.open(name, ios::binary);
	Book* Authors = new Book[authorAmount];
	int i = 0;
	while (fIn.read((char*)&b, sizeof(Book))) {
		Authors[i] = b;
		i++;
	}
	fIn.close();
	for (int i = 0; i < authorAmount - 1; i++) {
		for (int j = 0; j < authorAmount - i - 1; j++) {
			string temp_title = Authors[j].title;
			int temp_lenght = temp_title.length();
			for (int k = 0; k < temp_lenght; k++) {
				if (Authors[j].title[k] < Authors[j + 1].title[k]) {
					break;
				}
				if (Authors[j].title[k] > Authors[j + 1].title[k]) {
					swap(Authors[j], Authors[j + 1]);
					break;
				}
			}
		}
	}
	for (int i = 0; i < authorAmount; i++) {
		fOut.write((char*)&Authors[i], sizeof(Book));
	}
	fOut.close();
}