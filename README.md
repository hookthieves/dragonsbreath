
# Dragonsbreath

**Dragonsbreath** is a lightweight **C utility** designed to automate a **file bloating evasion technique** used in **red team operations**. It appends **null bytes** to a **Portable Executable (PE) file** to artificially increase its size, which can help evade **static analysis** by **Antivirus (AV)** and **Endpoint Detection and Response (EDR)** tools.

---

## Overview

This tool simplifies the manual process of file bloating by:
- Allowing operators to specify an original executable
- Defining a custom bloat size in megabytes
- Automatically generating a new file (e.g., `Virus_200.exe`) with appended junk data

The resulting file retains functionality but increases in size, potentially evading detection based on size thresholds or static signatures.

---

## Features

- **File Bloating**: Appends a specified number of null bytes to inflate file size
- **Customizable Output**: Output file is renamed to reflect the new size (e.g., `Virus_300.exe`)
- **Error Handling**: Built-in checks for file operations and system calls
- **Cross-Compatible with Windows**: Uses `copy /b` for concatenation on Windows systems

---

## Prerequisites

- **C compiler** (e.g., `gcc`, `cl`)
- **Windows operating system** (for file operations and `copy /b` command)
- Basic knowledge of **PE file formats** and **evasion techniques**

---

## Compilation

Use a standard C compiler to compile the source:

### With GCC

```bash
gcc dragonsbreath.c -o dragonsbreath
````

### With MSVC

```bash
cl dragonsbreath.c
```

---

## Usage

Run the compiled executable:

```bash
./dragonsbreath
```

Follow the interactive prompts:

1. Enter the name of the original executable (e.g., `Virus.exe`)
2. Enter the bloat size in **megabytes**

The program will:

* Generate a temporary binary file of null bytes
* Concatenate the original executable and the null-byte file
* Rename the output to `Original_BloatSize.exe` (e.g., `Virus_200.exe`)
* Delete the temporary file

### Example

```text
###########################################################
#         Dragons Breath - Designed By Cuong Nguyen       #
###########################################################

    --> File bloating evasion technique <--

[i] Enter the name of the original executable file: Virus.exe
[i] Enter the file size in MBs: 200
[!] New file 'Virus_200.exe' has been generated.
```

---

## Output

* A new bloated file is created in the same directory
* File size is increased by the specified megabytes of null bytes
* Filename includes the original name and bloat size (e.g., `Virus_200.exe`)

---

## Code Structure

* **main**: Manages user input, file writing, concatenation, and cleanup
* Uses:

  * `fopen`, `fwrite` to create a temporary file of null bytes
  * `scanf` for user input
  * `system("copy /b")` to merge files
  * `remove`, `rename` for file management

---

## Results

This technique has shown success in bypassing static detection on:

1. Windows Defender
2. Tanium
3. Symantec Endpoint
4. Elastic EDR
5. Crowdstrike

While effective against **static scanners**, this method does **not prevent dynamic analysis**. Use with appropriate **OPSEC** controls during execution.

---

## Notes

* **Bloat Limit**: Supports sizes up to the maximum value of an `unsigned int` (system-dependent)
* **Platform-Specific**: Uses Windows-specific `copy /b` for merging; not cross-platform
* **Performance Impact**: Large bloated files may affect execution or detection due to size
* **Naming**: Choose inconspicuous filenames to avoid heuristic detection

---

## Testing Guidelines

* Use in **isolated Windows test environments**
* Confirm file size with a hex editor or binary viewer
* Monitor execution with AV/EDR tools to verify bypass success
* Observe logs and alerts for possible detection triggers

---

## Future Improvements

* Support **randomized byte padding** instead of null bytes
* Add **command-line arguments** for non-interactive use
* Implement **cross-platform support** with native file operations
* Add **PE file validation** (e.g., header integrity checking)

---

## License

This project is licensed under the **MIT License**.
See the [LICENSE](https://raw.githubusercontent.com/hookthieves/dragonsbreath/main/LICENCE) file for details.

---

## Legal and Ethical Use

This tool is intended **strictly for educational and authorized research purposes**.
It demonstrates a **file bloating technique** often used in **red teaming**.
Use only in environments where you have **explicit permission** to test security controls.
Always follow applicable **laws** and **ethical guidelines**.

---

## Contact

Created by **Cuong Nguyen**
For issues, improvements, or feedback, visit the [GitHub repository](https://github.com/hookthieves/dragonsbreath).


