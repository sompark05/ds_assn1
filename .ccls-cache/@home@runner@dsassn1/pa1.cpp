// 박소망 20230689

#include "utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

/*
    [Task 1] Choose the time complexity of the following factorial function

    *factorial*
        Input
        - int n: An integer n >= 1
        Output
        - int: factorial of n(n!), which is the product of all integers from 1
   to n

        int factorial(int n){
          int f[n+1];
          f[0] = 1;
          for (int i=1; i<=n; i++){
            f[i] = i * f[i+1];
          }
          return f[n];
        }

    Choices
        1: O( 1 )
        2: O( n )
        3: O(log(n))
        4: O(n^2)
*/
void task_1(ofstream &fout) {
  int answer = 2; // TODO: Change to your answer

  fout << "[Task 1]" << endl;
  fout << answer << endl;

  return;
}
// =================================
// End of Task1
// =================================

/*
    [Task 2] Choose the time complexity of the following sumOfPrimes function.

    *sumOfPrimes*
        Input
        - int n: An integer n >= 2
        Output
        - int: The sum of all primes up to and including n

      int isPrime(int number){
        if(number <= 1) return 0;
        for(int i=2; i*i<=number; i++){
          if(number % i == 0) return 0;
        }
        return 1
      }

      int sumOfPrimes(int n){
        int sum = 0;
        for(int i=2; i<=n; i++){
          if(isPrime(i)) {
            sum += i;
          }
        }
        return sum;
      }

    Choices
        1: O( log(n) )
        2: O( nlog(n) )
        3: O( n^1.5 )
        4: O( n^2 )
*/
void task_2(ofstream &fout) {
  int answer = 3; // TODO: Change to your answer

  fout << "[Task 2]" << endl;
  fout << answer << endl;

  return;
}
// =================================
// End of Task2
// =================================

/*
    [Task 3] List

    Description:
        Implement a function that can insert or delete an integer into the list.
        An user can insert an element in descending order
        or delete an element at the specific index.
        If the specified index is out of range of the given list, print “ERROR”.

    Input:
        Sequence of commands, which is one of the following
        - (‘insert’,integer value): insert integer value at the appropriate
   position in the list, while ensuring that the elements within the array are
   always in descending order. index indicates zero-based index.
        - (‘delete’,index): delete an element at the index in the list.
        - Index indicates zero-based index.

    Output:
        - After inserting or deleting elements in an array, the resulting string
   should               have spaces between each element, but no space after the
   last element.
        - “ERROR” if the index is out of range
*/

void task_3(ofstream &fout, InstructionSequence *instr_seq) {
  string answer;

  int array[10000] = {-1};
  int size = 0;

  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    int value = instr_seq->instructions[i].value;

    // if insert command
    if (command.compare("insert") == 0) {
      // if the array is is empty, insert the value at the first index
      if (size == 0) {
        array[0] = value;
        size++;
        continue;
      }

      // if the array is not empty, insert the value in descending order
      int cursor = 0;
      for (; cursor < size; cursor++) {
        if (value < array[cursor]) {
          continue;
        }
        break;
      };

      for (int i = size; i > cursor; i--) {
        array[i] = array[i - 1];
      }
      array[cursor] = value;
      size++;
    }
    // else if delete command
    else if (command.compare("delete") == 0) {
      // 빈 리스트라면 ERROR 출력
      if (size == 0) {
        // cout << "ERROR";
        // break;
        fout << "[Task 3]" << endl;
        fout << "ERROR" << endl;
        return;
      }

      if (value >= size) {
        // cout << "ERROR";
        // break;
        fout << "[Task 3]" << endl;
        fout << "ERROR" << endl;
        return;
      }
      for (int i = value; i < size; i++) {
        array[i] = array[i + 1];
      };
      size--;
    } else {
      cerr << "Invalid command" << endl;
      exit(-1);
    }
  }

  // insert elements of array into answer
  for (int i = 0; i < size; i++) {
    answer += to_string(array[i]) + " ";
  }
  answer = answer.substr(0, answer.size() - 1);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////

  fout << "[Task 3]" << endl;
  fout << answer << endl;
}
// =================================
// End of Task3
// =================================

/*
    [Task 4] Palindrome checker / Stack

    Description:
        b.	Implement a stack and a function IsPalindrome.
        This function returns a Boolean indicating whether the given string is a
   palindrome, utilizing the stack you implemented.

    Input:
        A string containing at least on alphabetical character. Input is
   case-insensitive (i.e., disregard differences between uppercase and lowercase
   letters). Non-alphabetical inputs should be ignored.

      Example )
      1. mom
      2. anna
      3. level

    Output:
        -	TRUE : If the given string is palindrome.
        -	FALSE : If the given string is not palindrome


*/

