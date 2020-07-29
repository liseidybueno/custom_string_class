//Program Name: String Class
//Programmer Name: Liseidy Bueno
//Attempt Number: 1
//Purpose: To create a custom string class using doubly linked lists as the data structure
//Purpose for Update: n/a
//Global Variable List: Not any
//
// CLASS: stringlist (a sequence of characters)
//
// CONSTRUCTOR for the stringlist class:
//   stringlist(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the stringlist class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
//   void c_str(char * s) const
//     Precondition: At least this->length()+1 bytes available at s
//     Postcondition:  Copies to s a null-terminated sequence of characters (i.e., a C-string)
//       representing the current value of the stringlist object.
//
//   int strcmp(const stringlist& right) const
//     Precondition: none
//     Postcondition: Returns an integral value indicating the relationship between the strings:
//       return value   indicates
//         -1   the first character that does not match has a lower value in *this than in right
//         0    the contents of both strings are equal
//         1    the first character that does not match has a greater value in *this than in right
//
//  iterator find(const stringlist& target) const;
//     Precondition: N/A
//     Postcondition:  Returns an iterator to the first occurrence of target from the head
//
//  iterator find(const stringlist&, const_iterator) const;
//     Precondition: iterator is a valid iterator of this object
//     Postcondition:  Returns an iterator to the first occurrence of target from the current iterator
//
// MODIFICATION MEMBER FUNCTIONS for the stringlist class:
//   void clear()
//     Erases the contents of the stringlist, which becomes an empty string (with a length of 0 characters).
//
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
//   stringlist& insert (size_t pos, const char* s, size_t n)
//     Precondition: pos >= 0 <= this->length() and n <= strlen(s)
//     Postcondition: Inserts additional characters into the stringlist right before the character indicated by pos (or p).
//       The first character is denoted by a value of 0 (not 1).
//       n: Number of characters to insert.
//       returns *this.
//
//   stringlist& insert (size_t pos, const char* s)
//     Precondition: pos >= 0 <= this->length()
//     Postcondition: Inserts additional characters into the stringlist right before the character indicated by pos (or p).
//       The first character is denoted by a value of 0 (not 1).
//       All of s is inserted into the stringlist.
//       returns *this.
//
//  iterator insert(const_iterator p, const value_type& c);
//     Precondition: p is a valid iterator on the stringlist
//     Postcondition: Inserts additional character into the string right before the character indicated by p)
//      returns an iterator pointing to the new value

// NON-MEMBER FUNCTIONS for the stringlist class:
//   stringlist operator +(const stringlist& s1, const stringlist& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, stringlist& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const stringlist& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   void getline(istream& ins, stringlist& target)
//     Postcondition: A string has been read from the istream ins. The reading
//     operation reads all characters (including white space) until a newline
//     or end of file is encountered. The newline character is read and
//     discarded (but not added to the end of the string).
//
//  VALUE SEMANTICS for the stringlist class:
//    Assignments and the copy constructor may be used with stringlist objects.
//
//  TOTAL ORDER SEMANTICS for the stringlist class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the stringlist class, forming a total order semantics, using the usual
//    lexicographic order on stringlists.
//
// DYNAMIC MEMORY usage by the stringlist class:
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, reserve, operator +=, operator +, and the
//   assignment operator.
//
// INVARIANT OF stringlist:
// The number of characters in the stringlist is in the member variable used (charCount)
// Head is the first node in the linked list that we are using as a stringlist. The head node
// is the first character of the stringlist.
// Tail is the last node in the linked list that we are using as a stringlist. The tail node
// is the last character of the stringlist.
// There is no null character at the end of the stringlist.

#include <iostream>
#include <cstdlib>

#include "stringlist.h"

