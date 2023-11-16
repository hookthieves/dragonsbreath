# dragonsbreath
## Intention
The project was intended to automate a technique that I have used many times through my red teaming operations. I realised that I was implementing this technique many times throughout the operations, it would be easier to automate it and turn it into a project that could be leveraged within the team. 
## Information
File bloating is an evasion technique where a malicious file is inflated with junk data, usually by appending a large number of null bytes to the end of the file. This program will bloat a PE file with junk data with any number of bytes chosen by the operator. It will then save a new file with a new name appending the number of bytes in the file name. EG Virus_200.exe (This determines that the new file has 200MB of null bytes at the end of the file)
## Usage: 
dragonsbreath.exe
## Output
![image](https://github.com/hookthieves/dragonsbreath/assets/46670348/17568326-8e27-4155-83e8-296f851b1d24)
## Results:
This specific technique is able to bypass many AV and EDR statically. However the operator will need to have opsec in mind when executing the binary. So far, this project is able to bypass:
1. Windows Defender
2. Tanium
3. Symantec Endpoint
4. Elastic EDR
5. Crowdstrike
