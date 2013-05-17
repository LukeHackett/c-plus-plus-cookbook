/******************************************************************************
 *  Copyright 2013 Luke Hackett
 *  https://github.com/LukeHackett/
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *****************************************************************************/

#include <cstddef>
#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;


/**
 * Primary Constructor
 */
LinkedList::LinkedList()
{
  head = NULL;
}

/**
 * This method will add a new node to the end of the linked list. The data 
 * associated with the new node will be the given value.
 * 
 * @param  value  the string value to add
 */
void LinkedList::addNode(string value)
{
  // Setup a new new
  Node *node = new Node;
  node->data = value;
  node->prev = NULL;
  node->next = NULL;

  // Add to the head if first in the list
  if(head == NULL)
  {
    head = node;
  }
  else
  {
    // Add to the end of the list
    Node *p;
    p = head;

    // Find the last node
    while(p->next != NULL)
      p = p->next;

    node->prev = p;
    p->next = node;
  }
}

/**
 * This method will insert a new node with the given value into the given index
 * location. If the location is out of bounds, the node will be appended to the
 * end of the list.
 *
 * @param  value  the string value to add
 * @param  index  the index location to insert to
 */
void LinkedList::insertNode(string value, int index)
{
  // Add to the end of the list if easier
  if(index > size())
  {
    addNode(value);
    return;
  }

  // Ensure the index is a positive number
  index = (index < 0) ? 0 : index;

  // Current location counter
  int location = 0;

  // Setup a new new
  Node *node = new Node;
  node->data = value;
  node->prev = NULL;
  node->next = NULL;

  // Make a temp copy of the list
  Node *p = head;

  // loop over all known values
  while(index >= location)
  {
    // Check to see if an insert is to be made here
    if(index == location)
    { 
      // Set the new next node to the current node
      node->next = p;

      // Set the previous node to the current node's previous node
      node->prev = p->prev;

      // Update the previous next node if present
      if(p->prev != NULL)
        p->prev->next = node;

      // Put the new node in the list
      p->prev = node;

      // Set the new node as the head if required
      if(index == 0)
        head = node;

      break;
    }

    // Get the next element or the last element
    p = (p->next == NULL) ? p : p->next;

    // Increment the location counter
    location++;
  }
}

/**
 * This method will remove the first occurrence of the given node from the list.
 * If all occurrences should be removed, then a deep search should be used, as 
 * this will force the method to visit all nodes. 
 * 
 * @param  value  the string value to remove
 * @param  deep   whether or not to stop at the first matched instance
 */
void LinkedList::removeNode(string value, bool deep = false)
{
  Node *p = head;

  // loop over all known values
  while(true)
  {
    // Check for a match
    if(p->data == value)
    {
      // Update the link 
      p->prev->next = (p->next == NULL) ? NULL : p->next;

      if(p->next != NULL)
        p->next->prev = (p->prev == NULL) ? NULL : p->prev;

      // finish early if requested
      if(!deep)
      {
        break;
      }
    }

    // has the end been reached
    if(p->next == NULL)
      return;

    // Get the next element
    p = p->next;
  }
}

/**
 * This method will find and return a given node based upon it's data value. If
 * no node can be found, NULL is returned.
 *
 * @param   value  the string value to find
 * @return  Node
 */
Node* LinkedList::findNode(string value)
{
  Node *p = head;

  // loop over all known values
  while(true)
  {
    // Check for a match
    if(p->data == value)
    {
      return p;
    }

    // has the end been reached
    if(p->next == NULL)
      return NULL;

    // Get the next element
    p = p->next;
  }
}

/**
 * This method will return the number of nodes in this list.
 *
 * @return  int
 */
int LinkedList::size()
{
  // Default size
  int size = 0;

  // Temp copy of the list
  Node *p = head;

  // Loop over all known elements
  while(p->next != NULL)
  {
    // increment the size
    size++;

    // Get the next element
    p = p->next;
  }

  return size;
}

/**
 * This method will print all nodes within the linked list, displaying the 
 * previous linked node, and the next linked nodes (if available).
 */
void LinkedList::print()
{
  Node *p = head;

  while(p != NULL)
  { 
    // Get the previous node
    string prev = (p->prev == NULL) ? "NULL" : p->prev->data;

    // Get the next node
    string next = (p->next == NULL) ? "NULL" : p->next->data;

    // Output the node
    cout << p->data << " (prev=" << prev << " next=" << next << ")" << endl;

    // Obtain the next node
    p = p->next;
  }
}
