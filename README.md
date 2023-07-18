# cppProjects
Small side projects used to test myself as I learn C++.

SCHEDULER-BUILDER:
    This program allows users to manage course selections and create a schedule based on course information provided in text files. The program provides a user-friendly interface to perform various operations such as course selection, schedule management, and generating a final schedule.
    
    Command-Line Execution:
    
    The program can be executed by passing a command-line argument specifying the path to the file to read. For example, "yourprogram.exe filetoread.txt".

    File Reading and Data Processing:
    
    The program reads the specified file and extracts relevant information, which includes the following data elements from each line:
    ID Prefix (Columns 11-13): A three-letter code indicating the department to which the course belongs.
    Course Number (Columns 14-17): A four-digit code identifying the course, categorized as lower level, upper level, or graduate-level.
    Course Title (Columns 30-92): A friendly name of the course, trimmed of trailing spaces.
    Credit Values (Columns 183-185): Numeric values indicating the credits assigned to a course, with specific rules applied based on course level and type.
    Course Selection:
    
    The program prompts the user to choose between selecting courses by title or by department and course number.
    Depending on the user's selection, a menu is displayed, allowing the user to pick a course either by its title or department and course number.
    Course Information and Selection:
    
    Once a course is chosen, the program displays all the information about the course, including Department, Number, Title, and Credits.
    The user is then prompted whether they want to add the course to their schedule.
    If the user decides to add the course, the program stores the information. Regardless of the choice, the program prints the course menu again for course selection.
    
    Schedule Summary:
    
    When the user is ready to finish, they can select an option from the menu to view a summary of their schedule.
    The schedule summary displays all course elements (Department, Number, Title, and Credits) and shows the total credits.
    If the total credits are less than 9 or greater than 15, the user is prompted to add or remove courses to adjust the credit count.
    Saving the Schedule:
    
    After adjusting the schedule, the user is prompted to enter a filename to which the final schedule will be saved.
    The program then prints the final schedule to the specified file and exits.
    Note: This program supports various text files formatted similarly to the provided samples, allowing for testing with additional files beyond the given ones.

