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

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "LinkedList.h"
using namespace std;


int main(void)
{
  // The user's sentence
  string sentence;

  // Setup a new linked list
  LinkedList *list = new LinkedList();

  // Ask for user input
  cout << "Please input a sentence:" << endl;
  cout << "> ";

  // Obtain the input
  getline(cin, sentence);

  // Split the sentence input
  vector<string> words;
  stringstream s(sentence);
  while(!s.eof())
  {
    // Split the sentence based upon whitespace
    string tmp;
    s >> tmp;
    words.push_back(tmp);
  } 



  // Make some additions
  cout << endl 
       << "***  Additions  ***"
       << endl;

  // Add the words to a linked list
  for(int i = 0; i < words.size(); i++)
    list->addNode(words[i]);

  // print the list
  list->print();



  // Make some insertions
  cout << endl 
       << "***  Insertions  ***"
       << endl;

  list->insertNode("RAWR", 2);

  list->insertNode("RAWR", 200);

  // print the list
  list->print();



  // Remove the previous insertions
  cout << endl 
       << "***  Removals  ***"
       << endl;

  list->removeNode("RAWR", true);

  // print the list
  list->print(); 


  return 0;
}
