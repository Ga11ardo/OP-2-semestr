#include "Book.h";

int main()
{
	setlocale(LC_ALL, ".866");
	string nameKatalog = "katalog.txt";
	string AuthorsKatalog = "AuthorsKatalog.txt";
	string sortKatalog = "sortKatalog.txt";
	createKatalog(nameKatalog); //создаємо каталог
	printKatalog(nameKatalog); //виводимо каталог на екран
	addBooksToKatalog(nameKatalog); //додаємо книги до каталогу (за необхідністю)
	printKatalog(nameKatalog);
	findAuthor(nameKatalog, AuthorsKatalog); //шукаємо книги одного автора і переписуєм їх в наступний каталог
	sortAuthor(AuthorsKatalog, sortKatalog); //беремо каталог книг одного автора і сортуєм його за назвою книжок
	printKatalog(sortKatalog);
	return 0;
}
