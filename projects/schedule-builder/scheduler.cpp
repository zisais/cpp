#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int getCreditsFromCourseNum(int courseNum);
int printSchedule(vector<string> schedule, int credits);
int addCredits(vector<string> schedule);
string listTitles(int numCourses, string *titles);
string listCourseCodes(int numCourses, int *nums, string *depts);
vector<string> deleteClass(string classToDel, vector<string> schedule, int numCourses);

int main(int argc, char *argv[])
{
    int numCourses = 0;
    string *ptrDept = nullptr;
    string *ptrTitle = nullptr;
    int *ptrNumber = nullptr;
    int *ptrCredits = nullptr;
    vector<string> schedule;

    string data = "";

    fstream file(argv[1]); //          FILE OPEN
    while(getline(file,data))
    {
        numCourses++;
    }
    file.close(); //                 FILE CLOSE
    
    fstream fileReopen(argv[1]); //            FILE OPEN

    ptrDept = new string[numCourses];
    ptrTitle = new string[numCourses];
    ptrNumber = new int[numCourses];
    ptrCredits = new int[numCourses];

    for(int i=0;i<numCourses;i++)
    {
        getline(fileReopen, data);
        string dept = "";
        string title = "";
        string strNumber = "";
        string strCredits = "";
        int number = 0;
        int credits = 0;
        bool invalidEntry = false;

        for(int j=10;j<13;j++)
        {
            if (isalpha(data[j]) != 0)
            {
                dept.push_back(data[j]);
            } else {invalidEntry = true;}
        }
        if (invalidEntry) {cout << "Check file format."; return 0;}

        for(int j=13;j<17;j++)
        {
            if (isdigit(data[j]) != 0)
            {
                strNumber.push_back(data[j]);
                number = stoi(strNumber);
            } else {invalidEntry = true;}
        }
        if (invalidEntry) {cout << "Check file format."; return 0;}
        
        for(int j=29;j<179;j++)
        {
            title.push_back(toupper(data[j]));
            if (data[j-1] == ' ' && data[j] == ' ')
            {
                title.erase((j-1) - 29, 2);
                j = 178;
            }
        }
        
        for(int j=182;j<185;j++)
        {
            if (data[j] == ' ')
            {
                strCredits.push_back('0');
            } else {
                strCredits.push_back(data[j]);
            }
        }
        if (strCredits == "VAR" || strCredits == "000")
        {
            credits = getCreditsFromCourseNum(number);
            if (credits == -1)
            {
                cout << "Problem determining credit value.";
                return 0;
            }
        } else {
            credits = stoi(strCredits);
        }
        

        ptrDept[i] = dept;
        ptrNumber[i] = number;
        ptrTitle[i] = title;
        ptrCredits[i] = credits;
    }
    fileReopen.close(); //        FILE CLOSE
    int choice = 0;
    cout << "Would you like to search for courses by title, or by department and course number?\n"
         << "Enter '1' for title, '2' for department/course number.\n";
    cin >> choice;

    int scheduledCredits = 0;
    switch (choice) 
    {
        case 1:
        {
            bool again = true;
            do
            {
                int done = 0;
                string title = listTitles(numCourses, ptrTitle);

                if (title == "VIEW SCHEDULE")
                {
                    bool redo = true;
                    do
                    {
                        done = printSchedule(schedule, scheduledCredits);

                        if (done == 0) 
                        {
                            bool askAgain = false;
                            do
                            {
                                string schedAns;
                                cout << "Do you wish to add more classes, or finish? (ADD/FIN)\n";
                                cin >> schedAns;
                                for(int i=0;i<schedAns.length();i++)
                                {
                                    schedAns[i] = toupper(schedAns[i]);
                                }

                                if (schedAns == "ADD")
                                {
                                    redo = false;
                                } else if (schedAns == "FIN")
                                {
                                    string filename;
                                    cout << "What name would you like to give your file? Do not forget to include \".txt\": ";
                                    cin >> filename;

                                    ofstream sched(filename); //         FILE OPEN
                                    if (!sched)
                                    {
                                        cout << "File creation failed.";
                                        return 0;
                                    }
                                    for (int i=0;i<schedule.size();i++)
                                    {
                                        string scheduleLine = schedule[i];
                                        sched << scheduleLine << endl;
                                    }
                                    sched.close(); //            FILE CLOSE
                                    cout << "Schedule file successfully created at \"" << filename << "\".";
                                    return 0;
                                } else {askAgain = true;}
                            } while(askAgain);
                        } else if (done == -1) {
                            string classToDel;
                            cout << "You should remove some classes.\n";
                            cout << "Which class would you like to delete?\n";
                            cin.ignore();
                            getline(cin, classToDel);
                            schedule = deleteClass(classToDel, schedule, numCourses);
                            scheduledCredits = addCredits(schedule);
                            again = false;
                        } else if (done == 1) {
                            char answer = ' ';
                            cout << "You should sign up for more classes.\n" << "Continue? y/n: \n";
                            cin >> answer;
                            if (toupper(answer) == 'Y') 
                            {
                                redo = false;
                            } else {
                                return 0;
                            }
                            
                        }
                    } while (redo);

                } else {
                    int matchingArraySlot = 0;
                    bool courseFound = false;
                    for(int i=0;i<numCourses;i++)
                    {
                        if (title == ptrTitle[i]) {
                            courseFound = true;
                            matchingArraySlot = i;
                            break;
                        }
                    }
                    if (courseFound) {
                        string courseInfo = to_string(ptrCredits[matchingArraySlot]) + " credits" + ' ' + ptrDept[matchingArraySlot]
                                             + to_string(ptrNumber[matchingArraySlot]) + ", " + title;
                        cout << courseInfo;

                        char Ans;
                        cout << " Would you like to add this course to your schedule? y/n: ";
                        cin >> Ans;
                        char ans = toupper(Ans);

                        if (ans == 'Y')
                        {
                            schedule.push_back(courseInfo);
                            scheduledCredits += ptrCredits[matchingArraySlot];
                        }
                    } else {
                            cout << "No matching course. Try again.\n";
                    }
                }
            } while (again);
            break;
        }
        case 2:
        {
            int done;
            bool again = false;
            do
            {
                string courseCode = listCourseCodes(numCourses, ptrNumber, ptrDept);

                if (courseCode == "VIEW SCHEDULE")
                {
                    bool redo = false;
                    do
                    {
                        done = printSchedule(schedule, scheduledCredits);
                        if (done == 0) 
                        {
                            bool askAgain = false;
                            do
                            {
                                string schedAns;
                                cout << "Do you wish to add more classes, or finish? (ADD/FIN)\n";
                                cin >> schedAns;
                                for(int i=0;i<schedAns.length();i++)
                                {
                                    schedAns[i] = toupper(schedAns[i]);
                                }

                                if (schedAns == "ADD")
                                {
                                    redo = false;
                                } else if (schedAns == "FIN") {
                                    string filename;
                                    cout << "What name would you like to give your file? Do not forget to include \".txt\"";
                                    cin >> filename;

                                    ofstream sched(filename); //         FILE OPEN
                                    if (!sched)
                                    {
                                        cout << "File creation failed.";
                                        return 0;
                                    }
                                    for (int i=0;i<schedule.size();i++)
                                    {
                                        string scheduleLine = schedule[i];
                                        sched << scheduleLine;
                                    }
                                    sched.close(); //            FILE CLOSE
                                    cout << "Schedule file successfully created at \"" << filename << "\".";
                                    return 0;
                                }
                            } while(askAgain);
                        } else if (done == -1) {
                            string classToDel;
                            cout << "You should remove some classes.\n";
                            cout << "Which class would you like to delete?\n";
                            cin.ignore();
                            getline(cin, classToDel);
                            schedule = deleteClass(classToDel, schedule, numCourses);
                            scheduledCredits = addCredits(schedule);
                            redo = true;
                            again = false;
                        } else if (done == 1) {
                            cout << "You should sign up for more classes.\n";
                            redo = false;
                            again = true;
                        }
                    } while (redo);
                    
                    
                } else {
                    int matchingArraySlot;
                    for(int i=0;i<numCourses;i++)
                    {
                        if (courseCode == ptrTitle[i])
                        {
                            matchingArraySlot = i;
                        }
                    }

                    string courseInfo = ptrTitle[matchingArraySlot] + ' ' + courseCode
                        + ", " + to_string(ptrCredits[matchingArraySlot]) + "credits.\n";
                    cout << courseInfo;

                    char Ans;
                    cout << "\nWould you like to add this course to your schedule? y/n: ";
                    cin >> Ans;
                    char ans = toupper(Ans);

                    if (ans == 'Y')
                    {
                        schedule.push_back(courseInfo);
                        scheduledCredits += ptrCredits[matchingArraySlot];
                    }

                    again = true;
                }

            } while (again);
            
        }

            break;
        default:
            cout << "Must enter a '1' or a '2'.\n";
            break;
    }

    delete [] ptrDept;
    delete [] ptrCredits;
    delete [] ptrNumber;
    delete [] ptrTitle;

    ptrDept = nullptr;
    ptrCredits = nullptr;
    ptrNumber = nullptr;
    ptrTitle = nullptr;

    return 0;
}