namespace DS {

//Default constructor
    stringlist::stringlist() {
        charCount = 0;
        head = tail = nullptr;
    }

//Constructor that takes a null-terminated string and creates a stringlist using those characters
    stringlist::stringlist(const value_type str[]) {

        //check for empty string
        if (str[0] == '\0') {
            charCount = 0;
            head = tail = nullptr;
        } else {

            //character count is the number of characters in the string
            charCount = strlen(str);

            int i = 0;

            // create new node with the first character of
            // the string and set head and tail to the new node
            node *new_node = new node(str[0]);

            head = tail = new_node;

            while (i < charCount - 1) {
                i++;
                //set the tail to the next node and set the next node as the tail. use tail as
                //cursor
                tail = tail->next() = new node(str[i], nullptr, tail);
            }

        }

    }

//copy constructor
    stringlist::stringlist(const stringlist &source) {
        //if the source is empty, the new stringlist should also be empty
        if (source.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            charCount = 0;
        } else {
            //copy source into this stringlist
            list_copy(source.head, head, tail);
            charCount = source.charCount;
        }
    }

// destructor
    stringlist::~stringlist() {
        clear();
    }

//clears all nodes in the linked list
    void stringlist::clear() {
        node *remove_ptr;

        while (head != nullptr) {
            remove_ptr = head;
            head = head->next();
            delete remove_ptr;
        }

        charCount = 0;

    }

//  adds another stringlist to the end of the current stringlist
    void stringlist::operator+=(const stringlist &addend) {

        //create new nodes for head and tail
        node *copy_head_ptr;
        node *copy_tail_ptr;

        //copy the addend into the end of the original stringlist
        if (addend.charCount > 0) {
            list_copy(addend.head, copy_head_ptr, copy_tail_ptr);
            tail->setNext(copy_head_ptr);
            tail = tail->next();
        }

        charCount += addend.charCount;

    }

//add a null-terminated string to the end of a stringlist
    void stringlist::operator+=(const value_type addend[]) {

        int i = 0;

        //up until the end of the string, create a new node with the next character as the data
        // and add it to the tail. set the next node as the tail to iterate through the stringlist.
        while (i < strlen(addend)) {
            node *insert_ptr = new node(addend[i], nullptr, tail);
            tail->setNext(insert_ptr);
            tail = tail->next();
            i++;
        }

        charCount += strlen(addend);
  }

//add a character to the end of a stringlist
    void stringlist::operator+=(value_type addend) {

        if (head == nullptr) {
            //if the stringlist is empty, addend will be the first node of a new list
            head = new node(addend, nullptr, nullptr);
            tail = head;
        } else {
            //create a new node for the tail and set addend as the data
            tail = tail->next() = new node(addend, nullptr, tail);
        }

        charCount++;
 }

//assignment operator
    stringlist &stringlist::operator=(const stringlist &source) {

        //check for self-assignment
        if (this == &source) {
            return *this;
        }

        //clear this
        this->clear();

        if (source.head == nullptr) {
            head = nullptr;
            tail = nullptr;
            charCount = 0;
        } else {
            list_copy(source.head, head, tail);
            charCount = source.charCount;
        }

         return *this;
    }

//insert the string s at position pos
    stringlist &stringlist::insert(size_t pos, const value_type *s) {
        int i = 0;
        int j = 0;

        node *cursor = head;


        while (j < length()) {
            if (j == (pos - 1)) {
                while (i < strlen(s)) {
                    //create a new node with the data of s at the current index
                    //set new node to the next node
                    //set the cursor to the next node
                    node *insert_ptr = new node(s[i], cursor->next(), cursor->prev());
                    cursor->setNext(insert_ptr);
                    cursor = cursor->next();
                    i++;
                }
            }
            j++;
            cursor = cursor->next();
        }

        charCount += strlen(s);

        return *this;
    }

//insert a string at position s, but only insert n amount of characters in s
    stringlist &stringlist::insert(size_t pos, const value_type *s, size_t n) {
        int i = 0;
        int j = 0;

        node *cursor = head;

        while (j < length()) {
            if (j == (pos)) {
                //same as above but only as long as n is
                while (i < n) {
                    node *insert_ptr = new node(s[i], cursor->next(), cursor->prev());
                    cursor->setNext(insert_ptr);
                    cursor = cursor->next();
                    i++;
                }
                break;

            }
            j++;
            cursor = cursor->next();
        }

        charCount += (strlen(s) - n);
        return *this;
    }

//Inserts additional character into the string right before the character indicated by p
// returns an iterator pointing to the new value
    stringlist::iterator stringlist::insert(const_iterator p, const value_type &c) {
        iterator itr;
        node *cursor = head;

        while (cursor != nullptr) {
            if (cursor->data() == *p) {
                node *insert_ptr = new node(c, cursor->prev()->next(), cursor->prev()->prev());
                cursor->prev()->setNext(insert_ptr);
                cursor = cursor->next();
            }
            cursor = cursor->next();
        }

        itr = cursor;

        charCount += 1;

        return itr;
    }

//The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at
    stringlist::value_type stringlist::operator[](std::size_t position) const {

        node *cursor = head;

        int i = 0;

        while (cursor != nullptr) {
            if (i == position)
                return cursor->getData();
            cursor = cursor->next();
            i++;
        }
    }

//Copies to s a null-terminated sequence of characters (i.e., a C-string)
//representing the current value of the stringlist object.
    void stringlist::c_str(value_type *s) const {

        size_t i = 0;

        node * cursor = head;

        while(cursor != nullptr){
            s[i] = cursor->getData();
            cursor = cursor->next();
            ++i;
        }

        s[i] = '\0';

    }

//Returns an integral value indicating the relationship between the strings:
//       return value   indicates
//         -1   the first character that does not match has a lower value in *this than in right
//         0    the contents of both strings are equal
//         1    the first character that does not match has a greater value in *this than in right
    int stringlist::strcmp(const stringlist &right) const {

        //two cursors, one pointing to the left & one to the right
        node *cursor_right = right.head;
        node *cursor_left = head;

        while (cursor_left != nullptr && cursor_right != nullptr) {
            //move cursor to next
            if (cursor_left->getData() == cursor_right->getData()) {
                //if they're equal, continue to iterate
                cursor_left = cursor_left->next();
                cursor_right = cursor_right->next();
            } else if (cursor_left->getData() > cursor_right->getData()) {
                //if the left is greater than the right, return 1
                return 1;
            } else
                // if the right is greater than the left, return -1
                return -1;
        }

        if (right.length() == this->length())
            //if they're the same length AND equal, return 0
            return 0;
        else if (right.length() < this->length())
            //if they're equal up until the right one ends, return 1
            return 1;
        else if (this->length() < right.length())
            //if they're equal up until the left one ends, return -1
            return -1;

    }

//     Postcondition:  Returns an iterator to the first occurrence of target from the head
    stringlist::iterator stringlist::find(const stringlist &target) {
        node * cursor_this = head;
        node * cursor_target = target.head;

        while(cursor_target != nullptr)
        {
            if (cursor_this->getData() == cursor_target->getData()) {
                while (cursor_target != nullptr) {
                    //if both data sets are equal, iterate again to see if they are equal through
                    //target
                    if (cursor_this->getData() == cursor_target->getData()) {
                        cursor_target = cursor_target->next();
                        cursor_this = cursor_this->next();
                    } else {
                        return nullptr;
                    }
                }
                return target.head;
            } else if(cursor_this->getData() != cursor_target->getData()) {
                //if they are not equal, continue to iterate through this
                cursor_this = cursor_this->next();
            }
        }

    }

// similar to previous find function but start at itr instead of head
    stringlist::iterator stringlist::find(const stringlist &target, const_iterator itr) {
        node * cursor_this = head;
        value_type data = *itr;
        node * cursor_target = target.head;

        while(cursor_this != nullptr)
        {
            if (cursor_this->getData() == data) {
                while (cursor_target != nullptr) {
                    if (cursor_this->getData() == cursor_target->getData()) {
                        cursor_target = cursor_target->next();
                        cursor_this = cursor_this->next();
                    } else {
                        return nullptr;
                    }
                }
                return target.head;
            } else
                cursor_this = cursor_this->next();
        }

    }



//PRIVATE FUNCTIONS

//Precondition: source_ptr is not empty
//Postcondition: copies source linked list into a new linked list
    void stringlist::list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr) {
        head_ptr = nullptr;
        tail_ptr = nullptr;

        //handle empty list
        if (source_ptr == nullptr)
            return;

        //create new head node for the newly created list and put data in it
        head_ptr = new node(source_ptr->getData());
        tail_ptr = head_ptr;

        source_ptr = source_ptr->next();
        node *insert_ptr;
        while (source_ptr != nullptr) {
            insert_ptr = new node(source_ptr->data(), nullptr, tail_ptr);
            tail_ptr->setNext(insert_ptr);
            tail_ptr = tail_ptr->next();
            source_ptr = source_ptr->next();
        }

    }

    //NONMEMBER FUNCTIONS

    bool operator==(const stringlist &s1, const stringlist &s2) {

        return s1.strcmp(s2) == 0;

    }

    bool operator!=(const stringlist &s1, const stringlist &s2) {

        return s1.strcmp(s2) != 0;
    }

    bool operator>=(const stringlist &s1, const stringlist &s2) {

        return s2.strcmp(s1) == -1 || s1.strcmp(s2) == 0;

    }

    bool operator<=(const stringlist &s1, const stringlist &s2) {
        return s2.strcmp(s1) == 1 || s1.strcmp(s2) == 0;
    }

    bool operator>(const stringlist &s1, const stringlist &s2) {
        return s2.strcmp(s1) == -1;
    }

    bool operator<(const stringlist &s1, const stringlist &s2) {
        return s2.strcmp(s1) == 1;
    }


