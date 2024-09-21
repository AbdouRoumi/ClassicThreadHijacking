
# Local Thread Hijacking

This project demonstrates how to perform local thread hijacking on a running process in Windows. It manipulates the current thread's context to change the instruction pointer and execute custom shellcode.

## Features
- **Local Thread Hijacking:** Modify the execution flow of a thread within the same process.
- **Shellcode Injection:** Inject custom shellcode into the current process and hijack the thread to execute it.
- **Context Modification:** Alter the thread’s context (including instruction pointer) to point to the injected code.

## Prerequisites
- **Operating System:** Windows
- **Development Environment:** Visual Studio
- **Libraries:**
  - Windows API (kernel32, ntdll)
  - Functions for memory and thread management

## How It Works
1. **Shellcode Injection:** Memory is allocated within the same process using `VirtualAlloc` and filled with shellcode.
2. **Get Thread Context:** The thread's context is captured using `GetThreadContext`.
3. **Hijack Thread:** The instruction pointer (`RIP` on x64) is changed to the address of the injected shellcode, and the thread is resumed with the modified context.

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/LocalThreadHijacking.git
   ```
2. Open the project in Visual Studio.
3. Build the project (ensure C++20 is enabled in the project settings if needed).
4. Run the executable:
   ```bash
   LocalThreadHijacking.exe
   ```

### Example
```bash
LocalThreadHijacking.exe
```
After running the executable, the current process will hijack its own thread and execute the injected shellcode.

## Project Structure
- **Functions.h/Functions.cpp:** Contains the core functions for memory allocation, thread context manipulation, and shellcode injection.
- **LocalThreadHijacking.cpp:** The main entry point for the program that orchestrates the hijacking process.

## Troubleshooting
- **Privilege Errors:** Ensure you're running the program with the necessary privileges to modify thread contexts.
- **Memory Allocation Issues:** If `VirtualAlloc` fails, make sure there is enough memory available and check for proper permissions.

## Disclaimer
This project is intended for educational purposes only. Local thread hijacking can alter the behavior of running programs. Use responsibly within a controlled environment.

## License
This project is licensed under the MIT License.
