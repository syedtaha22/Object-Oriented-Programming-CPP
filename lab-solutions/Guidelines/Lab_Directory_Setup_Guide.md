# Guide to Initialize Your Working Directory

This guide will help you set up a working directory for your lab tasks. Follow the steps carefully. Assuming you have a terminal or command prompt (cmd) open, and you know the directory where you want to create your lab folder.

---

## Step 1: Navigate to Your Desired Directory
1. Open the **Command Prompt** (cmd).
   - Press `Win + R`, type `cmd`, and hit Enter.
2. Navigate to the directory where you want to create the lab.
   - Use the `cd` (change directory) command:
     ```
     cd <path_to_your_directory>
     ```
   - Replace `<path_to_your_directory>` with the path to the directory you want to use. For example:
     ```
     cd C:\Users\YourName\OneDrive\Desktop
     ```

---

## Step 2: Create Your Lab Directory
1. Type the following command to create a directory named as per your lab:
   ```
   mkdir Lab<number>_<erp>
   ```
   - Replace `<number>` with the lab number (e.g., 1 for Lab1).
   - Replace `<erp>` with your ERP number (e.g., 12345 for Lab1_12345).

2. Navigate into the newly created directory:
   ```
   cd Lab<number>_<erp>
   ```

---

## Step 3: Create Subdirectories and Configuration
1. Run the following commands to create the required subdirectories:
   ```
   mkdir headers main src .vscode
   ```
   - **`headers/`**: This will contain your `.hpp` header files.
   - **`main/`**: This will store your `.cpp` files with the main function for each task.
   - **`src/`**: This will store the `.cpp` implementation files for your classes and functions.
   - **`.vscode/`**: This will store Visual Studio Code configuration files.

2. Create an empty `tasks.json` file inside the `.vscode/` directory:
   ```
   echo. > .vscode\tasks.json
   ```

---

## Explanation of the Commands
- **`mkdir <name>`**: Creates a new directory with the specified name.
- **`cd <name>`**: Navigates into the specified directory.
- **`echo. > <filename>`**: Creates an empty file with the specified name.

---


## Step 4: Open the Project in Visual Studio Code
1. Open Visual Studio Code in the current directory:
   ```
   code .
   ```
   - This command launches Visual Studio Code with the directory as the workspace.
   - Make sure you have Visual Studio Code installed and the `code` command is added to your system PATH.

---


## Step 5: Configure the `tasks.json` File
1. Open the `tasks.json` file located in `.vscode/` using Visual Studio Code.
2. Add the following configuration:

   ```json
   {
      "tasks": [
         {
            "type": "cppbuild",
            "label": "C/C++: g++ build active file",
            "command": "g++",
            "args": [
               "${file}",
               "-o",
               "${fileDirname}\\${fileBasenameNoExtension}.exe",
               "${workspaceFolder}\\src\\*.cpp"
            ],
            "group": {
               "kind": "build",
               "isDefault": true
            }
         }
      ],
      "version": "2.0.0"
   }
   ```

---


## `tasks.json` Configuration
The `tasks.json` file defines tasks for Visual Studio Code to help you automate the process of compiling and running your code.

1. **`type`**: Specifies the task type. Here, it's `cppbuild`, which is for building C++ projects.
2. **`label`**: A user-friendly name for the task. This will appear in the task selection menu.
3. **`command`**: Specifies the compiler to use. Here, it is `g++`, a popular C++ compiler.
4. **`args`**: Specifies arguments to pass to the compiler:
   - **`${file}`**: Refers to the active file in the editor.
   - **`-o`**: Indicates the output file name.
   - **`${fileDirname}\\${fileBasenameNoExtension}.exe`**: Specifies the output file's directory and name.
   - **`${workspaceFolder}\\src\\*.cpp`**: Includes all `.cpp` files from the `src/` directory in the compilation.
5. **`group`**: Specifies the task group:
   - **`kind: build`**: Indicates this is a build task.
   - **`isDefault: true`**: Marks this as the default build task.
6. **`version`**: Indicates the version of the task schema.

---

By following these steps, you will have a well-structured working directory and an automated build process for your lab tasks.