/* DO NOT CHANGE */

struct stack {
  char value;
  stack *next;
};

struct Top {
  int count;
  struct stack *head;
};

/* DO NOT CHANGE */

/////////////////////////////////////////////////////////
//////////  TODO: Implement From Here      //////////////
char pop(Top *top) {
  int value = top->head->value;
  top->head = top->head->next;
  return value;
}

void push(char exp, Top *top) {
  stack *newNode = new stack;
  newNode->value = exp;
  newNode->next = top->head;
  top->head = newNode;
}

bool IsPalindrome(string word) {
  Top *top = new Top;
  top->count = 0;
  for (int i = 0; i < word.size() / 2; i++) {
    push(tolower(word[i]), top);
    top->count++;
  }

  for (int i = (word.size() / 2) + (word.size() % 2); i < word.size(); i++) {
    if (pop(top) != tolower(word[i])) {
      return false;
    }
  }
  return true;
}
///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////

void task_4(ofstream &fout, string expression) {
  string answer;

  if (IsPalindrome(expression))
    answer = "TRUE";
  else
    answer = "FALSE";

  fout << "[Task 4]" << endl;
  fout << answer << endl;
}

// =================================
// End of Task4
// =================================

/*
    [Task 5] Queue

    Description:
        Implement a function that shows the values in a priority queue without
   using heap. We “enqueue” values in the queue and “dequeue” the front value
   (first inserted value). If “dequeue” operation is called for an empty queue,
   you should print “EMPTY”.

    Command:
        -	('enqueue',integer): enqueue integer into the current queue
        -	('dequeue',0): dequeue the front value from the current queue.
        -	('peek',0): print the front value
        -	('show',0): show all values in queue (ex : value)  in descending
   order of priority (check the example below). If empty, print nothing.

    Caution:
        -	There should be a space between two outputs.
*/

void task_5(ofstream &fout, InstructionSequence *instr_seq) {
  string answer;
  string queue;
  int size = 0;

  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////

  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    int value = instr_seq->instructions[i].value;

    if (command.compare("enqueue") == 0) {
      queue += to_string(value) + "\n";
      size += to_string(value).size() + 1;
    } else if (command.compare("dequeue") == 0) {
      if (size == 0) {
        answer += "EMPTY\n";
      } else {
        int front = 1;
        while (queue[front] != '\n') {
          front++;
        }
        queue = queue.substr(front + 1, queue.size());
        size -= front + 1;
      }
    } else if (command.compare("peek") == 0) {
      if (size == 0) {
        continue;
      }

      for (int i = 0; i < size; i++) {
        if (queue[i] == '\n') {
          break;
        }
        answer += queue[i];
      }
      answer += "\n";
    } else if (command.compare("show") == 0) {
      if (size == 0) {
        continue;
      }
      for (int i = 0; i < size; i++) {
        answer += string(1, queue[i]);
      }

    } else {
      cerr << "Invalid command" << endl;
      exit(-1);
    }
  }
  answer = answer.substr(0, answer.size() - 1);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////

  fout << "[Task 5]" << endl;
  fout << answer << endl;
}
// =================================
// End of Task5
// =================================

// Task 6, Answer code is as below
// =====================================================================================

/*
    [Task 6] Priority Queue

    a.	Implement a function that shows the values in a priority queue without
   using heap. We “enqueue” values in the queue with specific priorities
   (priority is an integer starting from 1, and we define 1 as the highest
   priority), and “dequeue” value with the highest priority. If “dequeue”
   operation is called for an empty queue, you should print “EMPTY”.

    	We set the max size of queue as 100(Check the code) and we will not test
   over the maximum size. You don’t need exceptions for this situation. 
   We will not consider values with same priority. 	You don’t need to
   consider exceptions for inputs other than (‘enqueue’, integer), (‘priority’,
   integer).

    b.	Input & Output (integer value & priority range: 1 to 99)
    Input:  Sequence of commands, which is one of the following,
    -	(‘enqueue’,integer): enqueue integer into the current queue
    -	(‘priority’,integer): specify the value’s priority by integer. If you
   command “enqueue”, you MUST command “priority” right after it. -
   (‘dequeue’,0): dequeue the highest priority value from the current queue. -
   (‘peek’,0): print the highest priority value and its priority -
   (‘show’,0): show all values in queue with its priority in ascending order of
   priority (Please check the example below). If empty, do not print anything.


    * You don't need to exactly follow the structure. It is just a guide for you
   to implement Task 6.
*/

