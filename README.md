# Cplusplus-Program
BingR
### Project Summary
The Corner Grocer project is a C++ program that analyzes a text file containing grocery items purchased throughout the day. The program counts how many times each item appears and stores the results in a map. It allows the user to search for a specific item, display a complete frequency list, view the frequencies as a histogram, or exit the program. It also automatically creates a backup file named frequency.dat containing each item and its purchase frequency. This program helps the Corner Grocer understand which products are purchased most often so the store can make better decisions about inventory and product placement.

### What I did Well
I did particularly well organizing the program into separate functions, with each function handling one specific task. For example, loadItemFrequencies() reads and processes the input file, searchForItem() searches for an item, and printHistogram() creates the histogram. I also used a map to connect each grocery item with its frequency. The map made it easy to count items and automatically display them in alphabetical order. In addition, I included file-opening checks and input validation so the program can respond appropriately when a file cannot be opened or when the user enters a nonnumeric menu selection.

### Areas for Improvement
I could improve the program by making item searches case-insensitive. Currently, an entry such as apples may not match Apples because C++ treats uppercase and lowercase letters differently. I could convert both the stored item names and the user’s search entry to the same letter case before comparing them. I could also improve file-error handling by ending the program when the input file cannot be opened instead of continuing with an empty map. Additional validation could prevent blank searches and handle grocery-item names containing spaces. These changes would make the program more reliable and user-friendly.

For a very large input file, an unordered_map could provide faster average lookup and insertion times. However, the current map is useful because it automatically keeps the grocery items alphabetically ordered.

### Challenges and Resources
The most challenging parts were reading information from a file, counting repeated items, and creating the histogram. I overcame these challenges by dividing the problem into smaller steps and using a map, where the grocery item is the key and its frequency is the value. The statement itemFrequencies[itemName]++ allowed the program to increase the count each time an item appeared in the file. I also used nested loops in the histogram function so the program could print one asterisk for each purchase.

Resources that supported my work included course materials, C++ documentation, examples involving maps and file streams, instructor feedback, and debugging tools in Visual Studio. I can continue adding official C++ documentation, GitHub examples, classmates, tutors, and instructor guidance to my support network.

### Transferable Skills
Several skills from this project will transfer to future projects and coursework. These include breaking a larger problem into smaller functions, reading from and writing to files, selecting an appropriate data structure, validating user input, using loops and conditional statements, and debugging program errors. I also gained experience documenting code and using GitHub to save and present a completed project. These skills can be applied to programs that process records, analyze data, generate reports, or provide menu-driven user interaction.

### Maintainability, Readability, and Adaptability
I made the program maintainable and readable by giving variables and functions descriptive names, adding comments, and separating the program into functions with clear responsibilities. I used constants for the input and backup file names so they can be changed easily without searching throughout the program. I also passed the map by constant reference when a function only needed to read the information, which avoids unnecessary copies and prevents accidental changes. The program can be adapted by adding new menu options, changing the input file, using another display format, or expanding the item-search features without having to rewrite the entire program.

### AI Usage Acknowledgment
I used ChatGPT to help me understand the assignment requirements, organize the README outline, review C++ programming concepts, and improve the clarity of my written reflection. I reviewed and revised the suggestions to ensure that the final submission accurately represents my project, code, and learning.
