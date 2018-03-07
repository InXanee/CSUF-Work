// lab4.c - starter code for Lab 4

/*
 * Convert your program from Lab 3 to use a linked list instead of an array.
 * Use this code as a starting point.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_SIZE 3
#define PROGRAM_SIZE 13

struct node {
    int line;
    char command[MAX_COMMAND_SIZE + 1];
    unsigned int argument;

    struct node *next;
};

struct node *create_node(int line, char *command, unsigned int argument)
{
    assert(strlen(command) <= MAX_COMMAND_SIZE);

    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    new->line = line;
    strcpy(new->command, command);
    new->argument = argument;

    new->next = NULL;

    return new;
}

struct node *append_node(struct node *start, struct node *new)
{
    assert(start != NULL);

    struct node *current = start;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new;

    return new;
}

void print_node(struct node *n)
{
    printf("%2d %s %x\n", n->line, n->command, n->argument);
}

int counter = 0;

uint8_t byte = 0;

void do_step_node(struct node *start)
{
  assert(start != NULL);
  struct node *current = start;

  if (counter >= PROGRAM_SIZE) {
       return;
   }
   if (strcmp(current->command, "set") == 0) {
       byte = current->argument;
   } else if (strcmp(current->command, "and") == 0) {
       byte &= current->argument;
   } else if (strcmp(current->command, "or") == 0) {
       byte |= current->argument;
   } else if (strcmp(current->command, "xor") == 0) {
       byte ^= current->argument;
   } else if (strcmp(current->command, "shr") == 0) {
       byte >>= current->argument;
   } else if (strcmp(current->command, "shl") == 0) {
       byte <<= current->argument;
   }
   counter++;
}

void print_value_node()
{
  printf("%x\n", byte);
}

void list_node(struct node *start)
{
  assert(start != NULL);
  struct node *current = start;
  int list_counter = 0;
    if (counter == PROGRAM_SIZE-1) {
      while (list_counter <= counter-1) {
          current = current->next;
          list_counter++;
      }
    }
    else if (counter != 0) {
      while (list_counter < counter-1) {
          current = current->next;
          list_counter++;
      }
      print_node(current);
      current = current->next;
    }
    print_node(current);
    print_node(current->next);
}

void print_list(struct node *start)
{
    struct node *current = start;

    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

void do_continue_node(struct node *start)
{
  assert(start != NULL);
  struct node *current = start;
  for (int i = counter; i < PROGRAM_SIZE; i++){
    do_step_node(current);
    current = current->next;
  }
}

struct node *create_list(void)
{
    struct node *head, *next;
    int line = 1;

    head = create_node(line++, "set", 0x1);
    next = append_node(head, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "shl", 0x1));
    next = append_node(next, create_node(line++, "or", 0x1));
    next = append_node(next, create_node(line++, "or", 0x2));
    next = append_node(next, create_node(line++, "shl", 0x2));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "xor", 0x10));
    next = append_node(next, create_node(line++, "and", 0x4));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "and", 0x3));
    next = append_node(next, create_node(line++, "set", 0x1c));
    next = append_node(next, create_node(line++, "shr", 0x1));

    return head;
}

void free_list(struct node *start)
{
    struct node *prev, *current;

    current = start;
    while (current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }
}

int main(void)
{
    struct node *head = create_list(), *current;
    current = head;
    char command[MAX_COMMAND_SIZE + 1];

     while (scanf("%s", command) != EOF) {

         if (strcmp(command, "step") == 0) {
            do_step_node(current);
            current = current->next;
         } else if (strcmp(command, "continue") == 0) {
            do_continue_node(current);
         } else if (strcmp(command, "print") == 0) {
            print_value_node();
         } else if (strcmp(command, "list") == 0) {
            list_node(head);
         }

     }
    free_list(head);
    free_list(current);
    return EXIT_SUCCESS;
}
