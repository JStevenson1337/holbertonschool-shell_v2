# Simple Shell

## ABOUT:
The simple shell is a command line interpreter that was first conceived by Ken Thompson in 1971. Users can direct the operation of the computer by entering commands as text for a command line interpreter to execute, or by creating text scripts of one or more such commands. This shell includes basic functionality found in the traditional Unix shell.

## VERSION
This simple shell was complied and tested on Ubuntu 20.04 LTS

## TO RUN:
Clone this repo:
```git clone "https://github.com/TimSimms84/simple_shell.git"```

Compile:
```gcc -Wall -Werror -Wextra -pedantic *.c -o hsh```

This shell can be run in interactive mode:
```./hsh```

Or non-interactive mode: 
```echo ls -l | ./hsh```

## EXAMPLE
```$ ./hsh```

```$ ls -la```

```
total 200
drwxrwxr-x  4 tim tim  4096 Dec  1 14:40 .
drwxr-xr-x 45 tim tim  4096 Dec  1 14:40 ..
-rw-rw-r--  1 tim tim   159 Dec  1 14:21 AUTHORS
drwxrwxr-x  2 tim tim  4096 Dec  1 14:20 backup
-rw-rw-r--  1 tim tim   731 Dec  1 14:21 builtin_func.c
-rw-rw-r--  1 tim tim   557 Dec  1 14:36 check_builtin.c
-rw-rw-r--  1 tim tim   559 Dec  1 14:21 check_path.c
-rw-rw-r--  1 tim tim   638 Dec  1 14:21 env_func.c
-rw-rw-r--  1 tim tim   487 Dec  1 14:21 _environ.c
-rw-rw-r--  1 tim tim   810 Dec  1 14:21 error.c
-rw-rw-r--  1 tim tim  1165 Dec  1 14:21 execute.c
drwxrwxr-x  8 tim tim  4096 Dec  1 14:39 .git
-rwxrwxr-x  1 tim tim 53480 Dec  1 14:40 hsh
-rwxrwxr-x  1 tim tim 53480 Dec  1 14:36 hsh1
-rw-rw-r--  1 tim tim   244 Dec  1 14:21 hsh.c
-rw-rw-r--  1 tim tim   678 Dec  1 14:21 itoa.c
-rw-rw-r--  1 tim tim    38 Dec  1 14:21 main.h
-rw-rw-r--  1 tim tim   909 Dec  1 14:21 make_path.c
-rw-rw-r--  1 tim tim  3512 Dec  1 14:21 README.md
-rw-rw-r--  1 tim tim  1171 Dec  1 14:33 shell.c
-rw-rw-r--  1 tim tim  1350 Dec  1 14:28 shell.h
-rw-rw-r--  1 tim tim  2006 Dec  1 14:21 strings.c
-rw-rw-r--  1 tim tim   876 Dec  1 14:21 _strtok.c
-rw-rw-r--  1 tim tim  1232 Dec  1 14:21 tokenize.c

```


## ***List of allowed functions and system calls***
***
|FUNCTION/SYSTEM CALL|  MAN PAGE | More INFO | 
|-----|------|------|
|**access** | (man 2 access)|    INFO    |
|**chdir** | (man 2 chdir)|  INFO    |
|**close** | (man 2 close)|  INFO    |
|**closedir** | (man 3 closedir)|    INFO    |
|**execve** | (man 2 execve)|    INFO    |
|**exit** | (man 3 exit)|    INFO    |
|**_exit** | (man 2 _exit)|  INFO    |
|**fflush** | (man 3 fflush)|    INFO    |
|**fork** | (man 2 fork)|    INFO    |
|**free** | (man 3 free)|    INFO    |
|**getcwd** | (man 3 getcwd)|    INFO    |
|**getline** | (man 3 getline)|  INFO    |
|**getpid** | (man 2 getpid)|    INFO    |
|**isatty** | (man 3 isatty)|    INFO    |
|**kill** | (man 2 kill)|    INFO    |
|**malloc** | (man 3 malloc)|    INFO    |
|**open** | (man 2 open)|    INFO    |
|**opendir** | (man 3 opendir)|  INFO    |
|**perror** | (man 3 perror)|    INFO    |
|**read** | (man 2 read)|    INFO    |
|**readdir** | (man 3 readdir)|  INFO    |
|**signal** | (man 2 signal)|    INFO    |
|**stat** | (__xstat) (man 2 stat)|  INFO    |
|**lstat** | (__lxstat) (man 2 lstat)|   INFO    |
|**fstat** | (__fxstat) (man 2 fstat)|   INFO    |
|**strtok** | (man 3 strtok) INFO    |
|**wait** | (man 2 wait)|    INFO    |
|**waitpid** | (man 2 waitpid)|  INFO    |
|**wait3** | (man 2 wait3)|  INFO    |
|**wait4** | (man 2 wait4)|  INFO    |
|**write** | (man 2 write)|  INFO    |
***

## Authors
Jeremy Stevenson
Tim Simms
