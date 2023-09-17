# Simple Shell
A team project.

## An outline of how the shell works

### 1.Displaying the prompt
Continuously showing a prompt in an ongoing loop, including details like
the username, host, and current directory, while awaiting user input.

### 2.Reading User Input
A function collects input from the user when they press the "Enter" key in
the terminal. Typically, the 'fgets' function is used, storing the input in
a buffer.

### 3.Parsing the Command
Breaking down the input (referred to as the command) into tokens that 
represent various elements like the command name, arguments, and options. 
This occurs when a designated delimiter is encountered.

### 4.Searching for the Command
After parsing the command and its arguments, the shell looks for the 
corresponding executable file associated with the command. This search 
happens in directories specified by the 'PATH' environmental variable.

### 5.Creating the Child Process
If the shell finds the executable, it generates a child process using 
system calls like 'fork.' This child process operates as a distinct 
instance of the shell, responsible for executing the specified command.

### 6.Executing the Command
The child process, through system calls such as 'exec,' replaces its own 
program with the program corresponding to the command to be executed. The 
new program takes control of the child process, running the desired command.

### 7.Waiting for Command Completion
The parent shell awaits the completion of the child process using functions 
like 'wait' or 'waitpid.' This ensures that the shell doesn't proceed to 
display the next prompt until the executed command finishes executing.

### 8.Displaying Output
If the executed command generates output, such as text or data, the shell 
exhibits this output in the terminal for the user's viewing, using the
write command.

### 9.Returning the Prompt
Following the completion of the executed command, the shell reverts to its
initial state, presenting the prompt to the user and awaiting their next 
command.

### 10.Exiting the Shell
Users can exit the shell by entering a specific command (for example, 
'exit') or by executing a key combination (like Ctrl + D). This action 
results in the termination of the shell, returning the terminal to its 
prior state.