string listTitles(int numCourses, string *titles)
{
    bool redo = false;
    do
    {
        cout << "TITLES:\n";
        for(int i=0;i<numCourses;i++)
        {
            cout << "\t" << titles[i] << endl;
        }
        cout << "\tView schedule\n";

        string tempTitle;
        cout << "Enter the course title: \n";
        cin.ignore();
        getline(cin, tempTitle);
        cout << endl;
        string title = "";
        for(int i=0;i<tempTitle.length();i++)
        {
            title.push_back(toupper(tempTitle[i]));
        }

        return title;
    } while (redo);

}

string listCourseCodes(int numCourses, int *nums, string *depts)
{
    cout << "COURSE CODES:\n";
    for(int i=0;i<numCourses;i++)
    {
        string courseCode = depts[i] + to_string(nums[i]);
        cout << "\t" << courseCode << endl;
    }
    cout << "\tView schedule\n";

    string tempCode;
    cout << "Enter the course code: \n";
    cin.ignore();
    getline(cin, tempCode);
    string courseCode;
    for(int i=0;i<tempCode.length();i++)
    {
        courseCode[i] = toupper(tempCode[i]);
    }

    return courseCode;
}

int printSchedule(vector<string> schedule, int credits)
{
    for(int i=0;i<schedule.size();i++)
    {
        cout << schedule[i] << endl;
    }
    cout << "Your schedule has a total of " << credits << " credits.\n";
    if (credits < 9) 
    {
        return 1;
    } else if (credits > 15) {
        return -1;
    } else {return 0;}
}

