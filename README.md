Dragonsbreath

Overview
**Dragonsbreath** is a **C program** designed to automate a **file bloating evasion technique** commonly used in **red teaming operations**. The tool inflates a **Portable Executable (PE) file** with **junk data** (null bytes) to evade **static analysis** by **Antivirus (AV)** and **Endpoint Detection and Response (EDR)** systems. The operator specifies the original executable and the desired bloat size (in megabytes), and the program generates a new file with the appended null bytes, renaming it to reflect the bloat size (e.g., `Virus_200.exe` for 200MB of null bytes).

Intention
The project was created to **automate** a file bloating technique frequently used during **red teaming operations**. By turning this technique into a reusable tool, it streamlines workflows and enables **team collaboration** for **evasion-focused security research**.

Features
- **File Bloating**: Appends a user-specified number of **null bytes** to a PE file to increase its size.
- **Customizable Size**: Allows the operator to define the **bloat size** in megabytes.
- **Automated File Creation**: Generates a new executable with a name indicating the bloat size (e.g., `Virus_200.exe`).
- **Error Handling**: Includes checks for **file operations** and **system commands**.
- **Cross-Platform Commands**: Uses Windows `copy /b` for file concatenation.

Prerequisites
- A **C compiler** (e.g., MSVC, gcc).
- **Windows environment** (for `copy /b` command and file operations).
- Basic understanding of **PE files** and **evasion techniques**.

Usage

Compilation
Compile the program using a **C compiler**. Examples:
- **MSVC**: `cl dragonsbreath.c`
- **gcc**: `gcc dragonsbreath.c -o dragonsbreath`

Running the Program
Execute the compiled program:
```bash
./dragonsbreath
```

The program will:

1. Prompt for the original executable name (e.g., Virus.exe).
2. Prompt for the file size in megabytes to append as null bytes.
3. Create a temporary binary file (new_mb_file.bin) filled with null bytes.
4. Concatenate the original executable and the binary file using copy /b.
5. Rename the output file to include the bloat size (e.g., Virus_200.exe).
6. Delete the temporary binary file.

Example
Run the program and follow the prompts:

        ###########################################################
        #         Dragons Breath - Designed By Cuong Nguyen       #
        ###########################################################

            --> File bloating evasion technique <--

[i] Enter the name of the original executable file: Virus.exe[i] Enter the file size in MBs: 200[!] New file 'Virus_200.exe' has been generated.[i] Press  to exit programBye...

<h3>Output</h3>
The program generates a new executable with the specified number of **null bytes** appended, named to reflect the bloat size (e.g., `Virus_200.exe`).

![Output Image](https://github.com/hookthieves/dragonsbreath/assets/46670348/17568326-8e27-4155-83e8-296f851b1d24)

<h2>Code Structure</h2>
- **main**: Orchestrates **user input**, **file bloating**, **file concatenation**, and **renaming**.
- Uses **fopen** and **fwrite** to create a temporary binary file with **null bytes**.
- Uses **scanf** to capture the **executable name** and **bloat size**.
- Uses **system** to execute the `copy /b` command for file concatenation.
- Uses **remove** and **rename** to manage temporary and output files.

<h2>Results</h2>
This **file bloating technique** has been tested to bypass **static analysis** by the following **AV/EDR systems**:
1. **Windows Defender**
2. **Tanium**
3. **Symantec Endpoint**
4. **Elastic EDR**
5. **Crowdstrike**

**Note**: While effective against **static scans**, operators must exercise **operational security (OPSEC)** when executing the bloated binary, as **dynamic analysis** may still detect malicious behavior.

<h2>Notes</h2>
- **File Size**: The program supports bloating up to **unsigned int** megabytes (limited by system resources).
- **Evasion**: File bloating increases file size to evade **static signature detection**, but does not protect against **behavioral detection**.
- **Limitations**: The `copy /b` command and file operations are Windows-specific. Large file sizes may impact performance.
- **OPSEC**: Avoid suspicious file names or payloads that may trigger **heuristic detection**.

<h2>Testing</h2>
- Test in a **controlled Windows environment** (e.g., a virtual machine).
- Verify the output file (`<original>_<size>.exe`) contains the correct number of **null bytes** using a hex editor.
- Test against **AV/EDR systems** listed in the results section to confirm evasion.
- Monitor **EDR logs** for detection during execution.

<h2>Future Improvements</h2>
- Add support for **randomized junk data** instead of null bytes for better evasion.
- Implement **command-line arguments** for automated input.
- Support **non-Windows platforms** with alternative file concatenation methods.
- Add **validation** for the input executable's integrity (e.g., PE header checks).

<h2>License</h2>
This project is licensed under the **MIT License**. See the [LICENSE](https://raw.githubusercontent.com/hookthieves/dragonsbreath/main/LICENCE) file for details.

<h2>Legal and Ethical Considerations</h2>
This tool is for **educational and research purposes only**. It demonstrates a **file bloating evasion technique** for security research. Ensure compliance with all applicable **laws** and **ethical guidelines** when using this code, especially in **red teaming** or **evasion-focused research**.

<h2>Contact</h2>
For questions or contributions, please contact the project maintainer (Cuong Nguyen) or open an issue on the [GitHub repository](https://github.com/hookthieves/dragonsbreath).

