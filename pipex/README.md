# pipex and syscalls

[https://www.notion.so](https://www.notion.so)

# Fork Function

# Fork Function Overview

The fork() function in C is a system call that creates a new process by duplicating the existing (parent) process. The new process is called the child process.

## Key Points

- Creates an exact copy of the parent process
- Returns different values in parent and child processes:
    - Parent process: Returns child's PID (positive number)
    - Child process: Returns 0
    - Error case: Returns -1
- After fork(), both processes execute the same code but can be identified by the return value

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        // Fork failed
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child process\n");
    }
    else {
        // Parent process
        printf("Parent process\n");
    }
    return 0;
}
```

# Wait System Call

The wait() system call is used by a parent process to wait for its child process to terminate. It suspends the calling process until one of its child processes ends or a signal is received.

## Basic Syntax and Usage

```c
#include <sys/wait.h>
pid_t wait(int *status);
```

- Returns: Child's PID on success, -1 on error
- The status parameter stores information about how the child process terminated
- Commonly used with fork() to ensure parent process waits for child completion

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    int status;
    
    if (pid == 0) {
        printf("Child process\n");
        exit(0);
    } else {
        wait(&status);
        printf("Child has finished\n");
    }
    return 0;
}
```

# getpid() and getppid() System Calls

These system calls are used to get process IDs in Unix-like operating systems:

- getpid(): Returns the process ID (PID) of the calling process
- getppid(): Returns the parent process ID (PPID) of the calling process

## Basic Usage

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Current Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    return 0;
}
```

These functions are particularly useful when working with multiple processes to identify parent-child relationships and track process hierarchies.

## Common Applications

- Process identification in multi-process applications
- Debugging and logging process relationships
- Process management and monitoring

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("Child Process - PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        printf("Parent Process - PID: %d, Parent PID: %d\n", getpid(), getppid());
    }
    return 0;
}
```