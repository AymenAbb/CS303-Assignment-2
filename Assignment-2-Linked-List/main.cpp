#include "singleLinkedList.h"

int main() {
  Single_Linked_List list; // initlization
  int choice = -1;
  int initialInput;
  size_t secondInput; // Workaround for handling new inputs
  Item_Type temp;

  // Menu Selection, there has to be a better way of doing this
  cout << "What operation would you like to do to the list?" << endl;
  cout << "  1 - push_front" << endl;
  cout << "  2 - push_back" << endl;
  cout << "  3 - pop_front" << endl;
  cout << "  4 - pop_back" << endl;
  cout << "  5 - front" << endl;
  cout << "  6 - back" << endl;
  cout << "  7 - empty" << endl;
  cout << "  8 - Insert item at position index" << endl;
  cout << "  9 - Remove the item at position index" << endl;
  cout << "  10 - Return position of the first occurrence of item" << endl;
  cout << "  11 - Quit" << endl << endl;

  // While not quit
  while (choice != 11) {
    cout << "> ";
    cin >> choice;
    cout << endl;

    switch (choice) {

    case 1: // push_front
      cout << "What item would you like to add to the front? ";
      cin >> initialInput;
      temp.num = initialInput;
      list.push_front(temp);
      break;

    case 2: // push_back
      cout << "What item would you like to add to the end? ";
      cin >> initialInput;
      Item_Type temp;
      temp.num = initialInput;
      list.push_back(temp);
      break;

    case 3: // pop_front
      list.pop_front();
      break;

    case 4: // pop_back
      list.pop_back();
      break;

    case 5: // front
      cout << "First item: " << list.front().num << endl;
      break;

    case 6: // back
      cout << "Last item: " << list.back().num << endl;
      break;

    case 7: // empty
      if (list.empty() == true) {
        cout << "The list is empty\n" << endl;
      } else {
        cout << "The list is not empty" << endl;
      }
      break;

    case 8: // insert
      cout << "What item would you like to insert? ";
      cin >> initialInput;
      temp.num = initialInput;
      cout << "\nAt what index would you like to insert the item? ";
      cin >> secondInput;
      list.insert(initialInput, temp);
      break;

    case 9: // remove
      cout << "What index would you like to remove the item from? ";
      cin >> secondInput;
      list.remove(secondInput);
      break;

    case 10: // find
      cout << "What would you like to find in the list? ";
      cin >> initialInput;
      temp.num = initialInput;
      cout << list.find(temp) << endl;
      break;

    case 11: // terminate
      cout << "Your list is:" << endl;
      list.printList();
      cout << "Good bye!" << endl;
      exit(0);
    }

    cout << "Current List:" << endl;
    list.printList();

    cout << "Type new selection" << endl;
  }
}