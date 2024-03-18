#include <iostream>

using namespace std;

typedef struct Instruction {
  string command;

  int value;
  int priority;

} Instruction;

typedef struct InstructionSequence {
  Instruction *instructions;
  int length;
} InstructionSequence;

InstructionSequence *ParseInstructions(const char *arg);
void DeleteInstructionSequence(InstructionSequence *instr_seq);
void PrintInstructionSequence(InstructionSequence *instr_seq);

const char *const TASK_3_DEFAULT_ARGUMENT =
    "[('insert',3), ('insert',5), ('insert',4), ('delete',1), "
    "('insert',2),('delete',0)]";
const char *const TASK_4_DEFAULT_ARGUMENT = "mom";
const char *const TASK_5_DEFAULT_ARGUMENT =
    "[('enqueue',5), ('enqueue',3), ('dequeue',0), ('show', 0)]";
const char *const TASK_6_DEFAULT_ARGUMENT =
    "[('enqueue',5), ('priority', 1), ('enqueue',3), ('priority', 3), "
    "('dequeue',0), ('show', 0)]";
