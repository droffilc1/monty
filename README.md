# The Monty Program

## 0x19. C - Stacks, Queues - LIFO, FIFO

## The Monty Language

<p>
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.
</p>

## Monty Byte Code Files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```

<p>
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
</p>

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

## Compilation

```bash
  gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Features

| opcode       | functionality                                                     |
| ------------ | ----------------------------------------------------------------- |
| push         | add element to the 'top' of stack and 'end' of queue.             |
| pop          | remove element from 'top' of stack and 'end' of queue.            |
| pall         | print every member of the structure.                              |
| pint         | prints the member value at the top of stack.                      |
| swap         | swaps the order of the 1st and 2nd elements in stack.             |
| add          | add top two member values.                                        |
| sub          | subtract the top element from the 2nd top element.                |
| div          | divide the 2nd element by the top element.                        |
| mul          | multiply the top two elements of the stack.                       |
| mod          | the remainder when the 2nd element is divided by the top element. |
| comment      | there is the ability to parse comments found in bytecode ->'#'.   |
| pchar        | print character at the top of the stack.                          |
| pstr         | print the character at the top of the stack.                      |
| rotl         | moves element at the top to the bottom of the stack.              |
| rotr         | the bottom of the stack becomes the top.                          |
| queue, stack | toggles the doubly link list implementation style.                |
| nop          | opcode should do nothing.                                         |

## Motivation

To get a deeper undestanding of how stacks and queues work using a doubly linked list

## Reference

[How do I use extern to share variables between source files?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)

[Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)

[Stack operations](https://www.digitalocean.com/community/tutorials/stack-in-c)

[Queue operations](https://www.edureka.co/blog/queue-in-c/)

[Stacks](https://www.youtube.com/playlist?list=PLBlnK6fEyqRgWh1emltdMOz8O2m5X3YYn)

[Data Structures and Algorithms](https://www.youtube.com/playlist?list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU)

## Contributors

This project was created by [@droffilc1](https://www.github.com/droffilc1)
