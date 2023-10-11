#include "singleLinkedList.h"
// Note: Most of this is modified from 201R code
// Got some help from Kevin & Hallee on some functions as well
// Also thanks to https://www.educative.io/answers/singly-linked-list-in-cpp

// Creates empty single linked list
Single_Linked_List::Single_Linked_List() {
  head = NULL;
  tail = NULL;
  num_items = 0;
}

// Adds nodes to the front, and if empty it makes it the header
void Single_Linked_List::push_front(const Item_Type &item) {
  Node *newNode = new Node(item);
  // Adds a new node if the list isn't empty to the front
  if (head != NULL) {
    newNode->next = head;
    head = newNode;
    num_items++;
  }
  // Adds a new node as the head if not empty
  else {
    head = newNode;
    head->next = NULL;
    tail = newNode;
    num_items++;
  }
}

// Adds node to the back
void Single_Linked_List::push_back(const Item_Type &item) {
  Node *newNode = new Node(item);
  // Add node as head & tail if empty
  if (head == NULL) {
    head = newNode;
    head->next = NULL;
    tail = newNode;
    num_items++;
  }
  // Add node to the tail if not empty
  else {
    tail->next = newNode;
    tail = newNode;
    tail->next = NULL;
    num_items++;
  }
}

// Deletes first node
void Single_Linked_List::pop_front() {
  try {
    // Error checking to see if it's empty
    if (head == NULL) {
      throw runtime_error("List is empty\n");
    } else {
      Node *delNode = head;
      head = head->next;
      delete delNode;
      num_items--;
    }
  } catch (runtime_error e) {
    cout << e.what();
  }
}

// Delete node from the back
void Single_Linked_List::pop_back() {
  try {
    // Error checking to see if it's empty
    if (head == NULL) {
      throw runtime_error("List is empty\n");
    } else if (head == tail) {
      this->pop_front();
      num_items--;
    } else {
      Node *temp = head;
      while (temp->next != tail) {
        temp = temp->next;
      }
      tail = temp;
      temp = temp->next;
      delete temp;
      tail->next = NULL;
      num_items--;
    }
  } catch (runtime_error e) {
    cout << e.what();
  }
}

// Return first item
Item_Type &Single_Linked_List::front() {
  try {
    // Error checking to see if it's empty
    if (head == NULL) {
      throw runtime_error("List is empty\n");
    } else {
      return head->data;
    }
  } catch (runtime_error e) {
    cout << e.what();
  }
}

// Return last item
Item_Type &Single_Linked_List::back() {
  try {
    // Error checking to see if it's empty
    if (tail == NULL) {
      throw runtime_error("List is empty\n");
    } else {
      return tail->data;
    }
  } catch (runtime_error e) {
    cout << e.what();
  }
}

// Is list empty?
bool Single_Linked_List::empty() const {
  if (head == NULL) {
    return true;
  } else {
    return false;
  }
}

// Parameters: index of where to insert, and data item to be inserted at the
// index
void Single_Linked_List::insert(size_t index, const Item_Type &item) {
  // Error checking to see if it's negative
  try {
    if (index < 0) {
      throw runtime_error("Invalid index\n");
    }
  } catch (runtime_error e) {
    cout << e.what() << endl;
  }
  // Insert in beginning?
  Node *newNode = new Node(item);
  if (index == 0) {
    this->push_front(item);
    num_items++;
  }
  // Insert in the end if index is out of scope
  else if (index >= num_items - 1) {
    this->push_back(item);
    num_items++;
  } else {
    Node *tempNode = head;
    for (int i = 0; i < num_items; i++) {
      if (i + 1 == index) {
        newNode->next = tempNode->next;
        tempNode->next = newNode;
        num_items++;
        return;
      } else {
        tempNode = tempNode->next;
      }
    }
  }
}

// Remove given index
bool Single_Linked_List::remove(size_t index) {
  // Error checking to see if it's empty
  if (this->empty()) {
    cout << "List is empty\n" << endl;
    return false;
  } else if (index == 0) {
    this->pop_front();
    num_items--;
    return true;
  } else if (index == num_items - 1) {
    this->pop_back();
    num_items--;
    return true;
  }
  // Insert in the end if index is out of scope
  else if (index > num_items - 1) {
    cout << "Index is beyond the end of the list\n";
    return false;
  }
  // Deletion
  Node *tempNode = head;
  for (int i = 0; i < num_items; i++) {
    if (i + 1 == index) {
      tempNode->next = tempNode->next->next;
      num_items--;
      return true;
    } else {
      tempNode = tempNode->next;
    }
  }
  return false;
}

// Return node of first occurance
size_t Single_Linked_List::find(const Item_Type &item) {
  // Error checking to see if it's empty
  if (head == NULL) {
    cout << "Item not in list\n";
    return num_items;
  }
  Node *tempNode = head;
  for (int i = 0; i < num_items - 1; i++) {
    if (tempNode->data.num == item.num) {
      return i;
    } else {
      tempNode = tempNode->next;
    }
  }
  cout << "Item not in list\n";
  return num_items;
}

// Prints the list
void Single_Linked_List::printList() {
  Node *tempPtr = head;
  while (tempPtr != NULL) {
    cout << tempPtr->data.num << " -> ";
    tempPtr = tempPtr->next;
  }
  cout << endl << endl;
}