//   stringlist operator +(const stringlist& s1, const stringlist& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
    stringlist operator+(const stringlist &s1, const stringlist &s2) { //creates new object

        stringlist answer = s1;

        answer = s2;

        return answer;

    }


//   The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
    std::ostream &operator<<(std::ostream &outs, const stringlist &source) {

        int i = 0;

        while (i < source.length()) {
            outs << source[i];
            ++i;
        }

        return outs;
    }

//  A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
    std::istream &operator>>(std::istream &ins, stringlist &target) {

        char c;

//ignore spaces, new lines and tabs in the beginning of the input stream
        while (ins && (ins.peek() == '\n' || ins.peek() == ' ' || ins.peek() == '\t')) {
            ins.ignore();
        }

        //only read up until there is a space, new line, a tab, or the end of the stream
        while (ins && (ins.peek() != '\n' || ins.peek() != ' ' || ins.peek() != '\t')) {
            ins >> c;
            target += c;
            if(!ins || (ins.peek() == '\n' || ins.peek() == ' ' || ins.peek() == '\t'))
                break;
        }

        return ins;
    }

//   A string has been read from the istream ins. The reading
//     operation reads all characters (including white space) until a newline
//     or end of file is encountered. The newline character is read and
//     discarded (but not added to the end of the string).
    std::istream& getline(std::istream& ins, stringlist& target){

        char c;

        target.clear();

        //read in until there is a new line
        while(ins && (ins.peek() != '\n')){
            ins >> c;
            target += c;
        }

        //ignore the new line
        if(ins.peek() == '\n')
            ins.ignore();

        return ins;
    }

}