const int MAX_SIZE = 100; // Maximum queue size
int queue[MAX_SIZE][2];   // 2D array to store values and their priorities
int queueSize = 0;        // Current size of the queue

// Function to insert an element based on its priority
void insertWithPriority(int value, int priority) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  queue[priority][0] = priority;
  queue[priority][1] = value;
  queueSize++;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

// Function to process instructions
void task_6(ofstream &fout, InstructionSequence *instr_seq) {
  string answer = "";
  int temp;
  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    int value = instr_seq->instructions[i].value;

    if (command == "enqueue") {
      /////////////////////////////////////////////////////////
      //////////  TODO: Implement From Here      //////////////
      temp = value;
      ///////////      End of Implementation      /////////////
      /////////////////////////////////////////////////////////

    } else if (command == "priority") {
      /////////////////////////////////////////////////////////
      //////////  TODO: Implement From Here      //////////////
      insertWithPriority(temp, value);
      ///////////      End of Implementation      /////////////
      /////////////////////////////////////////////////////////

    } else if (command == "dequeue") {
      /////////////////////////////////////////////////////////
      //////////  TODO: Implement From Here      //////////////
      if (queueSize == 0) {
        answer += "EMPTY\n";
        continue;
      }
      for (int i = 1; i < MAX_SIZE; i++) {
        if (queue[i][0] != 0) {
          queue[i][0] = 0;
          queue[i][1] = 0;
          queueSize--;
          break;
        }
      }
      ///////////      End of Implementation      /////////////
      /////////////////////////////////////////////////////////

    } else if (command == "peek") {
      /////////////////////////////////////////////////////////
      //////////  TODO: Implement From Here      //////////////
      for (int i = 1; i < MAX_SIZE; i++) {
        if (queue[i][0] != 0) {
          answer +=
              to_string(queue[i][1]) + ", " + to_string(queue[i][0]) + "\n";
          break;
        }
      }
      ///////////      End of Implementation      /////////////
      /////////////////////////////////////////////////////////

    } else if (command == "show") {
      /////////////////////////////////////////////////////////
      //////////  TODO: Implement From Here      //////////////
      int count = 0;

      // run for loop until we access all the elements in the queue.
      for (int i = 1; count < queueSize; i++) {
        if (queue[i][0] != 0) {
          answer +=
              to_string(queue[i][1]) + ", " + to_string(queue[i][0]) + "\n";
          count++;
        }
      }
      ///////////      End of Implementation      /////////////
      /////////////////////////////////////////////////////////
    }
  }
  answer = answer.substr(0, answer.size() - 1);
  fout << "[Task 6]" << endl;
  fout << answer << endl;
}

// End of Task 6
// =======================================================================================================

// Nothing changed in Main function!!
// ==================================================================================

int main(int argc, char **argv) {
  string filename = "submit.txt";
  int task_num = 0;
  InstructionSequence *instr_seq;
  string expression;

  // Open file
  ofstream fout;
  fout.open(filename, fstream::app);
  if (!fout.is_open()) {
    cerr << "Unable to open file: " << filename << endl;
    return -1;
  }

  // Choosing task number. Default is running ALL tasks (0)
  if (argc >= 2)
    task_num = atoi(argv[1]);
  if (argc >= 3) {
    if (task_num == 4)
      expression = argv[2];
    else {
      try {
        instr_seq = ParseInstructions(argv[2]);
      } catch (const char *e) {
        cerr << e << endl;
        return -1;
      }
    }
  }

  // Running the task(s)
  switch (task_num) {
  case 1:
    task_1(fout);
    break;
  case 2:
    task_2(fout);
    break;
  case 3:
    task_3(fout, instr_seq);
    break;
  case 4:
    task_4(fout, expression);
    break;
  case 5:
    task_5(fout, instr_seq);
    break;
  case 6:
    task_6(fout, instr_seq);
    break;
  case 0:
    task_1(fout);

    task_2(fout);

    InstructionSequence *instr_seq_3;
    instr_seq_3 = ParseInstructions(TASK_3_DEFAULT_ARGUMENT);
    task_3(fout, instr_seq_3);

    InstructionSequence *instr_seq_4;
    expression = TASK_4_DEFAULT_ARGUMENT;
    task_4(fout, expression);

    InstructionSequence *instr_seq_5;
    instr_seq_5 = ParseInstructions(TASK_5_DEFAULT_ARGUMENT);
    task_5(fout, instr_seq_5);

    InstructionSequence *instr_seq_6;
    instr_seq_6 = ParseInstructions(TASK_6_DEFAULT_ARGUMENT);
    task_6(fout, instr_seq_6);
    break;
  default:
    cout << "Wrong task number" << endl;
  }

  fout.close();
  return 0;
}
