#include "modes.h"
#include "file_stream_functions.h"

void file_stream() {
    string mask;                               //Маска для пошуку слів
    const string input_name = "input.txt";     //Файл вводу
    const string output_name = "output.txt";   //Файл виводу

    cout << "Input your text: \n";
    input(input_name);
    find_mask(input_name, output_name, mask);

    cout << "\nYour text: \n";
    read(input_name);

    cout << "Do you want to add some text(y/n)? ";
answer_point:
    char answer;
    cin >> answer;
    cin.ignore();
    if (answer == 'y' || answer == 'Y') {
        add_input(input_name);
        find_mask(input_name, output_name, mask);

        cout << "\nYour text after add: \n";
        read(input_name);
        cout << "Do you want to add some text again?(y/n)\n";
        goto answer_point;
    }
    else if (answer == 'n' || answer == 'N') {}
    else {
        incorect_answers();
        goto answer_point;
    }

    cout << "Mask format should include only 1 \"*\".\n";
    edit_mask(mask);
    find_mask(input_name, output_name, mask);
    read(output_name);
answer_mask_point:
    cout << "Do you want to input new mask(y/n)? ";
    char answer_mask;
    cin >> answer_mask;
    cin.ignore();
    if (answer_mask == 'y' || answer_mask == 'Y') {
        goto answer_mask_point;
    }
    else if (answer_mask == 'n' || answer_mask == 'N') { cout << "Program is complete!"; }
    else {
        incorect_answers();
        goto answer_mask_point;
    }
}