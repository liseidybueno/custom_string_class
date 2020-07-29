//Program Name: Project 3
//Programmer Name: Liseidy Bueno
//Attempt Number: 1
//Purpose:
//Purpose for Update: N/A
//Global Variable List: Not any

#ifndef NODEDLL_ITERATOR_H_
#define NODEDLL_ITERATOR_H_

#include <iterator>
#include <cassert>
#include "node_dll.h"

namespace DS {

    template<typename NT, typename VT>
    class node_iterator : public std::iterator<std::bidirectional_iterator_tag, NT, VT, NT&>
    {
    public:
        friend class stringlist;
        node_iterator(NT* nd = nullptr) : itr(nd) {}

        node_iterator& operator++ () // Pre-increment
        {
            itr = itr->next();
            return *this;
        }

        node_iterator operator++ (int) // Post-increment
        {
            node_iterator itr2 = node_iterator(itr);
            ++(*this);
            return itr2;
        }

        node_iterator& operator-- () // Pre-decrement
        {
            itr = itr->prev();
            return *this;
        }

        node_iterator operator-- (int) // Post-decrement
        {
            node_iterator itr2 = node_iterator(itr);
            --(*this);
            return itr2;
        }

        // two-way comparison: v.begin() == v.cbegin() and vice versa
        template<class TT>
        bool operator == (const node_iterator<TT, VT>& rhs) const
        {
            if(itr == rhs.itr)
                return true;
            else
                return false;
        }

        template<class TT>
        bool operator != (const node_iterator<TT, VT>& rhs) const
        {
            if(itr != rhs.itr)
                return true;
            else
                return false;
        }

        VT& operator* () const
        {
            return itr->data();
        }

        VT& operator-> () const
        {
            return itr->data();
        }

        // Hack to allow us to create one iterator for both const and mutator
        operator node_iterator<NT, const VT>() const
        {
            return node_iterator<NT, const VT>(itr);
        }

    private:
        NT* itr;

    };

} /* namespace DS */

#endif /* NODEDLL_ITERATOR_H_ */