int getCreditsFromCourseNum(int courseNum)
{
    int lowLevel = 2;
    int upperLevel = 3;
    int gradLevel = 4;
    string num = to_string(courseNum);
    int intNum = stoi(num);

    if (intNum < 3000) {return lowLevel;}
    else if (intNum < 5000) {return upperLevel;}
    else if (intNum < 6000) {return gradLevel;}
    else {cout << "Invalid."; return -1;}
}

int addCredits(vector<string> schedule)
{
    int accum = 0;

    int a = 0; // Course credits stored in the first character of the string for each schedule entry.
    for(int i=0;i<schedule.size();i++)
    {
        string schedEntry = schedule[i];
        string strCreds = "0" + schedEntry[a]; // stoi() does not work with single chars, start with 0 to make string
        int credits = stoi(strCreds);
        accum += credits;
    }

    return accum;
}

vector<string> deleteClass(string classToDelTemp, vector<string> schedule, int numCourses)
{
    int numChars = classToDelTemp.length();
    int deleteSlot;
    string classDelete;
    vector<string> newSchedule;

    for(int i=0;i<classToDelTemp.length();i++)
    {
        classDelete.push_back(toupper(classToDelTemp[i]));
    }

    for(int i=0;i<schedule.size();i++)
    {
        int found = -1;
        found = schedule[i].find(classDelete, 0);

        if (found < 0) 
        {
            cout << "Course not found.\n";
        } else {
            deleteSlot = i;
        }
    }

    for(int i=0;i<schedule.size() - 1;i++)
    {
        if (i < deleteSlot) 
        {
            newSchedule.push_back(schedule[i]);
        } else {
            newSchedule.push_back(schedule[i+1]);
        }
    }

    return newSchedule;    
}