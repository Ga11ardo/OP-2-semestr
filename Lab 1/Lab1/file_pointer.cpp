#include "modes.h"
#include "file_pointer_functions.h"

void file_pointer() {
    char mask[MAXLEN] = "";                    //Маска для пошуку слів
    char input_name[MAXLEN] = "input.txt";     //Файл вводу
    char output_name[MAXLEN] = "output.txt";   //Файл виводу

    cout << "Input your text: \n";
    input(input_name);
    //find_mask(input_name, output_name, mask);
    cout << "\nYour text: \n";
    read(input_name);

    cout << "Do you want to add some text(y/n)?";
answer_point:
    char answer;
    cin >> answer;
    cin.ignore();
    if (answer == 'y' || answer == 'Y') {
        cout << "Add your text:\n";
        add_input(input_name);
        find_mask(input_name, output_name, mask);

        cout << "\nYour text after add: \n";
        read(input_name);
        cout << "Do you want to add some text again(y/n)? ";
        goto answer_point;
    }
    else if (answer == 'n' || answer == 'N') {}
    else {
        incorect_answer();
        goto answer_point;
    }

    cout << "Mask defines which words are fit for editing. Mask format must include only 1 \"*\".\n";
    edit_mask(mask);
    find_mask(input_name, output_name, mask);
    cout << "\nLines with masks: \n";
    read(output_name);
answer_mask_point:
    cout << "Do you want to input new mask(y/n)?";
    char answer_mask;
    cin >> answer_mask;
    cin.ignore();
    if (answer_mask == 'y' || answer_mask == 'Y') {
        goto answer_mask_point;
    }
    else if (answer_mask == 'n' || answer_mask == 'N') { cout << "Program is complete!"; }
    {
        incorect_answer();
        goto answer_mask_point;
    }
}