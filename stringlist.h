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
//   TODO Student TODO

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include <cstdlib>  // Provides size_t
#include <iostream>  // Provides ostream & istream
#include <iterator>  // Provides iterator and forward_iterator_tag
#include "node_dll.h"
#include "node_dll_iterator.h"

namespace DS
{
    class stringlist
    {
    public:
        typedef char value_type;
        typedef DSDLL::node<value_type> node;
        typedef node_iterator<node, value_type> iterator;
        typedef node_iterator<node, const value_type> const_iterator;

        // CONSTRUCTORS and DESTRUCTOR
        stringlist();
        stringlist(const value_type str[]);
        stringlist(const stringlist& source);
        ~stringlist( );
        // MODIFICATION MEMBER FUNCTIONS
        void clear();
        void operator +=(const stringlist& addend);
        void operator +=(const value_type addend[ ]);
        void operator +=(value_type addend);
        stringlist& operator =(const stringlist& source);
        stringlist& insert(size_t pos, const value_type* s);
        stringlist& insert(size_t pos, const value_type* s, size_t n);
        iterator insert(const_iterator p, const value_type& c);

        // CONSTANT MEMBER FUNCTIONS
        bool empty() const { return charCount == 0; };
        std::size_t length( ) const { return charCount; };
        value_type operator [ ](std::size_t position) const;
        void c_str(value_type * s) const;
        int strcmp(const stringlist& right) const;
        iterator find(const stringlist& target);
        iterator find(const stringlist&, const_iterator);

        //Iterators (bidirectional)
        //Basic iterator - Return iterator to first node
        iterator begin() { return iterator(head); }
        iterator end() { return iterator(); }
        //Implicit const - Return const iterator to first node
        const_iterator begin() const { return const_iterator(head); }
        const_iterator end() const { return const_iterator(); }
        //Explicit const iterator - Return const iterator to first node
        const_iterator cbegin() const { return const_iterator(head); }
        const_iterator cend() const { return const_iterator(); }
        //Reverse iterator - Return iterator pointing to last node
        iterator rbegin() { return iterator(tail); }
        iterator rend() { return iterator(); }
        //Implicit const reverse iterator - Return const iterator pointing to last node
        const_iterator rbegin() const  { return const_iterator(tail); }
        const_iterator rend() const  { return const_iterator(); }
        //Explicit const reverse iterator - Return const iterator pointing to last node
        const_iterator crbegin() const  { return const_iterator(tail); }
        const_iterator crend() const  { return const_iterator(); }

    private:
        node* head;
        size_t charCount;
        node* tail;
        void list_copy(const node *source_ptr, node *&head_ptr, node *&tail_ptr);
    };

    // NON-MEMBER FUNCTIONS for the stringlist class
    bool operator ==(const stringlist& s1, const stringlist& s2);
    bool operator !=(const stringlist& s1, const stringlist& s2);
    bool operator >=(const stringlist& s1, const stringlist& s2);
    bool operator <=(const stringlist& s1, const stringlist& s2);
    bool operator > (const stringlist& s1, const stringlist& s2);
    bool operator < (const stringlist& s1, const stringlist& s2);
    stringlist operator +(const stringlist& s1, const stringlist& s2); //creates new object
    std::ostream& operator <<(std::ostream& outs, const stringlist& source);
    std::istream& operator >>(std::istream& ins, stringlist& target);
    std::istream& getline(std::istream& ins, stringlist& target);
}

#endif